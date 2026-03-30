#include <GL/glut.h>
#include "Colors.h"
#include "Poster.h"

Poster::Poster(GLfloat x, GLfloat y, GLfloat z, GLfloat width, GLfloat height)
    : m_x(x), m_y(y), m_z(z), m_width(width), m_height(height), m_tex(nullptr) {}

Poster::~Poster() {
    delete m_tex;
}

void Poster::loadTexture(const char* texturePath) {
    delete m_tex;
    m_tex = new Texture(texturePath);
}

void Poster::draw() {
    bool hasTexture = (m_tex != nullptr && m_tex->m_id != 0);
    if (hasTexture) {
        glEnable(GL_TEXTURE_2D);
        m_tex->bind();
    }
    glColor3f(COLOR_WHITE);
    // clang-format off
    glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(m_x,           m_y,            m_z);
        glTexCoord2f(1.0f, 0.0f); glVertex3f(m_x + m_width, m_y,            m_z);
        glTexCoord2f(1.0f, 1.0f); glVertex3f(m_x + m_width, m_y + m_height, m_z);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(m_x,           m_y + m_height, m_z);
    glEnd();
    // clang-format on
    if (hasTexture) {
        m_tex->unbind();
        glDisable(GL_TEXTURE_2D);
    }
}
