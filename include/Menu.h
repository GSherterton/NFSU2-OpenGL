#pragma once
#include <GL/glut.h>

using namespace std;

class Menu {
  public:
    int window_width;
    int window_height;

    // Atributos do carro atual (valores de 0.0 a 1.0)
    float stat_acceleration;
    float stat_top_speed;
    float stat_handling;

    // Cores no padrão RGBA (Red, Green, Blue, Alpha) de 0-255
    GLubyte panel_color[4]    = {20, 20, 20, 200};      // Fundo dos painéis
    GLubyte border_color[4]   = {100, 100, 100, 180};   // Borda clara semitransparente
    GLubyte bar_bg_color[4]   = {80, 80, 80, 255};      // Fundo cinza da barrinha 
    GLubyte bar_fill_color[4] = {150, 255, 100, 255};   // Verde neon

    Menu();
    ~Menu();

    void init();
    void drawMenu(int width, int height);

  private:
    void drawTopPanel();
    void drawBottomPanel();
    // Função auxiliar para desenhar uma barra de progresso dinâmica
    void drawStatBar(float x, float y, float width, float height, float fill_percentage);
};