#include <cmath>
#include "Colors.h"
#include "Platform.h"
#include "Texture.h"

static const int SEGMENTS = 64;
static const float TWO_PI = 6.28318530718f;

Platform::Platform(GLfloat radius, GLfloat thickness)
    : m_radius(radius), m_thickness(thickness), m_rotation(0.0f), m_discTex(nullptr), m_sideTex(nullptr) {}

void Platform::loadTextures(const char* discPath, const char* sidePath) {
    delete m_discTex;
    m_discTex = new Texture(discPath);
    delete m_sideTex;
    m_sideTex = new Texture(sidePath);
}

void Platform::drawDisc(GLfloat y) {
    bool hasTexture = (m_discTex != nullptr && m_discTex->m_id != 0);
    if (hasTexture) {
        glEnable(GL_TEXTURE_2D);
        m_discTex->bind();
    }
    glColor3f(COLOR_WHITE);
    // clang-format off
    glBegin(GL_TRIANGLE_FAN);
        glNormal3f(0.0f, 1.0f, 0.0f);
        glTexCoord2f(0.5f, 0.5f);
        glVertex3f(0.0f, y, 0.0f);
        for (int i = 0; i <= SEGMENTS; ++i) {
            float angle = TWO_PI * i / SEGMENTS;
            glTexCoord2f(0.5f + 0.5f * std::cos(angle), 0.5f + 0.5f * std::sin(angle));
            glVertex3f(m_radius * std::cos(angle), y, m_radius * std::sin(angle));
        }
    glEnd();
    // clang-format on
    if (hasTexture) {
        m_discTex->unbind();
        glDisable(GL_TEXTURE_2D);
    }
}

void Platform::drawSide() {
    bool hasTexture = (m_sideTex != nullptr && m_sideTex->m_id != 0);
    if (hasTexture) {
        glEnable(GL_TEXTURE_2D);
        m_sideTex->bind();
    }
    glColor3f(COLOR_WHITE);
    // clang-format off
    glBegin(GL_QUAD_STRIP);
        for (int i = 0; i <= SEGMENTS; ++i) {
            float angle = TWO_PI * i / SEGMENTS;
            float u     = (float)i / SEGMENTS * 16.0f;
            float x     = m_radius * std::cos(angle);
            float z     = m_radius * std::sin(angle);
            glNormal3f(std::cos(angle), 0.0f, std::sin(angle));
            glTexCoord2f(u, 0.0f); glVertex3f(x, 0.0f,        z);
            glTexCoord2f(u, 1.0f); glVertex3f(x, m_thickness, z);
        }
    glEnd();
    // clang-format on
    if (hasTexture) {
        m_sideTex->unbind();
        glDisable(GL_TEXTURE_2D);
    }
}

float Platform::getRotation() const {
    return m_rotation;
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
        drawDisc(m_thickness);
        drawSide();
    glPopMatrix();
    // clang-format on
}
