#include <GL/glut.h>
#include "Garagem.h"

#define CINZA_ESCURO 0.25f, 0.25f, 0.25f
#define CINZA_AZULADO 0.20f, 0.20f, 0.22f


void Garagem::desenharChao() {
    glColor3f(CINZA_ESCURO);
    glBegin(GL_QUADS);
        glVertex3f(-m_larg, 0.0f,  m_prof);
        glVertex3f( m_larg, 0.0f,  m_prof);
        glVertex3f( m_larg, 0.0f, -m_prof);
        glVertex3f(-m_larg, 0.0f, -m_prof);
    glEnd();
}

void Garagem::desenharTeto() {
    glColor3f(CINZA_AZULADO);
    glBegin(GL_QUADS);
        glVertex3f(-m_larg, m_altura,  m_prof);
        glVertex3f(-m_larg, m_altura, -m_prof);
        glVertex3f( m_larg, m_altura, -m_prof);
        glVertex3f( m_larg, m_altura,  m_prof);
    glEnd();
}

void Garagem::desenharParedeFundos() {
    glColor3f(0.30f, 0.30f, 0.32f);
    glBegin(GL_QUADS);
        glVertex3f(-m_larg, 0.0f,  -m_prof);
        glVertex3f( m_larg, 0.0f,  -m_prof);
        glVertex3f( m_larg, m_altura, -m_prof);
        glVertex3f(-m_larg, m_altura, -m_prof);
    glEnd();
}

void Garagem::desenharParedeEsquerda() {
    glColor3f(0.28f, 0.28f, 0.30f);
    glBegin(GL_QUADS);
        glVertex3f(-m_larg, 0.0f,   m_prof);
        glVertex3f(-m_larg, 0.0f,  -m_prof);
        glVertex3f(-m_larg, m_altura, -m_prof);
        glVertex3f(-m_larg, m_altura,  m_prof);
    glEnd();
}

void Garagem::desenharParedeDireita() {
    glColor3f(0.28f, 0.28f, 0.30f);
    glBegin(GL_QUADS);
        glVertex3f( m_larg, 0.0f,  -m_prof);
        glVertex3f( m_larg, 0.0f,   m_prof);
        glVertex3f( m_larg, m_altura,  m_prof);
        glVertex3f( m_larg, m_altura, -m_prof);
    glEnd();
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
