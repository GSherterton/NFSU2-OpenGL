#pragma once

#include <GL/glut.h>

class Platform {
  public:
    GLfloat m_radius;
    GLfloat m_thickness;
    GLfloat m_rotation;

    Platform(GLfloat radius, GLfloat thickness);

    void draw();
    void addRotation(float delta);

  private:
    void drawDisc(GLfloat y);
    void drawSide();
};
