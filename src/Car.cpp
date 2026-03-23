#include "Car.h"

Car::Car(){}

Car::~Car(){}

void Car::drawTheWheels(){
  GLdouble back_shift = -2.0, front_shift = 2.0, side_shift = 1.5;

  // back left wheel
  {
    glPushMatrix();
    glTranslated(back_shift, 0.0, side_shift); // translate to the back left
    wheelBL.drawWheel();
    glPopMatrix();
  }

  // back right wheel
  {
    glPushMatrix();
    glTranslated(back_shift, 0.0, -side_shift); // translate to the back right
    wheelBR.drawWheel();
    glPopMatrix();
  }

  // front left wheel
  {
    glPushMatrix();
    glTranslated(front_shift, 0.0, side_shift); // translate to the front left
    wheelFL.drawWheel();
    glPopMatrix();
  }

  // front right wheel
  {
    glPushMatrix();
    glTranslated(front_shift, 0.0, -side_shift); // translate to the front right
    wheelFR.drawWheel();
    glPopMatrix();
  }
}

void Car::drawChassis(){
  chassis.drawChassis();
}

void drawChassis() {
  glColor3f(0.8, 0.0, 0.0);

  glBegin(GL_QUADS);
  // Base
  glVertex3f(-3, 0, 1.2);
  glVertex3f( 3, 0, 1.2);
  glVertex3f( 3, 1, 1.2);
  glVertex3f(-3, 1, 1.2);

  // Trás
  glVertex3f(-3, 0, -1.2);
  glVertex3f(-3, 1, -1.2);
  glVertex3f( 3, 1, -1.2);
  glVertex3f( 3, 0, -1.2);
  glEnd();
}

void drawDoors() {
  glColor3f(0.6, 0.0, 0.0);

  // Porta esquerda
  glBegin(GL_QUADS);
  glVertex3f(-1.5, 0.2, 1.21);
  glVertex3f( 0.0, 0.2, 1.21);
  glVertex3f( 0.0, 0.9, 1.21);
  glVertex3f(-1.5, 0.9, 1.21);
  glEnd();

  // Porta direita
  glBegin(GL_QUADS);
  glVertex3f(0.0, 0.2, 1.21);
  glVertex3f(1.5, 0.2, 1.21);
  glVertex3f(1.5, 0.9, 1.21);
  glVertex3f(0.0, 0.9, 1.21);
  glEnd();
}

void drawBumper() {
  glColor3f(0.2, 0.2, 0.2);

  // Frente
  glBegin(GL_QUADS);
  glVertex3f(-3.2, 0, 1.2);
  glVertex3f(-3.0, 0, 1.2);
  glVertex3f(-3.0, 0.5, 1.2);
  glVertex3f(-3.2, 0.5, 1.2);
  glEnd();

  // Trás
  glBegin(GL_QUADS);
  glVertex3f(3.0, 0, 1.2);
  glVertex3f(3.2, 0, 1.2);
  glVertex3f(3.2, 0.5, 1.2);
  glVertex3f(3.0, 0.5, 1.2);
  glEnd();
}

void drawFender(float x, float z) {
  glPushMatrix();
  glTranslatef(x, 0.5, z);

  glColor3f(0.7, 0.0, 0.0);
  glutSolidCube(1.2);

  glPopMatrix();
}

void Car::drawCar() {
  glPushMatrix(); // put everything that will be drawed into a new transf matrix

  // based on the center point of the car
  drawTheWheels();
  drawChassis();
  // drawDoors();
  // drawBumper();

  // // Paralamas
  // drawFender(-2.0, 1.2);
  // drawFender( 2.0, 1.2);
  // drawFender(-2.0,-1.2);
  // drawFender( 2.0,-1.2);

  // // Rodas
  // glPushMatrix();
  // glTranslatef(-2.0, 0.0, 1.5);
  // drawWheel();
  // glPopMatrix();

  // glPushMatrix();
  // glTranslatef(2.0, 0.0, 1.5);
  // drawWheel();
  // glPopMatrix();

  // glPushMatrix();
  // glTranslatef(-2.0, 0.0, -1.5);
  // drawWheel();
  // glPopMatrix();

  // glPushMatrix();
  // glTranslatef(2.0, 0.0, -1.5);
  // drawWheel();
  // glPopMatrix();
}