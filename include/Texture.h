#pragma once

#include <GL/glut.h>

class Texture {
    public:
        GLuint m_id;

        Texture(const char* path);
        ~Texture();

        void bind() const;
        void unbind() const;
};
