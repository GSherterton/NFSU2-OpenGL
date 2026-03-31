#pragma once
#include <GL/glut.h>
#include <iostream>
#include <fstream>

#define CAMERA_DATA_FILE "data/camera_data.txt"

using namespace std;

class Camera {
  public:
    GLdouble m_position[3]; // x, y, z
    GLdouble m_target[3];   // x, y, z

    Camera();
    Camera(const GLdouble x, const GLdouble y, const GLdouble z);
    ~Camera();

    bool readData();
    bool saveData();

    bool readData();
    bool saveData();

    void setPosition(const GLdouble x, const GLdouble y, const GLdouble z);
    void setTarget(const GLdouble x, const GLdouble y, const GLdouble z);

    void setLookAt();
};
