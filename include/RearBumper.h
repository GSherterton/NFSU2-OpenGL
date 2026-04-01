#pragma once
#include <GL/glut.h>
#include <vector>
#include <array>
#include <math.h>

#define RESOLUTION 30
#define PI         3.14159265

using namespace std;

class RearBumper {
  public:
    GLubyte car_color[3] = {0, 170, 0}; // car RGB color

    RearBumper();
    ~RearBumper();

    void drawBumper();

    // parameters vars
    // left - right horizontal shifts
    GLfloat side_shift = 1.85; // the shift of the side of the car

    // spec shifts
    GLfloat tire_radius = 0.7;                       // the radius of the tires
    GLfloat fender_shift = 0.1;                      // the shift of the fenders
    GLfloat new_radius = tire_radius + fender_shift; // the new radius of the rear bumper

    // back - front horizontal shifts
    GLfloat back_axle_shift = tire_radius + 2.1;                       // the shift of the rear axle
    GLfloat rear_bumper_begin_x = back_axle_shift + (tire_radius) / 2; // the x coordinate of the beginning of the rear bumper
    GLfloat rear_bumper_shift = 1.0;                                   // the shift of the rear bumper

    // vertical up shifts
    GLfloat up_shift = 0.7;                                                               // the shift of the radius of the tires
    GLfloat rear_bumper_begin_y = up_shift + sqrt((3 * (new_radius) * (new_radius)) / 4); // the y coordinate of the beginning of the rear bumper
    GLfloat bumper_elevation_shift = 0.1;                                                 // the elevation shift of the bumpers
};