#pragma once
#include <GL/glut.h>
#include <iostream>
#include <fstream>

#define CAMERA_DATA_FILE "data/camera_data.txt"

using namespace std;

class Camera{
  public:
    GLdouble posicao[3]; // x, y, z
    GLdouble direcao[3]; // x, y, z

    Camera();
    Camera(const GLdouble x, const GLdouble y, const GLdouble z);
    ~Camera();

    bool readData();
    bool saveData();

    void setPosicao(const GLdouble x, const GLdouble y, const GLdouble z);
    void setDirecao(const GLdouble x, const GLdouble y, const GLdouble z);

    void setLookAt();
};