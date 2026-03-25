#pragma once

#include <GL/glut.h>
#include "Textura.h"

class Garagem {
    public:
        const GLfloat m_larg;
        const GLfloat m_prof;
        const GLfloat m_altura;

        Garagem(GLfloat larg, GLfloat prof, GLfloat altura)
            : m_larg(larg), m_prof(prof), m_altura(altura), m_texParede(nullptr), m_texChao(nullptr), m_texTeto(nullptr) {}

        void carregarTexturas(const char* caminhoParede, const char* caminhoChao, const char* caminhoTeto);

        void desenhar();
        void desenharChao();
        void desenharTeto();
        void desenharParedeFundos();
        void desenharParedeEsquerda();
        void desenharParedeDireita();
        void desenharPilares();

    private:
        Textura* m_texParede;
        Textura* m_texChao;
        Textura* m_texTeto;
};
