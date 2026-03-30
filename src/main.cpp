#include <GL/glut.h>
#include <stdlib.h>

#include "Camera.h"
#include "Garage.h"
#include "Platform.h"
#include "Poster.h"
#include "Shelf.h"

Camera camera(0, 2.0, 8.0);
Garage garage(5.0f, 5.0f, 4.0f);
Platform platform(3.0f, 0.2f);
Shelf shelf(-4.5f, 0.0f, -4.97f, 1.2f, 2.5f, 0.5f);
Poster poster1(0.2f, 1.0f, -4.99f, 1.4f, 2.1f);
Poster poster2(1.7f, 1.0f, -4.99f, 1.4f, 2.1f);
Poster poster3(3.2f, 1.0f, -4.99f, 1.4f, 2.1f);

bool mouseLeftDown = false;
int lastMouseX = 0;

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_SMOOTH); // select gouraud shading

    glEnable(GL_DEPTH_TEST); // enable depth test

    garage.loadTextures("textures/wall.jpg", "textures/floor.jpg", "textures/ceiling.jpg");
    platform.loadTextures("textures/plataform_disc.jpg", "textures/platform_side.jpg");
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
    platform.draw();
    shelf.draw();
    poster1.draw();
    poster2.draw();
    poster3.draw();

    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
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
