#include "Menu.h"
#include <math.h>

using namespace std;

Menu::Menu() {
  this->window_width = 1280;
  this->window_height = 720;

  this->car_brand = "NISSAN";
  this->car_model = "240SX";
  this->car_acceleration = 0.6f;
  this->car_top_speed = 0.7f;
  this->car_handling = 0.8f;

  this->selected_color_index = 0; 
  this->logo_texture = nullptr; 
}

Menu::~Menu() {
  if (logo_texture != nullptr) {
    delete logo_texture;
  }
}

void Menu::init() {
  logo_texture = new Texture("textures/logo_nissan.png");
}

void Menu::setAvailableColors(const vector<array<GLubyte, 3>>& colors) {
  this->available_colors = colors;
}

void Menu::drawText(string text, float x, float y, void* font) {
  glColor4ubv(text_color);
  glRasterPos2f(x, y);
  for (char c : text) {
    glutBitmapCharacter(font, c);
  }
}

void Menu::drawStrokeText(string text, float x, float y, float scale, float line_width) {
  glColor4ubv(text_color);
  glPushMatrix();
  
  glTranslatef(x, y, 0.0f);
  glScalef(scale, -scale, 1.0f); 
  
  glLineWidth(line_width);
  
  for (char c : text) {
    glutStrokeCharacter(GLUT_STROKE_ROMAN, c);
  }
  
  glLineWidth(1.0f); 
  glPopMatrix();
}

void Menu::drawStatBar(float x, float y, float width, float height, float fill_percentage) {
  glColor4ubv(bar_bg_color);
  glBegin(GL_QUADS);
    glVertex2f(x, y);
    glVertex2f(x + width, y);
    glVertex2f(x + width, y + height);
    glVertex2f(x, y + height);
  glEnd();

  float fill_width = width * fill_percentage;
  glColor4ubv(bar_fill_color);
  glBegin(GL_QUADS);
    glVertex2f(x, y);
    glVertex2f(x + fill_width, y);
    glVertex2f(x + fill_width, y + height);
    glVertex2f(x, y + height);
  glEnd();
}

void Menu::drawColorPalette(float start_x, float y) {
  if (available_colors.empty()) return;

  float radius = 10.0f; 
  float spacing = 35.0f; 

  for (size_t i = 0; i < available_colors.size(); i++) {
    float cx = start_x + (i * spacing);
    float cy = y;

    // Desenha anel de seleção branco se for a cor atual
    if (i == selected_color_index) {
        glColor4ub(255, 255, 255, 220);
        glBegin(GL_POLYGON);
        for(int j = 0; j < 360; j++) {
            float theta = j * 3.14159f / 180.0f;
            glVertex2f(cx + (radius + 2.5f) * cos(theta), cy + (radius + 2.5f) * sin(theta));
        }
        glEnd();
    }

    // Pega a cor RGB do vetor passado pelo main
    auto color = available_colors[i];
    glColor4ub(color[0], color[1], color[2], 255);

    // Desenha a bolinha
    glBegin(GL_POLYGON);
    for(int j = 0; j < 360; j++) {
        float theta = j * 3.14159f / 180.0f;
        glVertex2f(cx + radius * cos(theta), cy + radius * sin(theta));
    }
    glEnd();
  }
}

