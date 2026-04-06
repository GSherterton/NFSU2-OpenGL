#pragma once
#include <GL/glut.h>
#include <string>
#include "Texture.h" // Incluindo a classe criada pelo seu time

using namespace std;

class Menu {
  public:
    int window_width;
    int window_height;

    // Atributos estáticos do Nissan 240SX
    string car_brand;
    string car_model;
    float car_acceleration;
    float car_top_speed;
    float car_handling;

    // Usando a classe Texture do projeto em vez do ID manual
    Texture* logo_texture;

    // Cores no padrão RGBA (Red, Green, Blue, Alpha) de 0-255
    GLubyte panel_color[4]    = {20, 20, 20, 160};      // Fundo dos painéis
    GLubyte border_color[4]   = {100, 100, 100, 180};   // Borda clara semitransparente
    GLubyte bar_bg_color[4]   = {80, 80, 80, 255};      // Fundo cinza da barrinha 
    GLubyte bar_fill_color[4] = {150, 255, 100, 255};   // Verde neon
    GLubyte text_color[4]     = {255, 255, 255, 255};   // Branco para os textos

    Menu();
    ~Menu();

    void init();
    void drawMenu(int width, int height);

  private:
    void drawTopPanel();
    void drawBottomPanel();
    void drawStatBar(float x, float y, float width, float height, float fill_percentage);
    void drawText(string text, float x, float y, void* font);

    void drawStrokeText(string text, float x, float y, float scale, float line_width);
};