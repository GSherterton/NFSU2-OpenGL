#pragma once
#include <GL/glut.h>

class Camera {
  public:
    GLdouble position[3]; // x, y, z
    GLdouble target[3];   // x, y, z

    Camera();
    Camera(const GLdouble x, const GLdouble y, const GLdouble z);
    ~Camera();

    void setPosition(const GLdouble x, const GLdouble y, const GLdouble z);
    void setTarget(const GLdouble x, const GLdouble y, const GLdouble z);

    void setLookAt();
};
