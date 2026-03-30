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

    // parameters vars
    // left - right horizontal shifts
    GLfloat side_shift = 1.5 + 0.7/2; // the shift of the side of the car

    // spec shifts
    GLfloat tire_radius = 0.7; // the radius of the tires
    GLfloat fender_shift = 0.1; // the shift of the fenders

    // back - front horizontal shifts
    GLfloat back_axle_shift    = tire_radius + 2.1; // the shift of the rear axle  
    GLfloat front_axle_shift   = tire_radius + 2.1; // the shift of the front axle
    GLfloat rear_bumper_shift  = 1.0; // the shift of the rear bumper
    GLfloat front_bumper_shift = 1.0; // the shift of the front bumper
    GLfloat windshield_shift   = 0.5; // the shift of the windshield
    
    // vertical up shifts
    GLfloat up_shift = 0.7;  // the shift of the radius of the tires
    GLfloat car_hood         = up_shift + tire_radius + 0.7;  // the height of the car hood
    GLfloat car_front_bumper = up_shift + tire_radius + 0.35; // the height of the car bumpers
    GLfloat car_rear_bumper  = up_shift + tire_radius + 0.9;  // the height of the car bumpers
    GLfloat car_roof   = up_shift + tire_radius + 0.9 + 0.7;  // the height of the car roof
    GLfloat bumper_elevation_shift = 0.1; // the elevation shift of the bumpers
};