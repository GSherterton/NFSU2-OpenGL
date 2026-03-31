/*
 * Also the cameras moves with w, a, s, d, space and z keys.
 * and the m key to enable/disable the camera movement.
 */

#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>

#include "Camera.h"
#include "Car.h"

#define PI 3.14159265
#define THETA 20.0
#define STEP 1.0

using namespace std;

// Camera camera(-10, 5, 5);
Camera camera(5, 0, 0);
Car carro;

bool move_camera = false;

void init(){
  glClearColor (1.0, 1.0, 1.0, 0.0);
  glShadeModel (GL_SMOOTH); // select gouraud shading

  glEnable(GL_DEPTH_TEST); // enable depth test
  glEnable(GL_MAP1_VERTEX_3);
}

void display(){
  glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glLoadIdentity();
  camera.setLookAt();

  carro.drawCar();

  glutSwapBuffers();
}

void reshape(int w, int h){
  glViewport (0, 0, (GLsizei) w, (GLsizei) h);
  glMatrixMode (GL_PROJECTION);
  glLoadIdentity();

  gluPerspective(45.0, (GLfloat) w/(GLfloat) h, 1.0, 30.0);

  glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y){
  if(key == 27 /* ESC */){
    exit(0);
  }else{
    // abilitates the camera movement
    if(key == 'm'){
      move_camera = !move_camera;
    }

    // manipulate camera
    if(move_camera){
      GLdouble x = camera.posicao[0], y = camera.posicao[2];

      if(key == 'w'){ // closer
        camera.posicao[0] = x - (STEP * (x / (sqrt(x*x + y*y))));
        camera.posicao[2] = y - (STEP * (y / (sqrt(x*x + y*y))));
      }

      if(key == 's'){ // further
        camera.posicao[0] = x + (STEP * (x / (sqrt(x*x + y*y))));
        camera.posicao[2] = y + (STEP * (y / (sqrt(x*x + y*y))));
      }

      if(key == 'a'){ // rotate left
        camera.posicao[0] = x * cos(THETA*PI/180) - y * sin(THETA*PI/180);
        camera.posicao[2] = x * sin(THETA*PI/180) + y * cos(THETA*PI/180);
      }

      if(key == 'd'){ // rotate right
        camera.posicao[0] = x * cos(-THETA*PI/180) - y * sin(-THETA*PI/180);
        camera.posicao[2] = x * sin(-THETA*PI/180) + y * cos(-THETA*PI/180);
      }

      if(key == ' '){ // up
        camera.posicao[1] += 1;
      }

      if(key == 'z'){ // down
        camera.posicao[1] -= 1;
      }
    }
  
    glutPostRedisplay();
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