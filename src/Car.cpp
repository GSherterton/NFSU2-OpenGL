#include "Car.h"

Car::Car(){}

Car::~Car(){}

// void Car::drawCar(){
//   glPushMatrix(); // put everything that will be drawed into a new transf matrix
// }

// Função para desenhar um círculo (roda)
void drawWheel(float radius) {
  glBegin(GL_POLYGON);
  for (int i = 0; i < 360; i++) {
    float theta = i * 3.14159f / 180.0f;
    float x = radius * cos(theta);
    float y = radius * sin(theta);
    glVertex3f(x, y, 0.0f);
  }
  glEnd();
}

// Corpo do carro
void drawCarBody() {
  glColor3f(1.0, 0.0, 0.0);

  glBegin(GL_QUADS);
  // Base
  glVertex3f(-2, 0, 1);
  glVertex3f( 2, 0, 1);
  glVertex3f( 2, 1, 1);
  glVertex3f(-2, 1, 1);

  // Parte de trás
  glVertex3f(-2, 0, -1);
  glVertex3f(-2, 1, -1);
  glVertex3f( 2, 1, -1);
  glVertex3f( 2, 0, -1);

  // Lado esquerdo
  glVertex3f(-2, 0, -1);
  glVertex3f(-2, 0,  1);
  glVertex3f(-2, 1,  1);
  glVertex3f(-2, 1, -1);

  // Lado direito
  glVertex3f(2, 0, -1);
  glVertex3f(2, 1, -1);
  glVertex3f(2, 1,  1);
  glVertex3f(2, 0,  1);

  // Topo
  glVertex3f(-2, 1, -1);
  glVertex3f(-2, 1,  1);
  glVertex3f( 2, 1,  1);
  glVertex3f( 2, 1, -1);
  glEnd();
}

// Cabine do carro
void drawCarTop() {
  glColor3f(0.8, 0.0, 0.0);

  glBegin(GL_QUADS);
  glVertex3f(-1, 1, 0.8);
  glVertex3f( 1, 1, 0.8);
  glVertex3f( 1, 2, 0.8);
  glVertex3f(-1, 2, 0.8);

  glVertex3f(-1, 1, -0.8);
  glVertex3f(-1, 2, -0.8);
  glVertex3f( 1, 2, -0.8);
  glVertex3f( 1, 1, -0.8);

  glEnd();
}

// Carro completo
void Car::drawCar() {
  drawCarBody();
  drawCarTop();

  // Rodas
  glColor3f(0, 1, 0);

  // Frente esquerda
  glPushMatrix();
  glTranslatef(-1.5, 0, 1.1);
  drawWheel(0.4);
  glPopMatrix();

  // Frente direita
  glPushMatrix();
  glTranslatef(1.5, 0, 1.1);
  drawWheel(0.4);
  glPopMatrix();

  // Traseira esquerda
  glPushMatrix();
  glTranslatef(-1.5, 0, -1.1);
  drawWheel(0.4);
  glPopMatrix();

  // Traseira direita
  glPushMatrix();
  glTranslatef(1.5, 0, -1.1);
  drawWheel(0.4);
  glPopMatrix();
}