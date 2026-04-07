#include "Lamp.h"

Lamp::Lamp(){}

Lamp::Lamp(GLfloat x, GLfloat y, GLfloat z){
  lampPosition[0] = x;
  lampPosition[1] = y;
  lampPosition[2] = z;
}

Lamp::~Lamp(){}

void Lamp::setupLampLight(){
  // setup light parameters
  GLfloat diffuse[]  = {5.0, 5.0, 2, 1.0};
  GLfloat ambient[]  = {0.2, 0.2, 0.2, 1.0};
  GLfloat position[] = {lampPosition[0], lampPosition[1], lampPosition[2], 1.0};

  glLightfv(GL_LIGHT0, GL_POSITION, position);
  glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
  glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);

  // atenuation
  glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, 0.1);
  glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, 0.05);

  if(enabled){ glEnable(GL_LIGHT0); }
  else{ glDisable(GL_LIGHT0); }
}

void Lamp::drawLamp() {
  setupLampLight();

  GLfloat emission[] = {1.0, 1.0, 0.4, 1.0};
  GLfloat noEmission[] = {0.0, 0.0, 0.0, 1.0};

  if(enabled){
    // turn on emission
    glMaterialfv(GL_FRONT, GL_EMISSION, emission);
  }

  glPushMatrix();
  glTranslatef(lampPosition[0], lampPosition[1], lampPosition[2]);
  glutSolidSphere(0.2, 20, 20);
  glPopMatrix();

  // turn off emission
  glMaterialfv(GL_FRONT, GL_EMISSION, noEmission);
}
