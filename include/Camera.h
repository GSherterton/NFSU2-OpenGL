#pragma once
#include <GL/glut.h>

using namespace std;

class Camera{
  public:
    GLdouble posicao[3]; // x, y, z
    GLdouble direcao[3]; // x, y, z

    Camera();
    Camera(const GLdouble x, const GLdouble y, const GLdouble z);
    ~Camera();

    void setPosicao(const GLdouble x, const GLdouble y, const GLdouble z);
    void setDirecao(const GLdouble x, const GLdouble y, const GLdouble z);

    void setLookAt();
};