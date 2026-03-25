#include <GL/glut.h>
#include <stdlib.h>

#include "Camera.h"
#include "Garage.h"

Camera camera(0, 2.0, 8.0);
Garage garage(5.0f, 5.0f, 4.0f);

void init() {
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glShadeModel(GL_SMOOTH); // select gouraud shading

  glEnable(GL_DEPTH_TEST); // enable depth test

  garage.loadTextures("textures/wall.jpg", "textures/floor.jpg", "textures/ceiling.jpg");
}

void display() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glLoadIdentity();
  camera.setTarget(0.0, 1.5, 0.0); // look at the vertical center of the garage
  camera.setLookAt();

  garage.draw();

  glutSwapBuffers();
}

void reshape(int w, int h) {
  glViewport(0, 0, (GLsizei) w, (GLsizei) h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  gluPerspective(60.0, (double)w / (double)h, 1.0, 30.0);

  glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y) {
  if (key == 27 /* ESC */) {
    exit(0);
  }
}

int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

  glutInitWindowSize(1280, 720); // initially at 720p
  glutInitWindowPosition(100, 100);
  glutCreateWindow("NFSU2-OpenGL");
  init();

  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutKeyboardFunc(keyboard);
  glutMainLoop();

  return 0;
}
