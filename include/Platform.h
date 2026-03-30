#pragma once

#include <GL/glut.h>
#include "Texture.h"

class Platform {
  public:
    Platform(GLfloat radius, GLfloat thickness);

    void loadTextures(const char* discPath, const char* sidePath);
    void draw();
    void addRotation(float delta);

  private:
    GLfloat m_radius, m_thickness, m_rotation;

    void drawDisc(GLfloat y);
    void drawSide();

    Texture* m_discTex;
    Texture* m_sideTex;
};
