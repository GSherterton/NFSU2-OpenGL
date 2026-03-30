#include <cmath>
#include "Platform.h"

static const int SEGMENTS = 64;
static const float TWO_PI = 6.28318530718f;

Platform::Platform(GLfloat radius, GLfloat thickness)
    : m_radius(radius), m_thickness(thickness), m_rotation(0.0f) {}

void Platform::drawDisc(GLfloat y) {
    glColor3f(1.0f, 1.0f, 1.0f);
    // clang-format off
    glBegin(GL_TRIANGLE_FAN);
        glVertex3f(0.0f, y, 0.0f);
        for (int i = 0; i <= SEGMENTS; ++i) {
            float angle = TWO_PI * i / SEGMENTS;
            glVertex3f(m_radius * std::cos(angle), y, m_radius * std::sin(angle));
        }
    glEnd();
    // clang-format on
}

void Platform::drawSide() {
    glColor3f(0.0f, 0.0f, 1.0f);
    // clang-format off
    glBegin(GL_QUAD_STRIP);
        for (int i = 0; i <= SEGMENTS; ++i) {
            float angle = TWO_PI * i / SEGMENTS;
            float x     = m_radius * std::cos(angle);
            float z     = m_radius * std::sin(angle);
            glVertex3f(x, 0.0f,        z);
            glVertex3f(x, m_thickness, z);
        }
    glEnd();
    // clang-format on
}

void Platform::addRotation(float delta) {
    m_rotation += delta;
    if (m_rotation >= 360.0f)
        m_rotation -= 360.0f;
    if (m_rotation < 0.0f)
        m_rotation += 360.0f;
}

void Platform::draw() {
    // clang-format off
    glPushMatrix();
        glTranslatef(0.0f, 0.0f, 1.0f);
        glRotatef(m_rotation, 0.0f, 1.0f, 0.0f);
        drawDisc(m_thickness);
        drawSide();
    glPopMatrix();
    // clang-format on
}
