#include "Wheel.h"

Wheel::Wheel(float radius, float width){
  this->radius = radius;
  this->width = width;
  this->rotation_angle = 0;
}

Wheel::~Wheel(){
  gluDeleteQuadric(quad);
}

void Wheel::drawRim(){ // draw the wheel rim
  glColor3ubv (rim_color); // paints the rim
  
  gluCylinder(quad, radius, radius, width, 32, 32);
}

void Wheel::drawTire(){
  glPushMatrix();

  glColor3ubv (tire_color); // paints the tire
  
  gluCylinder(quad, 0.7, 0.7, width, 32, 32);
  gluDisk(quad, radius, 0.7, 32, 2);
  glTranslated(0, 0, width); // translate to the other side of the tire
  gluDisk(quad, radius, 0.7, 32, 2);

  glPopMatrix();
}

void Wheel::drawWheel(){
  glPushMatrix();

  glTranslatef(0, 0.7, -width/2); // translate up the tire radius and width distance 
  glRotatef(rotation_angle, 0, 0, 1); // rotates based on the rotation angle

  drawRim();
  drawTire();

  glPopMatrix();
}

