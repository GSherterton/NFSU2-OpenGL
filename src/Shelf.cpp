#include <GL/glut.h>
#include "Colors.h"
#include "Shelf.h"

static const GLfloat UPRIGHT_T = 0.06f; // vertical side column thickness
static const GLfloat BOARD_T = 0.05f;   // horizontal shelf board thickness
static const GLfloat BACK_T = 0.04f;    // back panel thickness

Shelf::Shelf(GLfloat x, GLfloat y, GLfloat z,
             GLfloat width, GLfloat height, GLfloat depth)
    : m_x(x), m_y(y), m_z(z),
      m_width(width), m_height(height), m_depth(depth) {}

// Draws an axis-aligned box from (x0,y0,z0) to (x1,y1,z1) with 6 quad faces.
void Shelf::drawBox(GLfloat x0, GLfloat y0, GLfloat z0,
                    GLfloat x1, GLfloat y1, GLfloat z1) {
    // clang-format off
    glBegin(GL_QUADS);
        // Front face (z = z1)
        glVertex3f(x0, y0, z1); glVertex3f(x1, y0, z1);
        glVertex3f(x1, y1, z1); glVertex3f(x0, y1, z1);
        // Back face (z = z0)
        glVertex3f(x1, y0, z0); glVertex3f(x0, y0, z0);
        glVertex3f(x0, y1, z0); glVertex3f(x1, y1, z0);
        // Left face (x = x0)
        glVertex3f(x0, y0, z0); glVertex3f(x0, y0, z1);
        glVertex3f(x0, y1, z1); glVertex3f(x0, y1, z0);
        // Right face (x = x1)
        glVertex3f(x1, y0, z1); glVertex3f(x1, y0, z0);
        glVertex3f(x1, y1, z0); glVertex3f(x1, y1, z1);
        // Top face (y = y1)
        glVertex3f(x0, y1, z1); glVertex3f(x1, y1, z1);
        glVertex3f(x1, y1, z0); glVertex3f(x0, y1, z0);
        // Bottom face (y = y0)
        glVertex3f(x0, y0, z0); glVertex3f(x1, y0, z0);
        glVertex3f(x1, y0, z1); glVertex3f(x0, y0, z1);
    glEnd();
    // clang-format on
}

void Shelf::drawUprights() {
    // Left upright column
    drawBox(0.0f, 0.0f, 0.0f, UPRIGHT_T, m_height, m_depth);
    // Right upright column
    drawBox(m_width - UPRIGHT_T, 0.0f, 0.0f, m_width, m_height, m_depth);
}

void Shelf::drawBoards() {
    GLfloat spacing = (m_height - BOARD_T) / 2.0f;
    for (int i = 0; i < 3; ++i) {
        GLfloat boardY = i * spacing;
        drawBox(UPRIGHT_T, boardY, BACK_T, m_width - UPRIGHT_T, boardY + BOARD_T, m_depth);
    }
}

void Shelf::drawBackPanel() {
    drawBox(0.0f, 0.0f, 0.0f, m_width, m_height, BACK_T);
}

void Shelf::draw() {
    // clang-format off
    glPushMatrix();
        glTranslatef(m_x, m_y, m_z);
        glColor3f(COLOR_RED_DARK);
        drawUprights();
        glColor3f(COLOR_RED_MID);
        drawBoards();
        glColor3f(COLOR_RED_SHADOW);
        drawBackPanel();
    glPopMatrix();
    // clang-format on
}
