#include "Menu.h"

using namespace std;

Menu::Menu() {
  this->window_width = 1280;
  this->window_height = 720;

  this->car_brand = "NISSAN";
  this->car_model = "240SX";
  this->car_acceleration = 0.6f;
  this->car_top_speed = 0.7f;
  this->car_handling = 0.8f;

  this->logo_texture = nullptr; 
}

Menu::~Menu() {
  if (logo_texture != nullptr) {
    delete logo_texture;
  }
}

void Menu::init() {
  // Lembre-se de verificar se o nome do arquivo PNG está exato aqui
  logo_texture = new Texture("textures/logo_nissan.png");
}

void Menu::drawText(string text, float x, float y, void* font) {
  glColor4ubv(text_color);
  glRasterPos2f(x, y);
  for (char c : text) {
    glutBitmapCharacter(font, c);
  }
}

// === FUNÇÃO DE TEXTO VETORIAL ===
void Menu::drawStrokeText(string text, float x, float y, float scale, float line_width) {
  glColor4ubv(text_color);
  glPushMatrix();
  
  glTranslatef(x, y, 0.0f);
  // Escala invertida no Y para o texto não ficar de ponta-cabeça no Ortho2D
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

void Menu::drawTopPanel() {
  float margin = 150.0f;
  float top_y = 50.0f;
  float bottom_y = 180.0f;
  float panel_height = bottom_y - top_y;

  // === FUNDO E BORDA DO PAINEL PRINCIPAL ===
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

  // === CÁLCULO DE PROPORÇÃO DA LOGO (3840x2160) ===
  float aspect_ratio = 3840.0f / 2160.0f; // 16:9

  // 1. AUMENTAMOS A LOGO (Passou de 60.0f para 75.0f)
  float logo_height = 75.0f;
  float logo_width = logo_height * aspect_ratio; 

  float box_height = logo_height + 20.0f; 
  float box_width = logo_width + 20.0f; 

  // === DESENHANDO A CAIXA ESCURA ===
  float center_x = window_width / 2.0f;
  float box_x = center_x - 180.0f; 
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

  // === DESENHANDO A LOGO DENTRO DA CAIXA ===
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

  // === DESENHANDO OS NOMES DO CARRO ===
  float text_x = box_x + box_width + 30.0f; 
  
  // 2. DIMINUÍMOS O "NISSAN" (Escala de 0.4f para 0.32f e desceu um pouquinho no eixo Y)
  drawStrokeText(car_brand, text_x, top_y + 65.0f, 0.32f, 3.0f);
  
  // 3. AUMENTAMOS O "240SX" (Escala de 0.2f para 0.25f, subiu um pouco no eixo Y e a linha ficou um tiquinho mais grossa)
  drawStrokeText(car_model, text_x, top_y + 105.0f, 0.25f, 2.0f);
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

  drawText("Performance Stats", margin + 20.0f, top_y + 25.0f, GLUT_BITMAP_HELVETICA_18);

  float panel_width = (window_width - margin * 2);
  float padding_externo = 40.0f; 
  float padding_entre_barras = 40.0f; 
  
  float bar_width = (panel_width - padding_externo - (padding_entre_barras * 2)) / 3.0f; 
  
  float start_x = margin + 20.0f;
  float bar_y = top_y + 70.0f; 
  float bar_height = 10.0f; 
  float text_y = bar_y - 12.0f; 
  
  void* font = GLUT_BITMAP_HELVETICA_12; 

  // === BARRAS SEM PORCENTAGENS ===
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

  glDisable(GL_DEPTH_TEST);
    
  glMatrixMode(GL_PROJECTION);
  glPushMatrix();
  glLoadIdentity();
  // Configura a tela 2D com origem no topo-esquerdo (0, 0)
  gluOrtho2D(0.0, window_width, window_height, 0.0);

  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();
  glLoadIdentity();

  // Liga a transparência para os painéis e o PNG
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

  glEnable(GL_DEPTH_TEST);
}