#pragma once
#include <GL/glut.h>
#include <string>
#include <vector>
#include <array>
#include "Texture.h" 

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

    // Variáveis para a paleta de cores
    vector<array<GLubyte, 3>> available_colors;
    int selected_color_index;

    Texture* logo_texture;

    // Cores no padrão RGBA
    GLubyte panel_color[4]    = {20, 20, 20, 160};      
    GLubyte border_color[4]   = {100, 100, 100, 180};   
    GLubyte bar_bg_color[4]   = {80, 80, 80, 255};      
    GLubyte bar_fill_color[4] = {150, 255, 100, 255};   
    GLubyte text_color[4]     = {255, 255, 255, 255};   

    Menu();
    ~Menu();

    void init();
    void setAvailableColors(const vector<array<GLubyte, 3>>& colors);
    void drawMenu(int width, int height);

  private:
    void drawTopPanel();
    void drawBottomPanel();
    void drawColorPalette(float x, float y); 
    void drawStatBar(float x, float y, float width, float height, float fill_percentage);
    void drawText(string text, float x, float y, void* font);
    void drawStrokeText(string text, float x, float y, float scale, float line_width);
};