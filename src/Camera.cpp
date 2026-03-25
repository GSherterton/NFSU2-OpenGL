#include "Camera.h"

Camera::Camera() {     // create a camera with default position (0, 0, 5)
    m_position[0] = 0; // x
    m_position[1] = 0; // y
    m_position[2] = 5; // z

    m_target[0] = 0; // x
    m_target[1] = 0; // y
    m_target[2] = 0; // z
}

Camera::Camera(const GLdouble x, const GLdouble y, const GLdouble z) { // create a camera with a predefined position
    m_position[0] = x;
    m_position[1] = y;
    m_position[2] = z;

    m_target[0] = 0;
    m_target[1] = 0;
    m_target[2] = 0;
}

Camera::~Camera() {} // default destructor

void Camera::setPosition(const GLdouble x, const GLdouble y, const GLdouble z) {
    m_position[0] = x;
    m_position[1] = y;
    m_position[2] = z;
}

void Camera::setTarget(const GLdouble x, const GLdouble y, const GLdouble z) {
    m_target[0] = x;
    m_target[1] = y;
    m_target[2] = z;
}

void Camera::setLookAt() {
    gluLookAt(m_position[0], m_position[1], m_position[2],
              m_target[0], m_target[1], m_target[2],
              0.0, 1.0, 0.0);
}
