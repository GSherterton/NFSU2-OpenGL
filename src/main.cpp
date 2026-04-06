/*
 * Also the cameras moves with w, a, s, d, space and z keys.
 * and the m key to enable/disable the camera movement.
 */

#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>

#include "Camera.h"
#include "Garage.h"
#include "Platform.h"
#include "Poster.h"
#include "Shelf.h"
#include "Car.h"
#include "Menu.h"

#define RESOLUTION 30
#define PI 3.14159265
#define THETA 20.0
#define STEP 1.0

Camera camera(0, 2.0, 8.0);
Garage garage(5.0f, 5.0f, 4.0f);
Platform platform(3.0f, 0.2f);
Shelf shelf(-4.5f, 0.0f, -4.97f, 1.2f, 2.5f, 0.5f);
Poster poster1(0.2f, 1.3f, -4.99f, 1.4f, 2.1f);
Poster poster2(1.7f, 1.3f, -4.99f, 1.4f, 2.1f);
Poster poster3(3.2f, 1.3f, -4.99f, 1.4f, 2.1f);
Car carro;
Menu menu_interface;

bool mouseLeftDown = false;
int lastMouseX = 0;
bool move_camera = false;

void init(){
  glClearColor (1.0, 1.0, 1.0, 0.0);
  glShadeModel (GL_SMOOTH); // select gouraud shading

  glEnable(GL_DEPTH_TEST); // enable depth test
  glEnable(GL_MAP1_VERTEX_3);
  glEnable(GL_MAP2_VERTEX_3);
  glEnable(GL_AUTO_NORMAL);
  glMapGrid2f(RESOLUTION, 0.0, 1.0, RESOLUTION, 0.0, 1.0);
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  garage.loadTextures("textures/wall2.png", "textures/floor2.png", "textures/ceiling2.jpg");
  platform.loadTextures("textures/plataform_disc.jpg", "textures/platform_side2.jpg");
  poster1.loadTexture("textures/poster1.jpg");
  poster2.loadTexture("textures/poster2.jpg");
  poster3.loadTexture("textures/poster3.jpg");
}

void display() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glLoadIdentity();
  camera.setTarget(0.0, 1.5, 0.0); // look at the vertical center of the garage
  camera.setLookAt();

  garage.draw();
  glPushMatrix();
    glRotatef(platform.getRotation(), 0.0f, 1.0f, 0.0f);
    platform.draw();
    carro.drawCar();
  glPopMatrix();
  shelf.draw();
  poster1.draw();
  poster2.draw();
  poster3.draw();
  menu_interface.drawMenu(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));

  glutSwapBuffers();
}

void reshape(int w, int h) {
  glViewport(0, 0, (GLsizei)w, (GLsizei)h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  gluPerspective(45.0, (GLfloat) w/(GLfloat) h, 1.0, 30.0);

  glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y) {
  if(key == 27 /* ESC */){
    exit(0);
  }else{
    // abilitates the camera movement
    if(key == 'm'){
      move_camera = !move_camera;
    }

    // manipulate camera
    if(move_camera){
      GLdouble x = camera.m_position[0], y = camera.m_position[2];

      if(key == 'w'){ // closer
        camera.m_position[0] = x - (STEP * (x / (sqrt(x*x + y*y))));
        camera.m_position[2] = y - (STEP * (y / (sqrt(x*x + y*y))));
      }

      if(key == 's'){ // further
        camera.m_position[0] = x + (STEP * (x / (sqrt(x*x + y*y))));
        camera.m_position[2] = y + (STEP * (y / (sqrt(x*x + y*y))));
      }

      if(key == 'a'){ // rotate left
        camera.m_position[0] = x * cos(THETA*PI/180) - y * sin(THETA*PI/180);
        camera.m_position[2] = x * sin(THETA*PI/180) + y * cos(THETA*PI/180);
      }

      if(key == 'd'){ // rotate right
        camera.m_position[0] = x * cos(-THETA*PI/180) - y * sin(-THETA*PI/180);
        camera.m_position[2] = x * sin(-THETA*PI/180) + y * cos(-THETA*PI/180);
      }

      if(key == ' '){ // up
        camera.m_position[1] += 1;
      }

      if(key == 'z'){ // down
        camera.m_position[1] -= 1;
      }
    }
  
    glutPostRedisplay();
  }
}

void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON) {
        mouseLeftDown = (state == GLUT_DOWN);
        lastMouseX = x;
    }
}

void motion(int x, int y) {
    if (mouseLeftDown) {
        int dx = x - lastMouseX;
        lastMouseX = x;
        platform.addRotation(dx * 0.5f);
        glutPostRedisplay();
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
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutMainLoop();

    return 0;
}
