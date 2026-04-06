#pragma once

#include <GL/gl.h>

class Drum {
    public:
        Drum(GLfloat x, GLfloat y, GLfloat z, GLfloat radius, GLfloat height);
        void draw();

    private:
        GLfloat m_x, m_y, m_z;
        GLfloat m_radius, m_height;

        void drawBody();
        void drawCap(GLfloat y);
        void drawRing(GLfloat y, GLfloat ringRadius, GLfloat ringHeight);
        void drawPlug();
};
