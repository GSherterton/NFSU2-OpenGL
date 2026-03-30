#include "Car.h"

void Car::setParameters(){
  { // set chassis vars
    // left - right horizontal shifts
    chassis.side_shift = side_shift; // the shift of the side of the car

    // spec shifts
    chassis.tire_radius = tire_radius; // the radius of the tires
    chassis.fender_shift = fender_shift; // the shift of the fenders

    // back - front horizontal shifts
    chassis.back_axle_shift    = back_axle_shift; // the shift of the rear axle  
    chassis.front_axle_shift   = front_axle_shift; // the shift of the front axle
    chassis.rear_bumper_shift  = rear_bumper_shift; // the shift of the rear bumper
    chassis.front_bumper_shift = front_bumper_shift; // the shift of the front bumper
    chassis.windshield_shift   = windshield_shift; // the shift of the windshield
    
    // vertical up shifts
    chassis.up_shift = up_shift;  // the shift of the radius of the tires
    chassis.car_hood         = car_hood;  // the height of the car hood
    chassis.car_front_bumper = car_front_bumper; // the height of the car bumpers
    chassis.car_rear_bumper  = car_rear_bumper;  // the height of the car bumpers
    chassis.car_roof   = car_roof;  // the height of the car roof
    chassis.bumper_elevation_shift = bumper_elevation_shift; // the elevation shift of the bumpers
  }

  { // set doors vars
    { // left door
      // spec shifts
      doorL.tire_radius = tire_radius; // the radius of the tires
      doorL.fender_shift = fender_shift; // the shift of the fenders

      // back - front horizontal shifts
      doorL.back_line_shift = back_line_shift; // the back of the door shift from the center of the car
      doorL.front_axle_shift = front_axle_shift; // the shift of the front axle
      doorL.windshield_shift = windshield_shift; // the shift of the windshield
      
      // vertical up shifts
      doorL.up_shift = up_shift;  // the shift of the radius of the tires
      doorL.car_hood = car_hood; // the height of the car hood
      doorL.car_roof = car_roof; // the height of the car roof
    }

    { // right door
      // spec shifts
      doorR.tire_radius = tire_radius; // the radius of the tires
      doorR.fender_shift = fender_shift; // the shift of the fenders

      // back - front horizontal shifts
      doorR.back_line_shift = back_line_shift; // the back of the door shift from the center of the car
      doorR.front_axle_shift = front_axle_shift; // the shift of the front axle
      doorR.windshield_shift = windshield_shift; // the shift of the windshield
      
      // vertical up shifts
      doorR.up_shift = up_shift;  // the shift of the radius of the tires
      doorR.car_hood = car_hood; // the height of the car hood
      doorR.car_roof = car_roof; // the height of the car roof
    }
  }

  { // set bumpers vars
    { // rear bumper
      rear_bumper.side_shift = side_shift; // the shift of the side of the car
    
      // spec shifts
      rear_bumper.tire_radius = tire_radius; // the radius of the tires
      rear_bumper.fender_shift = fender_shift; // the shift of the fenders
      rear_bumper.new_radius = new_radius; // the new radius of the rear bumper

      // back - front horizontal shifts
      rear_bumper.back_axle_shift = back_axle_shift; // the shift of the rear axle
      rear_bumper.rear_bumper_begin_x = rear_bumper_begin_x; // the x coordinate of the beginning of the rear bumper
      rear_bumper.rear_bumper_shift = rear_bumper_shift; // the shift of the rear bumper
      
      // vertical up shifts
      rear_bumper.up_shift = up_shift;  // the shift of the radius of the tires
      rear_bumper.rear_bumper_begin_y = rear_bumper_begin_y; // the y coordinate of the beginning of the rear bumper
      rear_bumper.bumper_elevation_shift = bumper_elevation_shift; // the elevation shift of the bumpers
    }

    { // front bumper
      // left - right horizontal shifts
      front_bumper.side_shift = side_shift; // the shift of the side of the car
      
      // spec shifts
      front_bumper.tire_radius = tire_radius; // the radius of the tires
      front_bumper.fender_shift = fender_shift; // the shift of the fenders
      front_bumper.new_radius = new_radius; // the new radius of the front bumper

      // back - front horizontal shifts
      front_bumper.front_axle_shift = front_axle_shift; // the shift of the front axle
      front_bumper.front_bumper_begin_x = front_bumper_begin_x; // the x coordinate of the beginning of the front bumper
      front_bumper.front_bumper_shift = front_bumper_shift; // the shift of the front bumper
      
      // vertical up shifts
      front_bumper.up_shift = up_shift;  // the shift of the radius of the tires
      front_bumper.front_bumper_begin_y = front_bumper_begin_y; // the y coordinate of the beginning of the front bumper
    }
  }
}

Car::Car(){
  setParameters();
}

Car::~Car(){}

void Car::drawTheWheels(){
  // back left wheel
  {
    glPushMatrix();
    glTranslated(-back_axle_shift, 0.0, wheel_side_shift); // translate to the back left
    wheelBL.drawWheel();
    glPopMatrix();
  }

  // back right wheel
  {
    glPushMatrix();
    glTranslated(-back_axle_shift, 0.0, -wheel_side_shift); // translate to the back right
    wheelBR.drawWheel();
    glPopMatrix();
  }

  // front left wheel
  {
    glPushMatrix();
    glTranslated(front_axle_shift, 0.0, wheel_side_shift); // translate to the front left
    wheelFL.drawWheel();
    glPopMatrix();
  }

  // front right wheel
  {
    glPushMatrix();
    glTranslated(front_axle_shift, 0.0, -wheel_side_shift); // translate to the front right
    wheelFR.drawWheel();
    glPopMatrix();
  }
}

void Car::drawChassis(){
  chassis.drawChassis();
}

void Car::drawDoors(){
  { // leftDoor
    glPushMatrix();
    glTranslated(0.0, 0.0, -side_shift); // translate to the left
    doorL.drawDoor();
    glPopMatrix();
  }

  { // rightDoor
    glPushMatrix();
    glTranslated(0.0, 0.0, side_shift); // translate to the right
    doorR.drawDoor();
    glPopMatrix();
  }  
}

void Car::drawBumpers(){
  rear_bumper.drawBumper();
  front_bumper.drawBumper();
}

void Car::drawCar() {
  glPushMatrix(); // put everything that will be drawed into a new transf matrix

  // based on the center point of the car
  drawTheWheels();
  drawChassis();
  drawDoors();
  drawBumpers();
}