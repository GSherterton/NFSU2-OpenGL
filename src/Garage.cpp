#include <GL/glut.h>
#include "Garage.h"
#include "Texture.h"

#define DARK_GRAY    0.25f, 0.25f, 0.25f
#define BLUISH_GRAY  0.20f, 0.20f, 0.22f

void Garage::loadTextures(const char* wallPath, const char* floorPath, const char* ceilingPath) {
    delete m_wallTex;
    m_wallTex = new Texture(wallPath);
    delete m_floorTex;
    m_floorTex = new Texture(floorPath);
    delete m_ceilingTex;
    m_ceilingTex = new Texture(ceilingPath);
}


void Garage::drawFloor() {
    bool hasTexture = (m_floorTex != nullptr && m_floorTex->m_id != 0);
    if (hasTexture) {
        glEnable(GL_TEXTURE_2D);
        m_floorTex->bind();
    }
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-m_width, 0.0f,  m_depth);
        glTexCoord2f(1.0f, 0.0f); glVertex3f( m_width, 0.0f,  m_depth);
        glTexCoord2f(1.0f, 1.0f); glVertex3f( m_width, 0.0f, -m_depth);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(-m_width, 0.0f, -m_depth);
    glEnd();
    if (hasTexture) {
        m_floorTex->unbind();
        glDisable(GL_TEXTURE_2D);
    }
}

void Garage::drawCeiling() {
    bool hasTexture = (m_ceilingTex != nullptr && m_ceilingTex->m_id != 0);
    if (hasTexture) {
        glEnable(GL_TEXTURE_2D);
        m_ceilingTex->bind();
    }
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-m_width, m_height,  m_depth);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(-m_width, m_height, -m_depth);
        glTexCoord2f(1.0f, 1.0f); glVertex3f( m_width, m_height, -m_depth);
        glTexCoord2f(1.0f, 0.0f); glVertex3f( m_width, m_height,  m_depth);
    glEnd();
    if (hasTexture) {
        m_ceilingTex->unbind();
        glDisable(GL_TEXTURE_2D);
    }
}

void Garage::drawBackWall() {
    bool hasTexture = (m_wallTex != nullptr && m_wallTex->m_id != 0);
    if (hasTexture) {
        glEnable(GL_TEXTURE_2D);
        m_wallTex->bind();
    }
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-m_width, 0.0f,      -m_depth);
        glTexCoord2f(1.0f, 0.0f); glVertex3f( m_width, 0.0f,      -m_depth);
        glTexCoord2f(1.0f, 1.0f); glVertex3f( m_width, m_height,  -m_depth);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(-m_width, m_height,  -m_depth);
    glEnd();
    if (hasTexture) {
        m_wallTex->unbind();
        glDisable(GL_TEXTURE_2D);
    }
}

void Garage::drawLeftWall() {
    bool hasTexture = (m_wallTex != nullptr && m_wallTex->m_id != 0);
    if (hasTexture) {
        glEnable(GL_TEXTURE_2D);
        m_wallTex->bind();
    }
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-m_width, 0.0f,      m_depth);
        glTexCoord2f(1.0f, 0.0f); glVertex3f(-m_width, 0.0f,     -m_depth);
        glTexCoord2f(1.0f, 1.0f); glVertex3f(-m_width, m_height, -m_depth);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(-m_width, m_height,  m_depth);
    glEnd();
    if (hasTexture) {
        m_wallTex->unbind();
        glDisable(GL_TEXTURE_2D);
    }
}

void Garage::drawRightWall() {
    bool hasTexture = (m_wallTex != nullptr && m_wallTex->m_id != 0);
    if (hasTexture) {
        glEnable(GL_TEXTURE_2D);
        m_wallTex->bind();
    }
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 0.0f); glVertex3f( m_width, 0.0f,      -m_depth);
        glTexCoord2f(1.0f, 0.0f); glVertex3f( m_width, 0.0f,       m_depth);
        glTexCoord2f(1.0f, 1.0f); glVertex3f( m_width, m_height,   m_depth);
        glTexCoord2f(0.0f, 1.0f); glVertex3f( m_width, m_height,  -m_depth);
    glEnd();
    if (hasTexture) {
        m_wallTex->unbind();
        glDisable(GL_TEXTURE_2D);
    }
}

void Garage::drawPillars() {
    const GLfloat pillarWidth = 0.2f;
    const GLfloat pillarDepth = 0.2f;

    glColor3f(0.35f, 0.35f, 0.38f);

    // Left pillar
    glPushMatrix();
        glTranslatef(-m_width + pillarWidth * 0.5f, m_height * 0.5f, m_depth - pillarDepth * 0.5f);
        glScalef(pillarWidth, m_height, pillarDepth);
        glutSolidCube(1.0);
    glPopMatrix();

    // Right pillar
    glPushMatrix();
        glTranslatef( m_width - pillarWidth * 0.5f, m_height * 0.5f, m_depth - pillarDepth * 0.5f);
        glScalef(pillarWidth, m_height, pillarDepth);
        glutSolidCube(1.0);
    glPopMatrix();

    // Horizontal beam at the top of the opening
    glColor3f(0.32f, 0.32f, 0.34f);
    glPushMatrix();
        glTranslatef(0.0f, m_height - 0.1f, m_depth - pillarDepth * 0.5f);
        glScalef(m_width * 2.0f, 0.2f, pillarDepth);
        glutSolidCube(1.0);
    glPopMatrix();
}

void Garage::draw() {
    glPushMatrix();
        drawFloor();
        drawCeiling();
        drawBackWall();
        drawLeftWall();
        drawRightWall();
        drawPillars();
    glPopMatrix();
}
