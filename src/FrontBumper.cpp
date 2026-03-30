#include "FrontBumper.h"

FrontBumper::FrontBumper(){}

FrontBumper::~FrontBumper(){}

void FrontBumper::drawBumper(){
  // glPointSize(4.0);
  glLineWidth(8.0); // line width
  glColor3ubv (car_color); // paints the car

  // the x axle is the front-back direction, the y axle is the up-down direction and the z axle is the left-right direction
  // define the points of the down splines
  vector<array<array<GLfloat, 3>, 4>> down_ctrlpoints = {
    {{ // front right fender
      {front_bumper_begin_x             , front_bumper_begin_y             , side_shift},
      {front_bumper_begin_x+fender_shift, front_bumper_begin_y-fender_shift, side_shift},
      {front_axle_shift+(new_radius)    , up_shift+(new_radius/2)          , side_shift},
      {front_axle_shift+(new_radius)    , up_shift                         , side_shift},
    }},
    {{ // front bumper
      {front_axle_shift+(new_radius)                   , up_shift, side_shift},
      {front_axle_shift+(new_radius+front_bumper_shift), up_shift, side_shift},
      {front_axle_shift+(new_radius)                   , up_shift, side_shift},
      {front_axle_shift+(new_radius+front_bumper_shift), up_shift, side_shift},
    }},
    {{ // front bumper
      {front_axle_shift+(new_radius+front_bumper_shift), up_shift,  side_shift},
      {front_axle_shift+(new_radius+front_bumper_shift), up_shift, -side_shift},
      {front_axle_shift+(new_radius+front_bumper_shift), up_shift,  side_shift},
      {front_axle_shift+(new_radius+front_bumper_shift), up_shift, -side_shift},
    }},
    {{ // front bumper
      {front_axle_shift+(new_radius+front_bumper_shift), up_shift, -side_shift},
      {front_axle_shift+(new_radius)                   , up_shift, -side_shift},
      {front_axle_shift+(new_radius+front_bumper_shift), up_shift, -side_shift},
      {front_axle_shift+(new_radius)                   , up_shift, -side_shift},
    }},
    {{ // front left fender
      {front_axle_shift+(new_radius)    , up_shift                         , -side_shift},
      {front_axle_shift+(new_radius)    , up_shift+(new_radius/2)          , -side_shift},
      {front_bumper_begin_x+fender_shift, front_bumper_begin_y-fender_shift, -side_shift},
      {front_bumper_begin_x             , front_bumper_begin_y             , -side_shift},
    }},
  };

  for(int i = 0; i < down_ctrlpoints.size(); i++){
    glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 4, &down_ctrlpoints[i][0][0]);

    glBegin(GL_LINE_STRIP);
      for (int j = 0; j <= RESOLUTION; j++)
          glEvalCoord1f((GLfloat) float(j)/RESOLUTION);
    glEnd();
  }

  // define the points of the up splines
  vector<array<array<GLfloat, 3>, 4>> up_ctrlpoints = {
    {{ // front bumper
      {front_bumper_begin_x                            , front_bumper_begin_y, side_shift},
      {front_axle_shift+(new_radius+front_bumper_shift), front_bumper_begin_y, side_shift},
      {front_bumper_begin_x                            , front_bumper_begin_y, side_shift},
      {front_axle_shift+(new_radius+front_bumper_shift), front_bumper_begin_y, side_shift},
    }},
    {{ // front bumper
      {front_axle_shift+(new_radius+front_bumper_shift), front_bumper_begin_y, -side_shift},
      {front_axle_shift+(new_radius+front_bumper_shift), front_bumper_begin_y,  side_shift},
      {front_axle_shift+(new_radius+front_bumper_shift), front_bumper_begin_y, -side_shift},
      {front_axle_shift+(new_radius+front_bumper_shift), front_bumper_begin_y,  side_shift},
    }},
    {{ // front bumper
      {front_bumper_begin_x                            , front_bumper_begin_y, -side_shift},
      {front_axle_shift+(new_radius+front_bumper_shift), front_bumper_begin_y, -side_shift},
      {front_bumper_begin_x                            , front_bumper_begin_y, -side_shift},
      {front_axle_shift+(new_radius+front_bumper_shift), front_bumper_begin_y, -side_shift},
    }},
  };

  for(int i = 0; i < up_ctrlpoints.size(); i++){
    glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 4, &up_ctrlpoints[i][0][0]);

    glBegin(GL_LINE_STRIP);
      for (int j = 0; j <= RESOLUTION; j++)
          glEvalCoord1f((GLfloat) float(j)/RESOLUTION);
    glEnd();
  }

  // define the points of the linkin splines
  vector<array<array<GLfloat, 3>, 4>> link_ctrlpoints = {
    {{ // down - up bumper
      {front_axle_shift+(new_radius+front_bumper_shift), up_shift            , side_shift},
      {front_axle_shift+(new_radius+front_bumper_shift), front_bumper_begin_y, side_shift},
      {front_axle_shift+(new_radius+front_bumper_shift), up_shift            , side_shift},
      {front_axle_shift+(new_radius+front_bumper_shift), front_bumper_begin_y, side_shift},
    }},
    {{ // down - up bumper
      {front_axle_shift+(new_radius+front_bumper_shift), up_shift            , -side_shift},
      {front_axle_shift+(new_radius+front_bumper_shift), front_bumper_begin_y, -side_shift},
      {front_axle_shift+(new_radius+front_bumper_shift), up_shift            , -side_shift},
      {front_axle_shift+(new_radius+front_bumper_shift), front_bumper_begin_y, -side_shift},
    }},
  };

  for(int i = 0; i < link_ctrlpoints.size(); i++){
    glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 4, &link_ctrlpoints[i][0][0]);

    glBegin(GL_LINE_STRIP);
      for (int j = 0; j <= RESOLUTION; j++)
          glEvalCoord1f((GLfloat) float(j)/RESOLUTION);
    glEnd();
  }
}