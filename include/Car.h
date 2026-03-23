#pragma once
#include <GL/glut.h>
#include <math.h>
#include "Wheel.h"
#include "Chassis.h"

using namespace std;

class Car{
  public:
    // wheels
    Wheel wheelBL = Wheel(0.5, 0.7); // back left wheel
    Wheel wheelBR = Wheel(0.5, 0.7); // back right wheel
    Wheel wheelFL = Wheel(0.5, 0.7); // front left wheel
    Wheel wheelFR = Wheel(0.5, 0.7); // front right wheel

    Chassis chassis;

    Car();
    ~Car();

    void drawCar();
  
  private:
    void drawTheWheels();
    void drawChassis();
};