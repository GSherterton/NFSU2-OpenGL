#pragma once

#include <GL/glut.h>

class Garagem {
public:
    const GLfloat m_larg;
    const GLfloat m_prof;
    const GLfloat m_altura;

    Garagem(GLfloat larg, GLfloat prof, GLfloat altura) : m_larg(larg), m_prof(prof), m_altura(altura) {}

    void desenhar();
    void desenharChao();
    void desenharTeto();
    void desenharParedeFundos();
    void desenharParedeEsquerda();
    void desenharParedeDireita();
    void desenharPilares();
};
