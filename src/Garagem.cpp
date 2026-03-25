#include <GL/glut.h>
#include "Garagem.h"
#include "Textura.h"

#define CINZA_ESCURO 0.25f, 0.25f, 0.25f
#define CINZA_AZULADO 0.20f, 0.20f, 0.22f

void Garagem::carregarTexturas(const char* caminhoParede, const char* caminhoChao, const char* caminhoTeto) {
    delete m_texParede;
    m_texParede = new Textura(caminhoParede);
    delete m_texChao;
    m_texChao = new Textura(caminhoChao);
    delete m_texTeto;
    m_texTeto = new Textura(caminhoTeto);
}


void Garagem::desenharChao() {
    bool comTextura = (m_texChao != nullptr && m_texChao->m_id != 0);
    if (comTextura) {
        glEnable(GL_TEXTURE_2D);
        m_texChao->bind();
    }
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-m_larg, 0.0f,  m_prof);
        glTexCoord2f(1.0f, 0.0f); glVertex3f( m_larg, 0.0f,  m_prof);
        glTexCoord2f(1.0f, 1.0f); glVertex3f( m_larg, 0.0f, -m_prof);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(-m_larg, 0.0f, -m_prof);
    glEnd();
    if (comTextura) {
        m_texChao->unbind();
        glDisable(GL_TEXTURE_2D);
    }
}

void Garagem::desenharTeto() {
    bool comTextura = (m_texTeto != nullptr && m_texTeto->m_id != 0);
    if (comTextura) {
        glEnable(GL_TEXTURE_2D);
        m_texTeto->bind();
    }
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-m_larg, m_altura,  m_prof);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(-m_larg, m_altura, -m_prof);
        glTexCoord2f(1.0f, 1.0f); glVertex3f( m_larg, m_altura, -m_prof);
        glTexCoord2f(1.0f, 0.0f); glVertex3f( m_larg, m_altura,  m_prof);
    glEnd();
    if (comTextura) {
        m_texTeto->unbind();
        glDisable(GL_TEXTURE_2D);
    }
}

void Garagem::desenharParedeFundos() {
    bool comTextura = (m_texParede != nullptr && m_texParede->m_id != 0);
    if (comTextura) {
        glEnable(GL_TEXTURE_2D);
        m_texParede->bind();
    }
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-m_larg, 0.0f,     -m_prof);
        glTexCoord2f(1.0f, 0.0f); glVertex3f( m_larg, 0.0f,     -m_prof);
        glTexCoord2f(1.0f, 1.0f); glVertex3f( m_larg, m_altura, -m_prof);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(-m_larg, m_altura, -m_prof);
    glEnd();
    if (comTextura) {
        m_texParede->unbind();
        glDisable(GL_TEXTURE_2D);
    }
}

void Garagem::desenharParedeEsquerda() {
    bool comTextura = (m_texParede != nullptr && m_texParede->m_id != 0);
    if (comTextura) {
        glEnable(GL_TEXTURE_2D);
        m_texParede->bind();
    }
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-m_larg, 0.0f,      m_prof);
        glTexCoord2f(1.0f, 0.0f); glVertex3f(-m_larg, 0.0f,     -m_prof);
        glTexCoord2f(1.0f, 1.0f); glVertex3f(-m_larg, m_altura, -m_prof);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(-m_larg, m_altura,  m_prof);
    glEnd();
    if (comTextura) {
        m_texParede->unbind();
        glDisable(GL_TEXTURE_2D);
    }
}

void Garagem::desenharParedeDireita() {
    bool comTextura = (m_texParede != nullptr && m_texParede->m_id != 0);
    if (comTextura) {
        glEnable(GL_TEXTURE_2D);
        m_texParede->bind();
    }
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 0.0f); glVertex3f( m_larg, 0.0f,     -m_prof);
        glTexCoord2f(1.0f, 0.0f); glVertex3f( m_larg, 0.0f,      m_prof);
        glTexCoord2f(1.0f, 1.0f); glVertex3f( m_larg, m_altura,  m_prof);
        glTexCoord2f(0.0f, 1.0f); glVertex3f( m_larg, m_altura, -m_prof);
    glEnd();
    if (comTextura) {
        m_texParede->unbind();
        glDisable(GL_TEXTURE_2D);
    }
}

void Garagem::desenharPilares() {
    const GLfloat larg_pilar = 0.2f;
    const GLfloat prof_pilar = 0.2f;

    glColor3f(0.35f, 0.35f, 0.38f);

    // Pilar esquerdo
    glPushMatrix();
        glTranslatef(-m_larg + larg_pilar * 0.5f, m_altura * 0.5f, m_prof - prof_pilar * 0.5f);
        glScalef(larg_pilar, m_altura, prof_pilar);
        glutSolidCube(1.0);
    glPopMatrix();

    // Pilar direito
    glPushMatrix();
        glTranslatef( m_larg - larg_pilar * 0.5f, m_altura * 0.5f, m_prof - prof_pilar * 0.5f);
        glScalef(larg_pilar, m_altura, prof_pilar);
        glutSolidCube(1.0);
    glPopMatrix();

    // Viga horizontal no topo da abertura
    glColor3f(0.32f, 0.32f, 0.34f);
    glPushMatrix();
        glTranslatef(0.0f, m_altura - 0.1f, m_prof - prof_pilar * 0.5f);
        glScalef(m_larg * 2.0f, 0.2f, prof_pilar);
        glutSolidCube(1.0);
    glPopMatrix();
}

void Garagem::desenhar() {
    glPushMatrix();
        desenharChao();
        desenharTeto();
        desenharParedeFundos();
        desenharParedeEsquerda();
        desenharParedeDireita();
        desenharPilares();
    glPopMatrix();
}
