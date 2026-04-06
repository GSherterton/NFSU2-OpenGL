#include "Wheel.h"

Wheel::Wheel(float radius, float width){
  this->radius = radius;
  this->width = width;
  this->rotation_angle = 0;
}

Wheel::~Wheel(){
  gluDeleteQuadric(quad);
}

void Wheel::drawRim(){ // draw the wheel rim
  glColor3ub (80, 80, 80);

  glPushMatrix();
  glTranslated(0, 0, 0.3); // translate to the other side of the
  gluDisk(quad, 0, radius-0.05, 32, 2);
  glPopMatrix();

  glColor3ubv (rim_color); // paints the rim

  gluCylinder(quad, radius, radius, width, 32, 32);
  gluDisk(quad, 0, radius/3, 32, 2);

  GLfloat new_radius = 4*radius/9;
  GLfloat big = 0.08;
  GLfloat small = 0.06;

  vector<array<array<array<GLfloat, 3>, 4>, 4>> rim_ctrlpoints = {
    {{ // rim piece (left - right)
      {{ // top side
        {-new_radius, big  , 0},
        { new_radius, small, 0},
        {-new_radius, big  , 0},
        { new_radius, small, 0},
      }},
      {{
        {-new_radius, big  , 0},
        { new_radius, small, 0},
        {-new_radius, big  , 0},
        { new_radius, small, 0},
      }},
      {{
        {-new_radius, -big  , 0},
        { new_radius, -small, 0},
        {-new_radius, -big  , 0},
        { new_radius, -small, 0},
      }},
      {{ // bottom side
        {-new_radius, -big  , 0},
        { new_radius, -small, 0},
        {-new_radius, -big  , 0},
        { new_radius, -small, 0},
      }},
    }},
  };

  for(int j = 0; j < 6; j++){
    glPushMatrix();
    glRotatef(j*60, 0, 0, 1); // rotate to the next piece
    glTranslated(new_radius/2+radius/3, 0, 0.1);

    for(int i = 0; i < rim_ctrlpoints.size(); i++){
      glMap2f(GL_MAP2_VERTEX_3, 0, 1, 3, 4,
            0, 1, 12, 4, &rim_ctrlpoints[i][0][0][0]);

      // glEvalMesh2(GL_LINE, 0, RESOLUTION, 0, RESOLUTION);
      glEvalMesh2(GL_FILL, 0, RESOLUTION, 0, RESOLUTION);
    }

    glPopMatrix();
  }
}

void Wheel::drawTire(){
  glPushMatrix();

  glColor3ubv (tire_color); // paints the tire
  
  gluCylinder(quad, 0.7, 0.7, width, 32, 32);
  gluDisk(quad, radius, 0.7, 32, 2);
  glTranslated(0, 0, width); // translate to the other side of the tire
  gluDisk(quad, radius, 0.7, 32, 2);

  glPopMatrix();
}

void Wheel::drawWheel(){
  glPushMatrix();

  glTranslatef(0, 0.7, -width/2); // translate up the tire radius and width distance 
  glRotatef(rotation_angle, 0, 0, 1); // rotates based on the rotation angle

  drawRim();
  drawTire();

  glPopMatrix();
}

