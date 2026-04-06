#pragma once
#include <GL/glut.h>
#include <vector>
#include <array>
#include <math.h>

#define PI 3.14159265
#define RESOLUTION 30

using namespace std;

class Chassis{
  public:
    GLubyte car_lines_color[3]  = {0, 0, 0};      // car lines RGB color
    GLubyte car_color[3]  = {0, 0, 100};          // car RGB color
    GLubyte car_window_color[4]  = {20, 20, 50, 250}; // car window RGB color

    Chassis();
    ~Chassis();

    void drawChassis();

    // parameters vars
    // left - right horizontal shifts
    GLfloat side_shift = 1.85; // the shift of the side of the car

    // spec shifts
    GLfloat tire_radius = 0.7; // the radius of the tires
    GLfloat fender_shift = 0.1; // the shift of the fenders
    GLfloat new_radius = tire_radius + fender_shift; // the new radius of the rear bumper

    // back - front horizontal shifts
    //axles
    GLfloat back_axle_shift    = tire_radius + 2.1; // the shift of the rear axle
    GLfloat front_axle_shift   = tire_radius + 2.1; // the shift of the front axle
    //bumpers
    GLfloat rear_bumper_begin_x = back_axle_shift + (tire_radius)/2; // the x coordinate of the beginning of the rear bumper
    GLfloat rear_bumper_shift  = 1.0; // the shift of the rear bumper
    GLfloat front_bumper_begin_x = front_axle_shift + (new_radius * cos(45.0*PI/180)); // the x coordinate of the beginning of the front bumper
    GLfloat front_bumper_shift = 1.0; // the shift of the front bumper
    //windshield
    GLfloat windshield_shift   = 0.5; // the shift of the windshield
    //doors
    GLfloat back_line_shift = tire_radius+fender_shift; // the back of the door shift from the center of the car
    // lights
    GLfloat tailight_width = 0.6; // the width of the tailight
    GLfloat frontlight_width = 0.8; // the width of the frontlight
    GLfloat frontlight_arrow_width = 0.2; // the width of the arrow of the frontlight
    
    // vertical up shifts
    GLfloat up_shift = 0.7;  // the shift of the radius of the tires
    GLfloat car_hood = up_shift + tire_radius + 0.7;        // the height of the car hood
    GLfloat car_roof = up_shift + tire_radius + 0.9 + 0.7;  // the height of the car roof
    //bumpers
    GLfloat car_rear_bumper  = up_shift + tire_radius + 0.9;  // the height of the car bumpers
    GLfloat car_front_bumper = up_shift + tire_radius + 0.35; // the height of the car bumpers
    GLfloat rear_bumper_begin_y = up_shift + sqrt((3*(new_radius)*(new_radius))/4); // the y coordinate of the beginning of the rear bumper
    GLfloat front_bumper_begin_y = up_shift + (new_radius * sin(45.0*PI/180)); // the y coordinate of the beginning of the front bumper
    // lights
    GLfloat tailight_bot_y = rear_bumper_begin_y + 2*fender_shift; // the y coordinate of the bottom of the tailight
    GLfloat tailight_top_y = tailight_bot_y + 0.4; // the y coordinate of the top of the tailight (the bottom plus the height of the tailight)
    GLfloat tailight_divider = tailight_bot_y + 0.15;
};