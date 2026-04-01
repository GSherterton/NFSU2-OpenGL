#pragma once

#include <GL/gl.h>

class Shelf {
  public:
    Shelf(GLfloat x, GLfloat y, GLfloat z, GLfloat width, GLfloat height, GLfloat depth);

    void draw();

  private:
    GLfloat m_x, m_y, m_z;
    GLfloat m_width, m_height, m_depth;

    void drawBox(GLfloat x0, GLfloat y0, GLfloat z0,
                 GLfloat x1, GLfloat y1, GLfloat z1);
    void drawUprights();
    void drawBoards();
    void drawBackPanel();
};
