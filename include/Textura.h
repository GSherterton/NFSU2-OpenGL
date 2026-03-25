#pragma once

#include <GL/glut.h>

class Textura {
    public:
        GLuint m_id;

        Textura(const char* caminho);
        ~Textura();

        void bind() const;
        void unbind() const;
};
