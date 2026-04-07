#include "Drum.h"
#include "Colors.h"
#include <GL/gl.h>
#include <math.h>

static const int SEGMENTS = 32;
static const float TWO_PI = 6.28318530718f;

Drum::Drum(GLfloat x, GLfloat y, GLfloat z, GLfloat radius, GLfloat height)
    : m_x(x), m_y(y), m_z(z), m_radius(radius), m_height(height) {}

void Drum::drawBody() {
    glColor3f(COLOR_BLACK);
    glBegin(GL_QUAD_STRIP);
    for (int i = 0; i <= SEGMENTS; ++i) {
        float angle = TWO_PI * i / SEGMENTS;
        float cx = cosf(angle) * m_radius;
        float cz = sinf(angle) * m_radius;
        glVertex3f(cx, 0.0f, cz);
        glVertex3f(cx, m_height, cz);
    }
    glEnd();
}

void Drum::drawCap(GLfloat y) {
    glColor3f(COLOR_BLACK);
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(0.0f, y, 0.0f);
    for (int i = 0; i <= SEGMENTS; ++i) {
        float angle = TWO_PI * i / SEGMENTS;
        glVertex3f(cosf(angle) * m_radius, y, sinf(angle) * m_radius);
    }
    glEnd();
}

void Drum::drawRing(GLfloat y, GLfloat ringRadius, GLfloat ringHeight) {
    glColor3f(COLOR_DARK_GRAY);
    glBegin(GL_QUAD_STRIP);
    for (int i = 0; i <= SEGMENTS; ++i) {
        float angle = TWO_PI * i / SEGMENTS;
        float cx = cosf(angle) * ringRadius;
        float cz = sinf(angle) * ringRadius;
        glVertex3f(cx, y, cz);
        glVertex3f(cx, y + ringHeight, cz);
    }
    glEnd();
}

void Drum::drawPlug() {
    float plugRadius = 0.03f;
    float plugHeight = 0.03f;
    float offsetX = m_radius * 0.4f;
    float plugY = m_height;

    glColor3f(COLOR_DARK_GRAY);
    // side of plug
    glBegin(GL_QUAD_STRIP);
    for (int i = 0; i <= SEGMENTS; ++i) {
        float angle = TWO_PI * i / SEGMENTS;
        float cx = offsetX + cosf(angle) * plugRadius;
        float cz = sinf(angle) * plugRadius;
        glVertex3f(cx, plugY, cz);
        glVertex3f(cx, plugY + plugHeight, cz);
    }
    glEnd();
    // top of plug
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(offsetX, plugY + plugHeight, 0.0f);
    for (int i = 0; i <= SEGMENTS; ++i) {
        float angle = TWO_PI * i / SEGMENTS;
        glVertex3f(offsetX + cosf(angle) * plugRadius, plugY + plugHeight, sinf(angle) * plugRadius);
    }
    glEnd();
}

void Drum::draw() {
    glPushMatrix();
    glTranslatef(m_x, m_y, m_z);

    drawBody();
    drawCap(0.0f);
    drawCap(m_height);
    drawRing(m_height * 0.30f, m_radius + 0.015f, 0.04f);
    drawRing(m_height * 0.65f, m_radius + 0.015f, 0.04f);
    drawPlug();

    glPopMatrix();
}
