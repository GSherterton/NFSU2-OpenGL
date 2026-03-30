#pragma once

#include <GL/glut.h>
#include "Texture.h"

class Platform {
  public:
    GLfloat m_radius;
    GLfloat m_thickness;
    GLfloat m_rotation;

    Platform(GLfloat radius, GLfloat thickness);

    void draw();
    void addRotation(float delta);
    void loadTextures(const char* discPath, const char* sidePath);

  private:
    void drawDisc(GLfloat y);
    void drawSide();

    Texture* m_discTex;
    Texture* m_sideTex;
};
