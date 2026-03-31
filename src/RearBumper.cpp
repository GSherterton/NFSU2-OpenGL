#include "RearBumper.h"

RearBumper::RearBumper(){}

RearBumper::~RearBumper(){}

void RearBumper::drawBumper(){
  // glPointSize(4.0);
  glLineWidth(8.0); // line width
  glColor3ubv (car_color); // paints the car

  // the x axle is the front-back direction, the y axle is the up-down direction and the z axle is the left-right direction
  vector<array<array<GLfloat, 3>, 4>> down_ctrlpoints = {
    {{ // rear left fender
      {-rear_bumper_begin_x                    , rear_bumper_begin_y              , -side_shift},
      {-back_axle_shift-((float)0.7*new_radius), up_shift+((float)0.76*new_radius), -side_shift},
      {-back_axle_shift-(new_radius)           , up_shift+((float)0.5*new_radius) , -side_shift},
      {-back_axle_shift-(new_radius)           , up_shift                         , -side_shift},
    }},
    {{ // rear bumper
      {-back_axle_shift-(tire_radius+fender_shift)                  , up_shift                       , -side_shift},
      {-back_axle_shift-(tire_radius+fender_shift+rear_bumper_shift), up_shift+bumper_elevation_shift, -side_shift},
      {-back_axle_shift-(tire_radius+fender_shift)                  , up_shift                       , -side_shift},
      {-back_axle_shift-(tire_radius+fender_shift+rear_bumper_shift), up_shift+bumper_elevation_shift, -side_shift},
    }},
    {{ // rear bumper
      {-back_axle_shift-(tire_radius+fender_shift+rear_bumper_shift), up_shift+bumper_elevation_shift, -side_shift},
      {-back_axle_shift-(tire_radius+fender_shift+rear_bumper_shift), up_shift+bumper_elevation_shift,  side_shift},
      {-back_axle_shift-(tire_radius+fender_shift+rear_bumper_shift), up_shift+bumper_elevation_shift, -side_shift},
      {-back_axle_shift-(tire_radius+fender_shift+rear_bumper_shift), up_shift+bumper_elevation_shift,  side_shift},
    }},
    {{ // rear bumper
      {-back_axle_shift-(tire_radius+fender_shift+rear_bumper_shift), up_shift+bumper_elevation_shift, side_shift},
      {-back_axle_shift-(tire_radius+fender_shift)                  , up_shift                       , side_shift},
      {-back_axle_shift-(tire_radius+fender_shift+rear_bumper_shift), up_shift+bumper_elevation_shift, side_shift},
      {-back_axle_shift-(tire_radius+fender_shift)                  , up_shift                       , side_shift},
    }},
    {{ // rear right fender
      {-back_axle_shift-(new_radius)           , up_shift                         , side_shift},
      {-back_axle_shift-(new_radius)           , up_shift+((float)0.5*new_radius) , side_shift},
      {-back_axle_shift-((float)0.7*new_radius), up_shift+((float)0.76*new_radius), side_shift},
      {-rear_bumper_begin_x                    , rear_bumper_begin_y              , side_shift},
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
    {{ // rear bumper
      {-rear_bumper_begin_x                           , rear_bumper_begin_y, -side_shift},
      {-back_axle_shift-(new_radius+rear_bumper_shift), rear_bumper_begin_y, -side_shift},
      {-rear_bumper_begin_x                           , rear_bumper_begin_y, -side_shift},
      {-back_axle_shift-(new_radius+rear_bumper_shift), rear_bumper_begin_y, -side_shift},
    }},
    {{ // rear bumper
      {-back_axle_shift-(new_radius+rear_bumper_shift), rear_bumper_begin_y, -side_shift},
      {-back_axle_shift-(new_radius+rear_bumper_shift), rear_bumper_begin_y,  side_shift},
      {-back_axle_shift-(new_radius+rear_bumper_shift), rear_bumper_begin_y, -side_shift},
      {-back_axle_shift-(new_radius+rear_bumper_shift), rear_bumper_begin_y,  side_shift},
    }},
    {{ // rear bumper
      {-back_axle_shift-(new_radius+rear_bumper_shift), rear_bumper_begin_y, side_shift},
      {-rear_bumper_begin_x                           , rear_bumper_begin_y, side_shift},
      {-back_axle_shift-(new_radius+rear_bumper_shift), rear_bumper_begin_y, side_shift},
      {-rear_bumper_begin_x                           , rear_bumper_begin_y, side_shift},
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
      {-back_axle_shift-(tire_radius+fender_shift+rear_bumper_shift), up_shift+bumper_elevation_shift, -side_shift},
      {-back_axle_shift-(tire_radius+fender_shift+rear_bumper_shift), rear_bumper_begin_y            , -side_shift},
      {-back_axle_shift-(tire_radius+fender_shift+rear_bumper_shift), up_shift+bumper_elevation_shift, -side_shift},
      {-back_axle_shift-(tire_radius+fender_shift+rear_bumper_shift), rear_bumper_begin_y            , -side_shift},
    }},
    {{ // down - up bumper
      {-back_axle_shift-(tire_radius+fender_shift+rear_bumper_shift), up_shift+bumper_elevation_shift, side_shift},
      {-back_axle_shift-(tire_radius+fender_shift+rear_bumper_shift), rear_bumper_begin_y            , side_shift},
      {-back_axle_shift-(tire_radius+fender_shift+rear_bumper_shift), up_shift+bumper_elevation_shift, side_shift},
      {-back_axle_shift-(tire_radius+fender_shift+rear_bumper_shift), rear_bumper_begin_y            , side_shift},
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