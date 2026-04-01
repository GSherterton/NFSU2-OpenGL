#include <GL/glut.h>
#include "Lamp.h"

void Lamp::setup() {
    GLfloat pos[]      = {0.0f, 3.7f, 0.0f, 1.0f};
    GLfloat diffuse[]  = {1.0f, 0.95f, 0.8f, 1.0f};
    GLfloat ambient[]  = {0.1f, 0.1f,  0.1f, 1.0f};
    GLfloat specular[] = {0.8f, 0.8f,  0.8f, 1.0f};

    glLightfv(GL_LIGHT0, GL_POSITION, pos);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  diffuse);
    glLightfv(GL_LIGHT0, GL_AMBIENT,  ambient);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
}

void Lamp::draw() {
    glPushMatrix();
        glTranslatef(0.0f, 3.7f, 0.0f);
        glDisable(GL_LIGHTING);
        glColor3f(1.0f, 1.0f, 0.8f);
        glutSolidSphere(0.08, 8, 8);
        glEnable(GL_LIGHTING);
    glPopMatrix();
}
