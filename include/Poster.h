#pragma once

#include <GL/gl.h>
#include "Texture.h"

class Poster {
  public:
    Poster(GLfloat x, GLfloat y, GLfloat z, GLfloat width, GLfloat height);
    ~Poster();
    void loadTexture(const char* texturePath);
    void draw();

  private:
    GLfloat m_x, m_y, m_z;
    GLfloat m_width, m_height;
    Texture* m_tex;
};
