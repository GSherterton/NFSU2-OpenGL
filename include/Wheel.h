#pragma once
#include <GL/glut.h>

using namespace std;

class Wheel {
  public:
    float radius;         // wheel radius
    float width;          // wheel width (thickness)
    float rotation_angle; // wheel rotation angle

    GLubyte rim_color[3] = {170, 170, 170}; // rim RGB color
    GLubyte tire_color[3] = {30, 30, 30};   // tire RGB color

    GLUquadric* quad = gluNewQuadric();

    Wheel(float radius, float width);
    ~Wheel();

    void drawWheel();
    void rotate(float angle);

  private:
    void drawRim();
    void drawTire();
};