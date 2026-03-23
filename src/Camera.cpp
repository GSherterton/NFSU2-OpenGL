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

Camera::Camera(){ // criar uma camera com a posição padrão (0, 0, 5)
  posicao[0] = 0; // x
  posicao[1] = 0; // y
  posicao[2] = 5; // z

  direcao[0] = 0; // x
  direcao[1] = 0; // y
  direcao[2] = 0; // z
}

Camera::Camera(const GLdouble x, const GLdouble y, const GLdouble z){ // cria uma camera com uma posição predefinida
  posicao[0] = x;
  posicao[1] = y;
  posicao[2] = z;

  direcao[0] = 0;
  direcao[1] = 0;
  direcao[2] = 0;

  readData(); // tries read the data, if not possible, it will keep the default position
}

Camera::~Camera(){ // destrutor default
  saveData();
}

void Camera::setPosicao(const GLdouble x, const GLdouble y, const GLdouble z){
  posicao[0] = x;
  posicao[1] = y;
  posicao[2] = z;
}

void Camera::setDirecao(const GLdouble x, const GLdouble y, const GLdouble z){
  direcao[0] = x;
  direcao[1] = y;
  direcao[2] = z;
}

void Camera::setLookAt(){
  gluLookAt(posicao[0], posicao[1], posicao[2],
            direcao[0], direcao[1], direcao[2],
            0.0, 1.0, 0.0);
}