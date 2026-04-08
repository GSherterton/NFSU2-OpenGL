#include "Car.h"

void Car::setParameters(){
  { // set chassis vars
    // colors
    { // car lines color
      chassis.car_lines_color[0] =  car_lines_color[0]; // car lines RGB color
      chassis.car_lines_color[1] =  car_lines_color[1]; // car lines RGB color
      chassis.car_lines_color[2] =  car_lines_color[2]; // car lines RGB color
    }

    { // car color
      chassis.car_color[0] = car_color[0];  // car RGB color
      chassis.car_color[1] = car_color[1];  // car RGB color
      chassis.car_color[2] = car_color[2];  // car RGB color
    }

    { // car window color
      chassis.car_window_color[0] = car_window_color[0]; // car window RGB color
      chassis.car_window_color[1] = car_window_color[1]; // car window RGB color
      chassis.car_window_color[2] = car_window_color[2]; // car window RGB color
      chassis.car_window_color[3] = car_window_color[3]; // car window RGB color
    }

    // left - right horizontal shifts
    chassis.side_shift = side_shift; // the shift of the side of the car

    // spec shifts
    chassis.tire_radius  = tire_radius;  // the radius of the tires
    chassis.fender_shift = fender_shift; // the shift of the fenders
    chassis.new_radius   = new_radius;   // the new radius of the rear bumper

    // back - front horizontal shifts
    //axles
    chassis.back_axle_shift  = back_axle_shift;  // the shift of the rear axle  
    chassis.front_axle_shift = front_axle_shift; // the shift of the front axle
    //bumpers
    chassis.rear_bumper_shift    = rear_bumper_shift;    // the shift of the rear bumper
    chassis.front_bumper_shift   = front_bumper_shift;   // the shift of the front bumper
    chassis.rear_bumper_begin_x  = rear_bumper_begin_x;  // the x coordinate of the beginning of the rear bumper
    chassis.front_bumper_begin_x = front_bumper_begin_x; // the x coordinate of the beginning of the front bumper
    //windshield
    chassis.windshield_shift   = windshield_shift; // the shift of the windshield
    //doors
    chassis.back_line_shift = back_line_shift; // the back of the door shift from the center of the car
    // lights
    chassis.tailight_width = tailight_width; // the width of the tailight
    chassis.frontlight_width = frontlight_width; // the width of the frontlight
    chassis.frontlight_arrow_width = frontlight_arrow_width; // the width of the arrow of the frontlight

    // vertical up shifts
    chassis.up_shift = up_shift; // the shift of the radius of the tires
    chassis.car_hood = car_hood; // the height of the car hood
    chassis.car_roof = car_roof; // the height of the car roof
    //bumpers
    chassis.car_rear_bumper  = car_rear_bumper;  // the height of the car bumpers
    chassis.car_front_bumper = car_front_bumper; // the height of the car bumpers
    chassis.rear_bumper_begin_y = rear_bumper_begin_y; // the y coordinate of the beginning of the rear bumper
    chassis.front_bumper_begin_y = front_bumper_begin_y; // the y coordinate of the beginning of the front bumper
    // lights
    chassis.tailight_bot_y = tailight_bot_y; // the y coordinate of the bottom of the tailight
    chassis.tailight_top_y = tailight_top_y; // the y coordinate of the top of the tailight (the bottom plus the height of the tailight)
    chassis.tailight_divider = tailight_divider;
  }

  { // set doors vars
    { // left door
      // colors
      { // car lines color
        doorL.car_lines_color[0] =  car_lines_color[0]; // car lines RGB color
        doorL.car_lines_color[1] =  car_lines_color[1]; // car lines RGB color
        doorL.car_lines_color[2] =  car_lines_color[2]; // car lines RGB color 
      }

      { // car color
        doorL.car_color[0] = car_color[0];  // car RGB color
        doorL.car_color[1] = car_color[1];  // car RGB color
        doorL.car_color[2] = car_color[2];  // car RGB color
      }

      { // car window color
        doorL.car_window_color[0] = car_window_color[0]; // car window RGB color
        doorL.car_window_color[1] = car_window_color[1]; // car window RGB color
        doorL.car_window_color[2] = car_window_color[2]; // car window RGB color
        doorL.car_window_color[3] = car_window_color[3]; // car window RGB color
      }

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
      // colors
      { // car lines color
        doorR.car_lines_color[0] =  car_lines_color[0]; // car lines RGB color
        doorR.car_lines_color[1] =  car_lines_color[1]; // car lines RGB color
        doorR.car_lines_color[2] =  car_lines_color[2]; // car lines RGB color
      }

      { // car color
        doorR.car_color[0] = car_color[0];  // car RGB color
        doorR.car_color[1] = car_color[1];  // car RGB color
        doorR.car_color[2] = car_color[2];  // car RGB color
      }

      { // car window color
        doorR.car_window_color[0] = car_window_color[0]; // car window RGB color
        doorR.car_window_color[1] = car_window_color[1]; // car window RGB color
        doorR.car_window_color[2] = car_window_color[2]; // car window RGB color
        doorR.car_window_color[3] = car_window_color[3]; // car window RGB color
      }

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
      // colors
      { // car lines color
        rear_bumper.car_lines_color[0] =  car_lines_color[0]; // car lines RGB color
        rear_bumper.car_lines_color[1] =  car_lines_color[1]; // car lines RGB color
        rear_bumper.car_lines_color[2] =  car_lines_color[2]; // car lines RGB color
      }

      { // car color
        rear_bumper.car_color[0] = car_color[0];  // car RGB color
        rear_bumper.car_color[1] = car_color[1];  // car RGB color
        rear_bumper.car_color[2] = car_color[2];  // car RGB color
      }

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
      // colors
      { // car lines color
        front_bumper.car_lines_color[0] =  car_lines_color[0]; // car lines RGB color
        front_bumper.car_lines_color[1] =  car_lines_color[1]; // car lines RGB color
        front_bumper.car_lines_color[2] =  car_lines_color[2]; // car lines RGB color
      }

      { // car color
        front_bumper.car_color[0] = car_color[0];  // car RGB color
        front_bumper.car_color[1] = car_color[1];  // car RGB color
        front_bumper.car_color[2] = car_color[2];  // car RGB color
      }

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
    glTranslated(-back_axle_shift, 0.0, -wheel_side_shift); // translate to the back left
    wheelBL.drawWheel();
    glPopMatrix();
  }

  // back right wheel
  {
    glPushMatrix();
    glRotatef(180, 0, 1, 0); // rotate the wheel to the opposite direction
    glTranslated(-back_axle_shift, 0.0, -wheel_side_shift); // translate to the back right
    wheelBR.drawWheel();
    glPopMatrix();
  }

  // front left wheel
  {
    glPushMatrix();
    glTranslated(front_axle_shift, 0.0, -wheel_side_shift); // translate to the front left
    wheelFL.drawWheel();
    glPopMatrix();
  }

  // front right wheel
  {
    glPushMatrix();
    glRotatef(180, 0, 1, 0); // rotate the wheel to the opposite direction
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

void Car::setBodyColor(GLubyte r, GLubyte g, GLubyte b) {
    car_color[0] = r;
    car_color[1] = g;
    car_color[2] = b;
    setParameters();
}

void Car::drawNeon() {
    glPushAttrib(GL_ENABLE_BIT | GL_LIGHTING_BIT | GL_DEPTH_BUFFER_BIT); 
    
    glDisable(GL_TEXTURE_2D); 
    glDisable(GL_LIGHTING);   
    glEnable(GL_BLEND);       
    
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); 
    
    glDepthMask(GL_FALSE);  

    float length = 4.2f; 
    float width = 2.0f;
    
    float y_pos = 0.02f; 

    glBegin(GL_TRIANGLE_FAN);
        glColor4ub(car_color[0], car_color[1], car_color[2], 170);
        glVertex3f(0.0f, y_pos, 0.0f);

        glColor4ub(car_color[0], car_color[1], car_color[2], 0);
        
        glVertex3f(-length, y_pos, -width);
        glVertex3f( length, y_pos, -width);
        glVertex3f( length, y_pos,  width);
        glVertex3f(-length, y_pos,  width);
        glVertex3f(-length, y_pos, -width); 
    glEnd();

    glDepthMask(GL_TRUE);

    glPopAttrib(); 
}

void Car::drawCar() {
  glPushMatrix(); // put everything that will be drawed into a new transf matrix

  glTranslatef(0.0f, 0.19f, 0.0f); // lift the car up
  glScalef(0.66f, 0.66f, 0.66f); // scale the car

  // based on the center point of the car
  drawTheWheels();
  drawChassis();
  drawDoors();
  drawBumpers();

  drawNeon();

  glPopMatrix(); // pop the matrix to return to the previous one
}