#pragma once
#include <GL/glut.h>
#include <vector>
#include <array>

#define RESOLUTION 30

using namespace std;

class Chassis{
  public:
    GLubyte car_color[3]  = {170, 0, 0};  // car RGB color

    Chassis();
    ~Chassis();

    void drawChassis();
};