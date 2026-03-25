#include <GL/glut.h>
#include <cstdio>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include "Textura.h"

Textura::Textura(const char* caminho) : m_id(0) {
    int largura, altura, canais;
    stbi_set_flip_vertically_on_load(1);
    unsigned char* dados = stbi_load(caminho, &largura, &altura, &canais, 0);

    if (!dados) {
        fprintf(stderr, "Textura: erro ao carregar '%s': %s\n", caminho, stbi_failure_reason());
        return;
    }

    GLenum formato = (canais == 4) ? GL_RGBA : GL_RGB;

    glGenTextures(1, &m_id);
    glBindTexture(GL_TEXTURE_2D, m_id);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, formato, largura, altura, 0, formato, GL_UNSIGNED_BYTE, dados);

    stbi_image_free(dados);
    glBindTexture(GL_TEXTURE_2D, 0);
}

Textura::~Textura() {
    if (m_id != 0) {
        glDeleteTextures(1, &m_id);
    }
}

void Textura::bind() const {
    glBindTexture(GL_TEXTURE_2D, m_id);
}

void Textura::unbind() const {
    glBindTexture(GL_TEXTURE_2D, 0);
}
