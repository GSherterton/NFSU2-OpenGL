#pragma once
#include <GL/glut.h>
#include <vector>
#include <array>
#include <math.h>

#define PI 3.14159265
#define RESOLUTION 30

using namespace std;

class FrontBumper{
  public:
    GLubyte car_lines_color[3]  = {0, 0, 0};  // car lines RGB color
    GLubyte car_color[3]  = {0, 0, 100};      // car RGB color

    FrontBumper();
    ~FrontBumper();

    void drawBumper();

    // parameters vars
    // left - right horizontal shifts
    GLfloat side_shift = 1.85; // the shift of the side of the car
    
    // spec shifts
    GLfloat tire_radius = 0.7; // the radius of the tires
    GLfloat fender_shift = 0.1; // the shift of the fenders
    GLfloat new_radius = tire_radius + fender_shift; // the new radius of the front bumper

    // back - front horizontal shifts
    GLfloat front_axle_shift = tire_radius + 2.1; // the shift of the front axle
    GLfloat front_bumper_begin_x = front_axle_shift + (new_radius * cos(45.0*PI/180)); // the x coordinate of the beginning of the front bumper
    GLfloat front_bumper_shift = 1.0; // the shift of the front bumper
    
    // vertical up shifts
    GLfloat up_shift = 0.7;  // the shift of the radius of the tires
    GLfloat front_bumper_begin_y = up_shift + (new_radius * sin(45.0*PI/180)); // the y coordinate of the beginning of the front bumper
};