void Menu::drawTopPanel() {
  float margin = 150.0f;
  float top_y = 50.0f;
  float bottom_y = 180.0f;
  float panel_height = bottom_y - top_y;

  // Fundo e borda do painel
  glColor4ubv(panel_color); 
  glBegin(GL_QUADS);
    glVertex2f(margin, top_y);                             
    glVertex2f(window_width - margin, top_y);              
    glVertex2f(window_width - margin, bottom_y);             
    glVertex2f(margin, bottom_y);                            
  glEnd();

  glColor4ubv(border_color);
  glLineWidth(2.0f);
  glBegin(GL_LINE_LOOP);
    glVertex2f(margin, top_y);                             
    glVertex2f(window_width - margin, top_y);              
    glVertex2f(window_width - margin, bottom_y);             
    glVertex2f(margin, bottom_y);                            
  glEnd();
  glLineWidth(1.0f);

  // === LADO ESQUERDO: LOGO E NOME DO CARRO ===
  float aspect_ratio = 3840.0f / 2160.0f; 
  float logo_height = 75.0f;
  float logo_width = logo_height * aspect_ratio; 

  float box_height = logo_height + 20.0f; 
  float box_width = logo_width + 20.0f; 

  float box_x = margin + 30.0f; 
  float box_y = top_y + (panel_height - box_height) / 2.0f; 
  
  glColor4ub(30, 30, 30, 255); 
  glBegin(GL_QUADS);
    glVertex2f(box_x, box_y);
    glVertex2f(box_x + box_width, box_y);
    glVertex2f(box_x + box_width, box_y + box_height);
    glVertex2f(box_x, box_y + box_height);
  glEnd();

  glColor4ub(100, 100, 100, 200);
  glBegin(GL_LINE_LOOP);
    glVertex2f(box_x, box_y);
    glVertex2f(box_x + box_width, box_y);
    glVertex2f(box_x + box_width, box_y + box_height);
    glVertex2f(box_x, box_y + box_height);
  glEnd();

  if (logo_texture != nullptr && logo_texture->m_id != 0) {
    glEnable(GL_TEXTURE_2D);
    logo_texture->bind(); 
    
    float logo_x = box_x + 10.0f;
    float logo_y = box_y + 10.0f; 

    glColor4f(1.0f, 1.0f, 1.0f, 1.0f); 

    glBegin(GL_QUADS);
      glTexCoord2f(0.0f, 1.0f); glVertex2f(logo_x, logo_y); 
      glTexCoord2f(1.0f, 1.0f); glVertex2f(logo_x + logo_width, logo_y); 
      glTexCoord2f(1.0f, 0.0f); glVertex2f(logo_x + logo_width, logo_y + logo_height); 
      glTexCoord2f(0.0f, 0.0f); glVertex2f(logo_x, logo_y + logo_height); 
    glEnd();
    
    logo_texture->unbind(); 
    glDisable(GL_TEXTURE_2D);
  }

  float text_x = box_x + box_width + 30.0f; 
  drawStrokeText(car_brand, text_x, top_y + 65.0f, 0.32f, 3.0f);
  drawStrokeText(car_model, text_x, top_y + 105.0f, 0.25f, 2.0f);

  // === LADO DIREITO: COMANDOS ===
  float right_x = (window_width - margin) - 250.0f; 
  void* font_title = GLUT_BITMAP_HELVETICA_18;
  void* font_cmd = GLUT_BITMAP_HELVETICA_12;

  drawText("COMMANDS", right_x, top_y + 45.0f, font_title);
  drawText("[ P ] - CHANGE COLOR", right_x, top_y + 80.0f, font_cmd);
  drawText("[ L ] - ENABLE/DISABLE LAMP", right_x, top_y + 105.0f, font_cmd);

  // === CENTRO/DIREITA: PALETA DE CORES ===
  // Calcula o tamanho total das bolinhas para posicionar antes dos comandos
  float spacing = 35.0f;
  float total_palette_width = (available_colors.size() > 0) ? (available_colors.size() - 1) * spacing : 0;
  
  // Afasta 80px para a esquerda do bloco de comandos
  float palette_start_x = right_x - total_palette_width - 80.0f; 
  
  drawText("COLORS", palette_start_x, top_y + 45.0f, font_title);
  // Posiciona as bolinhas alinhadas na mesma altura do primeiro comando "[ P ]"
  drawColorPalette(palette_start_x + 10.0f, top_y + 76.0f); 
}

void Menu::drawBottomPanel() {
  float margin = 150.0f;
  float top_y = window_height - 140.0f; 
  float bottom_y = window_height - 40.0f;

  glColor4ubv(panel_color); 
  glBegin(GL_QUADS);
    glVertex2f(margin, top_y);                             
    glVertex2f(window_width - margin, top_y);              
    glVertex2f(window_width - margin, bottom_y);             
    glVertex2f(margin, bottom_y);                            
  glEnd();

  glColor4ubv(border_color);
  glLineWidth(2.0f);
  glBegin(GL_LINE_LOOP);
    glVertex2f(margin, top_y);                             
    glVertex2f(window_width - margin, top_y);              
    glVertex2f(window_width - margin, bottom_y);             
    glVertex2f(margin, bottom_y);                            
  glEnd();
  glLineWidth(1.0f);

  // Título limpo e centralizado
  float title_width = 150.0f; 
  drawText("Performance Stats", (window_width / 2.0f) - (title_width / 2.0f), top_y + 25.0f, GLUT_BITMAP_HELVETICA_18);

  // === BARRAS DE PERFORMANCE ===
  float panel_width = (window_width - margin * 2);
  float padding_externo = 40.0f; 
  float padding_entre_barras = 40.0f; 
  
  float bar_width = (panel_width - padding_externo - (padding_entre_barras * 2)) / 3.0f; 
  
  float start_x = margin + 20.0f;
  float bar_y = top_y + 70.0f; // Barras subiram de volta, preenchendo o painel
  float bar_height = 10.0f; 
  float text_y = bar_y - 12.0f; 
  
  void* font = GLUT_BITMAP_HELVETICA_12; 

  drawText("Acceleration", start_x, text_y, font);
  drawStatBar(start_x, bar_y, bar_width, bar_height, car_acceleration);

  float speed_x = start_x + bar_width + padding_entre_barras;
  drawText("Top Speed", speed_x, text_y, font);
  drawStatBar(speed_x, bar_y, bar_width, bar_height, car_top_speed);

  float handling_x = speed_x + bar_width + padding_entre_barras;
  drawText("Handling", handling_x, text_y, font);
  drawStatBar(handling_x, bar_y, bar_width, bar_height, car_handling);
}

void Menu::drawMenu(int width, int height) {
  this->window_width = width;
  this->window_height = height;

  glPushAttrib(GL_ENABLE_BIT);
  glDisable(GL_DEPTH_TEST);
  glDisable(GL_LIGHTING); 
    
  glMatrixMode(GL_PROJECTION);
  glPushMatrix();
  glLoadIdentity();
  gluOrtho2D(0.0, window_width, window_height, 0.0);

  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();
  glLoadIdentity();

  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  drawTopPanel();
  drawBottomPanel();

  glDisable(GL_BLEND); 
  glColor4f(1.0f, 1.0f, 1.0f, 1.0f); 

  glMatrixMode(GL_PROJECTION);
  glPopMatrix();

  glMatrixMode(GL_MODELVIEW);
  glPopMatrix();

  glPopAttrib();
}