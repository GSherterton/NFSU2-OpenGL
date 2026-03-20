#include <GL/glut.h>
#include <stdlib.h>

#include "Camera.h"

using namespace std;

Camera camera(0, 0, 5);

void init(){
  glClearColor (0.0, 0.0, 0.0, 0.0);
  glShadeModel (GL_SMOOTH); // select gouraud shading

  glEnable(GL_DEPTH_TEST); // enable depth test
}

void display(){
  glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glLoadIdentity();
  camera.setLookAt();

  glutWireCube (1.0); // só um exemplo

  glutSwapBuffers();
}

void reshape(int w, int h){
  glViewport (0, 0, (GLsizei) w, (GLsizei) h);
  glMatrixMode (GL_PROJECTION);
  glLoadIdentity();

  glFrustum (-1.0, 1.0, -1.0, 1.0, 1.0, 30.0); // podemos alterar dps isso se ficar ruim

  glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y){
  if(key == 27 /* ESC */){
    exit(0);
  }
}

int main(int argc, char** argv){
  glutInit(&argc, argv);
  glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

  glutInitWindowSize (1280, 720); // inicialmente em 720p
  glutInitWindowPosition (100, 100);
  glutCreateWindow ("NFSU2-OpenGL");
  init ();

  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutKeyboardFunc(keyboard);
  glutMainLoop();

  return 0;
}