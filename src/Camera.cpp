#include "Camera.h"

Camera::Camera() { // create a camera with default position (0, 0, 5)
  position[0] = 0; // x
  position[1] = 0; // y
  position[2] = 5; // z

  target[0] = 0; // x
  target[1] = 0; // y
  target[2] = 0; // z
}

Camera::Camera(const GLdouble x, const GLdouble y, const GLdouble z) { // create a camera with a predefined position
  position[0] = x;
  position[1] = y;
  position[2] = z;

  target[0] = 0;
  target[1] = 0;
  target[2] = 0;
}

Camera::~Camera() {} // default destructor

void Camera::setPosition(const GLdouble x, const GLdouble y, const GLdouble z) {
  position[0] = x;
  position[1] = y;
  position[2] = z;
}

void Camera::setTarget(const GLdouble x, const GLdouble y, const GLdouble z) {
  target[0] = x;
  target[1] = y;
  target[2] = z;
}

void Camera::setLookAt() {
  gluLookAt(position[0], position[1], position[2],
            target[0],   target[1],   target[2],
            0.0, 1.0, 0.0);
}
