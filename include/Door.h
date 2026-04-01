#pragma once
#include <GL/glut.h>
#include <vector>
#include <array>

#define RESOLUTION 30

using namespace std;

class Door {
  public:
    GLubyte car_color[3] = {0, 170, 0}; // car RGB color

    Door();
    ~Door();

    void drawDoor();

    // parameters vars
    // spec shifts
    GLfloat tire_radius = 0.7;  // the radius of the tires
    GLfloat fender_shift = 0.1; // the shift of the fenders

    // back - front horizontal shifts
    GLfloat back_line_shift = tire_radius + fender_shift; // the back of the door shift from the center of the car
    GLfloat front_axle_shift = tire_radius + 1.8;         // the shift of the front axle
    GLfloat windshield_shift = 0.5;                       // the shift of the windshield

    // vertical up shifts
    GLfloat up_shift = 0.7;                                // the shift of the radius of the tires
    GLfloat car_hood = up_shift + tire_radius + 0.7;       // the height of the car hood
    GLfloat car_roof = up_shift + tire_radius + 0.9 + 0.7; // the height of the car roof
};