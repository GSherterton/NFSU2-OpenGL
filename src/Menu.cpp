#include "Menu.h"

Menu::Menu() {
  this->window_width = 1280;
  this->window_height = 720;

  // Valores iniciais de teste simulando os status de um carro
  this->stat_acceleration = 0.8f; // 80% cheio
  this->stat_top_speed = 0.6f;    // 60% cheio
  this->stat_handling = 0.75f;    // 75% cheio
}

Menu::~Menu() {
}

void Menu::init() {
}

void Menu::drawStatBar(float x, float y, float width, float height, float fill_percentage) {
  // 1. Desenha o fundo da barra (cinza)
  glColor4ubv(bar_bg_color);
  glBegin(GL_QUADS);
    glVertex2f(x, y);
    glVertex2f(x + width, y);
    glVertex2f(x + width, y + height);
    glVertex2f(x, y + height);
  glEnd();

  // 2. Desenha o preenchimento da barra (verde) por cima
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

  // 1. Desenha o fundo preenchido
  glColor4ubv(panel_color); 
  glBegin(GL_QUADS);
    glVertex2f(margin, top_y);                             
    glVertex2f(window_width - margin, top_y);              
    glVertex2f(window_width - margin, bottom_y);             
    glVertex2f(margin, bottom_y);                            
  glEnd();

  // 2. Desenha a borda do painel
  glColor4ubv(border_color);
  glLineWidth(2.0f); // Deixa a linha mais grossa (o padrão é 1.0f)
  glBegin(GL_LINE_LOOP);
    glVertex2f(margin, top_y);                             
    glVertex2f(window_width - margin, top_y);              
    glVertex2f(window_width - margin, bottom_y);             
    glVertex2f(margin, bottom_y);                            
  glEnd();
  glLineWidth(1.0f); // Restaura a espessura normal para não bugar o resto do 3D
}

void Menu::drawBottomPanel() {
  float margin = 150.0f;
  float top_y = window_height - 120.0f;
  float bottom_y = window_height - 40.0f;

  // 1. Desenha o fundo preenchido
  glColor4ubv(panel_color); 
  glBegin(GL_QUADS);
    glVertex2f(margin, top_y);                             
    glVertex2f(window_width - margin, top_y);              
    glVertex2f(window_width - margin, bottom_y);             
    glVertex2f(margin, bottom_y);                            
  glEnd();

  // 2. Desenha a borda do painel
  glColor4ubv(border_color);
  glLineWidth(2.0f);
  glBegin(GL_LINE_LOOP);
    glVertex2f(margin, top_y);                             
    glVertex2f(window_width - margin, top_y);              
    glVertex2f(window_width - margin, bottom_y);             
    glVertex2f(margin, bottom_y);                            
  glEnd();
  glLineWidth(1.0f);

  
  float panel_width = (window_width - margin * 2);
  float bar_width = panel_width / 3.5f; 
  float spacing = (panel_width - (bar_width * 3)) / 2.0f; 
  
  float start_x = margin;
  float bar_y = top_y + 40.0f; 
  float bar_height = 8.0f;     

  drawStatBar(start_x, bar_y, bar_width, bar_height, stat_acceleration);
  drawStatBar(start_x + bar_width + spacing, bar_y, bar_width, bar_height, stat_top_speed);
  drawStatBar(start_x + (bar_width + spacing) * 2, bar_y, bar_width, bar_height, stat_handling);
}

void Menu::drawMenu(int width, int height) {
  this->window_width = width;
  this->window_height = height;

  glDisable(GL_DEPTH_TEST);
    
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

  glDisable(GL_BLEND); // Desliga para não afetar o 3D depois
  // ==========================================

  // Restaura a cor branca padrão com alpha em 100%
  glColor4f(1.0f, 1.0f, 1.0f, 1.0f); 

  glMatrixMode(GL_PROJECTION);
  glPopMatrix();

  glMatrixMode(GL_MODELVIEW);
  glPopMatrix();

  glEnable(GL_DEPTH_TEST);
}