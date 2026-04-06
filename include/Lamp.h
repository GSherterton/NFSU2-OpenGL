#pragma once
#include <GL/glut.h>

using namespace std;

class Lamp{
  public:
    Lamp();
    Lamp(GLfloat x, GLfloat y, GLfloat z);
    ~Lamp();

    GLfloat lampPosition[3];
    bool enabled = false;

    void setupLampLight();
    void drawLamp();
};