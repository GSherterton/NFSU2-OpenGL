#include <GL/glut.h>
#include <stdlib.h>

#include "Camera.h"
#include "Garagem.h"

using namespace std;

Camera camera(0, 2.0, 8.0);
Garagem garagem(5.0f, 5.0f, 4.0f);

void init(){
  glClearColor (0.0, 0.0, 0.0, 0.0);
  glShadeModel (GL_SMOOTH); // select gouraud shading

  glEnable(GL_DEPTH_TEST); // enable depth test

  garagem.carregarTexturas("textures/parede.jpg");
}

void display(){
  glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glLoadIdentity();
  camera.setDirecao(0.0, 1.5, 0.0); // olha para o centro vertical da garagem
  camera.setLookAt();

  garagem.desenhar();

  glutSwapBuffers();
}

void reshape(int w, int h){
  glViewport (0, 0, (GLsizei) w, (GLsizei) h);
  glMatrixMode (GL_PROJECTION);
  glLoadIdentity();

  // glFrustum (-1.0, 1.0, -1.0, 1.0, 1.0, 30.0); // podemos alterar dps isso se ficar ruim
  gluPerspective(60.0, (double)w / (double)h, 1.0, 30.0);

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