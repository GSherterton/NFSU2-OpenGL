#include "FrontBumper.h"

FrontBumper::FrontBumper(){}

FrontBumper::~FrontBumper(){}

void FrontBumper::drawBumper(){
  { // splines
    // glPointSize(4.0);
    glLineWidth(4.0); // line width
    glColor3ubv (car_lines_color); // paints the car

    // the x axle is the front-back direction, the y axle is the up-down direction and the z axle is the left-right direction
    // define the points of the down splines
    vector<array<array<GLfloat, 3>, 4>> down_ctrlpoints = {
      {{ // front right fender
        {front_bumper_begin_x                     , front_bumper_begin_y             , side_shift},
        {front_axle_shift+((float)0.79*new_radius), up_shift+((float)0.65*new_radius), side_shift},
        {front_axle_shift+(new_radius)            , up_shift+((float)0.43*new_radius), side_shift},
        {front_axle_shift+(new_radius)            , up_shift                         , side_shift},
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
        {front_axle_shift+(new_radius)            , up_shift                         , -side_shift},
        {front_axle_shift+(new_radius)            , up_shift+((float)0.43*new_radius), -side_shift},
        {front_axle_shift+((float)0.79*new_radius), up_shift+((float)0.65*new_radius), -side_shift},
        {front_bumper_begin_x                     , front_bumper_begin_y             , -side_shift},
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

  { // surfaces
    glLineWidth(4.0); // line width
    glColor3ubv (car_color); // paints the car

    // define the points of the surfaces
    vector<array<array<array<GLfloat, 3>, 4>, 4>> surface_ctrlpoints = {
      {{ // left side (down - up)
        {{ // frontside
          {front_axle_shift+(new_radius+front_bumper_shift), up_shift            , -side_shift},
          {front_axle_shift+(new_radius+front_bumper_shift), front_bumper_begin_y, -side_shift},
          {front_axle_shift+(new_radius+front_bumper_shift), up_shift            , -side_shift},
          {front_axle_shift+(new_radius+front_bumper_shift), front_bumper_begin_y, -side_shift},
        }},
        {{
          {front_axle_shift+(new_radius+front_bumper_shift), up_shift            , -side_shift},
          {front_axle_shift+(new_radius+front_bumper_shift), front_bumper_begin_y, -side_shift},
          {front_axle_shift+(new_radius+front_bumper_shift), up_shift            , -side_shift},
          {front_axle_shift+(new_radius+front_bumper_shift), front_bumper_begin_y, -side_shift},
        }},
        {{
          {front_axle_shift+(new_radius)            , up_shift                         , -side_shift},
          {front_axle_shift+(new_radius)            , up_shift+((float)0.43*new_radius), -side_shift},
          {front_axle_shift+((float)0.79*new_radius), up_shift+((float)0.65*new_radius), -side_shift},
          {front_bumper_begin_x                     , front_bumper_begin_y             , -side_shift},
        }},
        {{ // backside
          {front_axle_shift+(new_radius)            , up_shift                         , -side_shift},
          {front_axle_shift+(new_radius)            , up_shift+((float)0.43*new_radius), -side_shift},
          {front_axle_shift+((float)0.79*new_radius), up_shift+((float)0.65*new_radius), -side_shift},
          {front_bumper_begin_x                     , front_bumper_begin_y             , -side_shift},
        }},
        // {{ // example of curvated surface
        //   {-back_axle_shift+(tire_radius)    , car_roof     , side_shift},
        //   {-back_axle_shift+(tire_radius)+0.5, car_roof+0.05, side_shift},
        //   {windshield_shift-0.15             , car_roof+0.05, side_shift},
        //   {windshield_shift                  , car_roof     , side_shift},
        // }},
      }},
    
      {{ // right side (down - up)
        {{ // frontside
          {front_axle_shift+(new_radius+front_bumper_shift), up_shift            , side_shift},
          {front_axle_shift+(new_radius+front_bumper_shift), front_bumper_begin_y, side_shift},
          {front_axle_shift+(new_radius+front_bumper_shift), up_shift            , side_shift},
          {front_axle_shift+(new_radius+front_bumper_shift), front_bumper_begin_y, side_shift},
        }},
        {{
          {front_axle_shift+(new_radius+front_bumper_shift), up_shift            , side_shift},
          {front_axle_shift+(new_radius+front_bumper_shift), front_bumper_begin_y, side_shift},
          {front_axle_shift+(new_radius+front_bumper_shift), up_shift            , side_shift},
          {front_axle_shift+(new_radius+front_bumper_shift), front_bumper_begin_y, side_shift},
        }},
        {{
          {front_axle_shift+(new_radius)            , up_shift                         , side_shift},
          {front_axle_shift+(new_radius)            , up_shift+((float)0.43*new_radius), side_shift},
          {front_axle_shift+((float)0.79*new_radius), up_shift+((float)0.65*new_radius), side_shift},
          {front_bumper_begin_x                     , front_bumper_begin_y             , side_shift},
        }},
        {{ // backside
          {front_axle_shift+(new_radius)            , up_shift                         , side_shift},
          {front_axle_shift+(new_radius)            , up_shift+((float)0.43*new_radius), side_shift},
          {front_axle_shift+((float)0.79*new_radius), up_shift+((float)0.65*new_radius), side_shift},
          {front_bumper_begin_x                     , front_bumper_begin_y             , side_shift},
        }},
      }},

      {{ // front side (down - up)
        {{ // left side
          {front_axle_shift+(new_radius+front_bumper_shift), up_shift            , -side_shift},
          {front_axle_shift+(new_radius+front_bumper_shift), front_bumper_begin_y, -side_shift},
          {front_axle_shift+(new_radius+front_bumper_shift), up_shift            , -side_shift},
          {front_axle_shift+(new_radius+front_bumper_shift), front_bumper_begin_y, -side_shift},
        }},
        {{
          {front_axle_shift+(new_radius+front_bumper_shift), up_shift            , -side_shift},
          {front_axle_shift+(new_radius+front_bumper_shift), front_bumper_begin_y, -side_shift},
          {front_axle_shift+(new_radius+front_bumper_shift), up_shift            , -side_shift},
          {front_axle_shift+(new_radius+front_bumper_shift), front_bumper_begin_y, -side_shift},
        }},
        {{
          {front_axle_shift+(new_radius+front_bumper_shift), up_shift            , side_shift},
          {front_axle_shift+(new_radius+front_bumper_shift), front_bumper_begin_y, side_shift},
          {front_axle_shift+(new_radius+front_bumper_shift), up_shift            , side_shift},
          {front_axle_shift+(new_radius+front_bumper_shift), front_bumper_begin_y, side_shift},
        }},
        {{ // right side
          {front_axle_shift+(new_radius+front_bumper_shift), up_shift            , side_shift},
          {front_axle_shift+(new_radius+front_bumper_shift), front_bumper_begin_y, side_shift},
          {front_axle_shift+(new_radius+front_bumper_shift), up_shift            , side_shift},
          {front_axle_shift+(new_radius+front_bumper_shift), front_bumper_begin_y, side_shift},
        }},
      }},
    };

    for(int i = 0; i < surface_ctrlpoints.size(); i++){
      glMap2f(GL_MAP2_VERTEX_3, 0, 1, 3, 4,
            0, 1, 12, 4, &surface_ctrlpoints[i][0][0][0]);

      // glEvalMesh2(GL_LINE, 0, RESOLUTION, 0, RESOLUTION);
      glEvalMesh2(GL_FILL, 0, RESOLUTION, 0, RESOLUTION);
    }
  }
}