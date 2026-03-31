#include "Camera.h"

bool Camera::readData(){
  // cria um fluxo de entrada (para ler o arquivo)
  ifstream fp;

  //tenta abrir o arquivo
  fp.open(CAMERA_DATA_FILE);

  //verifica se o arquivo foi aberto
  if(!fp.is_open()){
    cout << "Nao foi possivel abrir o arquivo [" << CAMERA_DATA_FILE << "].\n";
    return false;
  }

  fp >> posicao[0] >> posicao[1] >> posicao[2];

  fp.close();

  return true;
}

bool Camera::saveData(){
  //cria um fluxo de saida (para escrever no arquivo)
  ofstream fp;

  //tenta abrir o arquivo
  fp.open(CAMERA_DATA_FILE);

  //verifica se o arquivo foi aberto
  if(!fp.is_open()){
    cout << "Nao foi possivel abrir o arquivo [" << CAMERA_DATA_FILE << "].\n";
    return false;
  }

  fp << posicao[0] << " " << posicao[1] << " " << posicao[2] << endl;

  fp.close();

  return true;
}

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
    m_target[1] = 1.5;
    m_target[2] = 0;

  readData(); // tries read the data, if not possible, it will keep the default position
}

Camera::~Camera() { // default destructor
  saveData();
}

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
