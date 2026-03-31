#pragma once
#include <GL/glut.h>
#include <math.h>
#include "Wheel.h"
#include "Chassis.h"
#include "Door.h"
#include "RearBumper.h"
#include "FrontBumper.h"

using namespace std;

class Car{
  public:
    // wheels
    Wheel wheelBL = Wheel(0.5, 0.7); // back left wheel
    Wheel wheelBR = Wheel(0.5, 0.7); // back right wheel
    Wheel wheelFL = Wheel(0.5, 0.7); // front left wheel
    Wheel wheelFR = Wheel(0.5, 0.7); // front right wheel

    Chassis chassis;

    // doors
    Door doorL; // left door
    Door doorR; // right door

    RearBumper rear_bumper;
    FrontBumper front_bumper;

    Car();
    ~Car();

    void drawCar();
  
  private:
    void drawTheWheels();
    void drawChassis();
    void drawDoors();
    void drawBumpers();

    // parameters vars
    // left - right horizontal shifts
    GLfloat side_shift = 1.85; // the shift of the side of the car
    GLfloat wheel_side_shift = side_shift - 0.7/2; // the shift of the wheels from the center of the car

    // spec shifts
    GLfloat tire_radius = 0.7; // the radius of the tires
    GLfloat fender_shift = 0.1; // the shift of the fenders
    GLfloat new_radius = tire_radius + fender_shift; // the new radius of the rear bumper

    // back - front horizontal shifts
    // axles
    GLfloat back_axle_shift    = tire_radius + 2.1; // the shift of the rear axle  
    GLfloat front_axle_shift   = tire_radius + 2.1; // the shift of the front axle
    // doors
    GLfloat back_line_shift = tire_radius+fender_shift; // the back of the door shift from the center of the car
    // bumpers
    GLfloat rear_bumper_shift  = 1.0; // the shift of the rear bumper
    GLfloat front_bumper_shift = 1.0; // the shift of the front bumper
    GLfloat rear_bumper_begin_x = back_axle_shift + (tire_radius)/2; // the x coordinate of the beginning of the rear bumper
    GLfloat front_bumper_begin_x = front_axle_shift + (new_radius * cos(45.0*PI/180)); // the x coordinate of the beginning of the front bumper
    // windshield
    GLfloat windshield_shift   = 0.5; // the shift of the windshield
    
    // vertical up shifts
    GLfloat up_shift = 0.7;  // the shift of the radius of the tires
    GLfloat car_hood         = up_shift + tire_radius + 0.7;  // the height of the car hood
    GLfloat car_roof   = up_shift + tire_radius + 0.9 + 0.7;  // the height of the car roof
    // bumpers 
    GLfloat car_front_bumper = up_shift + tire_radius + 0.35; // the height of the car bumpers
    GLfloat car_rear_bumper  = up_shift + tire_radius + 0.9;  // the height of the car bumpers
    GLfloat rear_bumper_begin_y = up_shift + sqrt((3*(new_radius)*(new_radius))/4); // the y coordinate of the beginning of the rear bumper
    GLfloat front_bumper_begin_y = up_shift + (new_radius * sin(45.0*PI/180)); // the y coordinate of the beginning of the front bumper
    GLfloat bumper_elevation_shift = 0.1; // the elevation shift of the bumpers


    void setParameters();
};