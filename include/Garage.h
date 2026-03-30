#pragma once

#include <GL/glut.h>
#include "Texture.h"

class Garage {
  public:
    const GLfloat m_width;
    const GLfloat m_depth;
    const GLfloat m_height;

    Garage(GLfloat width, GLfloat depth, GLfloat height)
        : m_width(width), m_depth(depth), m_height(height), m_wallTex(nullptr), m_floorTex(nullptr), m_ceilingTex(nullptr) {}

    void loadTextures(const char* wallPath, const char* floorPath, const char* ceilingPath);

    void draw();
  
  private:
    void drawFloor();
    void drawCeiling();
    void drawBackWall();
    void drawLeftWall();
    void drawRightWall();
    void drawPillars();

    Texture* m_wallTex;
    Texture* m_floorTex;
    Texture* m_ceilingTex;
};
