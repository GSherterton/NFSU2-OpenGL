#include "Chassis.h"

Chassis::Chassis(){}

Chassis::~Chassis(){}

void Chassis::drawChassis(){
  { // splines
    // glPointSize(4.0);
    glLineWidth(4.0); // line width
    glColor3ubv (car_lines_color); // paints the car

    // the x axle is the front-back direction, the y axle is the up-down direction and the z axle is the left-right direction
    // define the points of the down splines
    vector<array<array<GLfloat, 3>, 4>> down_ctrlpoints = {
      {{ // rear left fender
        {-back_axle_shift+(tire_radius+fender_shift)                         , up_shift                        , -side_shift},
        {-back_axle_shift+(tire_radius+fender_shift)                         , up_shift+((float)0.8*new_radius), -side_shift},
        {-back_axle_shift+(tire_radius+fender_shift)-((float)0.86*new_radius), up_shift+((float)1.2*new_radius), -side_shift},
        {-rear_bumper_begin_x                                                , rear_bumper_begin_y             , -side_shift},
      }},
      {{ // rear bumper
        {-back_axle_shift-(tire_radius+fender_shift)                  , rear_bumper_begin_y                       , -side_shift},
        {-back_axle_shift-(tire_radius+fender_shift+rear_bumper_shift), rear_bumper_begin_y, -side_shift},
        {-back_axle_shift-(tire_radius+fender_shift)                  , rear_bumper_begin_y             , -side_shift},
        {-back_axle_shift-(tire_radius+fender_shift+rear_bumper_shift), rear_bumper_begin_y, -side_shift},
      }},
      {{ // rear bumper
        {-back_axle_shift-(tire_radius+fender_shift+rear_bumper_shift), rear_bumper_begin_y, -side_shift},
        {-back_axle_shift-(tire_radius+fender_shift+rear_bumper_shift), rear_bumper_begin_y,  side_shift},
        {-back_axle_shift-(tire_radius+fender_shift+rear_bumper_shift), rear_bumper_begin_y, -side_shift},
        {-back_axle_shift-(tire_radius+fender_shift+rear_bumper_shift), rear_bumper_begin_y,  side_shift},
      }},
      {{ // rear bumper
        {-back_axle_shift-(tire_radius+fender_shift+rear_bumper_shift), rear_bumper_begin_y, side_shift},
        {-back_axle_shift-(tire_radius+fender_shift)                  , rear_bumper_begin_y                       , side_shift},
        {-back_axle_shift-(tire_radius+fender_shift+rear_bumper_shift), rear_bumper_begin_y, side_shift},
        {-back_axle_shift-(tire_radius+fender_shift)                  , rear_bumper_begin_y                       , side_shift},
      }},
      {{ // rear right fender
        {-rear_bumper_begin_x                                                , rear_bumper_begin_y             , side_shift},
        {-back_axle_shift+(tire_radius+fender_shift)-((float)0.86*new_radius), up_shift+((float)1.2*new_radius), side_shift},
        {-back_axle_shift+(tire_radius+fender_shift)                         , up_shift+((float)0.8*new_radius), side_shift},
        {-back_axle_shift+(tire_radius+fender_shift)                         , up_shift                        , side_shift},
      }},
      {{ // right side skirt
        {-back_axle_shift+(tire_radius+fender_shift), up_shift, side_shift},
        {front_axle_shift-(tire_radius+fender_shift), up_shift, side_shift},
        {-back_axle_shift+(tire_radius+fender_shift), up_shift, side_shift},
        {front_axle_shift-(tire_radius+fender_shift), up_shift, side_shift},
      }},
      {{ // front right fender
        {front_axle_shift-(tire_radius+fender_shift)                         , up_shift                         , side_shift},
        {front_axle_shift-(tire_radius+fender_shift)                         , up_shift+(new_radius)            , side_shift},
        {front_axle_shift-(tire_radius+fender_shift)+((float)1.14*new_radius), up_shift+((float)1.26*new_radius), side_shift},
        {front_bumper_begin_x                                                , front_bumper_begin_y             , side_shift},
      }},
      {{ // front bumper
        {front_bumper_begin_x                                          , front_bumper_begin_y, side_shift},
        {front_axle_shift+(tire_radius+fender_shift+front_bumper_shift), front_bumper_begin_y, side_shift},
        {front_bumper_begin_x                                          , front_bumper_begin_y, side_shift},
        {front_axle_shift+(tire_radius+fender_shift+front_bumper_shift), front_bumper_begin_y, side_shift},
      }},
      {{ // front bumper
        {front_axle_shift+(tire_radius+fender_shift+front_bumper_shift), front_bumper_begin_y,  side_shift},
        {front_axle_shift+(tire_radius+fender_shift+front_bumper_shift), front_bumper_begin_y, -side_shift},
        {front_axle_shift+(tire_radius+fender_shift+front_bumper_shift), front_bumper_begin_y,  side_shift},
        {front_axle_shift+(tire_radius+fender_shift+front_bumper_shift), front_bumper_begin_y, -side_shift},
      }},
      {{ // front bumper
        {front_bumper_begin_x                                          , front_bumper_begin_y, -side_shift},
        {front_axle_shift+(tire_radius+fender_shift+front_bumper_shift), front_bumper_begin_y, -side_shift},
        {front_bumper_begin_x                                          , front_bumper_begin_y, -side_shift},
        {front_axle_shift+(tire_radius+fender_shift+front_bumper_shift), front_bumper_begin_y, -side_shift},
      }},
      {{ // front left fender
        {front_bumper_begin_x                                                , front_bumper_begin_y             , -side_shift},
        {front_axle_shift-(tire_radius+fender_shift)+((float)1.14*new_radius), up_shift+((float)1.26*new_radius), -side_shift},
        {front_axle_shift-(tire_radius+fender_shift)                         , up_shift+(new_radius)            , -side_shift},
        {front_axle_shift-(tire_radius+fender_shift)                         , up_shift                         , -side_shift},
      }},
      {{ //right side skirt
        {front_axle_shift-(tire_radius+fender_shift), up_shift, -side_shift},
        {-back_axle_shift+(tire_radius+fender_shift), up_shift, -side_shift},
        {front_axle_shift-(tire_radius+fender_shift), up_shift, -side_shift},
        {-back_axle_shift+(tire_radius+fender_shift), up_shift, -side_shift},
      }},
    };

    for(int i = 0; i < down_ctrlpoints.size(); i++){
      glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 4, &down_ctrlpoints[i][0][0]);

      glBegin(GL_LINE_STRIP);
        for (int j = 0; j <= RESOLUTION; j++)
            glEvalCoord1f((GLfloat) float(j)/RESOLUTION);
      glEnd();
    }

    vector<array<array<GLfloat, 3>, 4>> up_ctrlpoints = {
      {{ // rear left chassis top
        {-back_axle_shift+(tire_radius)             , car_roof       , -side_shift},
        {-back_axle_shift-(tire_radius+fender_shift), car_rear_bumper, -side_shift},
        {-back_axle_shift+(tire_radius)             , car_roof       , -side_shift},
        {-back_axle_shift-(tire_radius+fender_shift), car_rear_bumper, -side_shift},
      }},
      {{ // trunk
        {-back_axle_shift-(tire_radius+fender_shift)                  , car_rear_bumper, -side_shift},
        {-back_axle_shift-(tire_radius+fender_shift+rear_bumper_shift), car_rear_bumper, -side_shift},
        {-back_axle_shift-(tire_radius+fender_shift)                  , car_rear_bumper, -side_shift},
        {-back_axle_shift-(tire_radius+fender_shift+rear_bumper_shift), car_rear_bumper, -side_shift},
      }},
      {{ // trunk
        {-back_axle_shift-(tire_radius+fender_shift+rear_bumper_shift), car_rear_bumper, -side_shift},
        {-back_axle_shift-(tire_radius+fender_shift+rear_bumper_shift), car_rear_bumper,  side_shift},
        {-back_axle_shift-(tire_radius+fender_shift+rear_bumper_shift), car_rear_bumper, -side_shift},
        {-back_axle_shift-(tire_radius+fender_shift+rear_bumper_shift), car_rear_bumper,  side_shift},
      }},
      {{ // trunk
        {-back_axle_shift-(tire_radius+fender_shift)                  , car_rear_bumper, side_shift},
        {-back_axle_shift-(tire_radius+fender_shift+rear_bumper_shift), car_rear_bumper, side_shift},
        {-back_axle_shift-(tire_radius+fender_shift)                  , car_rear_bumper, side_shift},
        {-back_axle_shift-(tire_radius+fender_shift+rear_bumper_shift), car_rear_bumper, side_shift},
      }},
      {{ // rear right chassis top
        {-back_axle_shift-(tire_radius+fender_shift), car_rear_bumper, side_shift},
        {-back_axle_shift+(tire_radius)             , car_roof       , side_shift},
        {-back_axle_shift-(tire_radius+fender_shift), car_rear_bumper, side_shift},
        {-back_axle_shift+(tire_radius)             , car_roof       , side_shift},
      }},
      {{ // right side chassis top
        {-back_axle_shift+(tire_radius), car_roof, side_shift},
        {windshield_shift              , car_roof, side_shift},
        {-back_axle_shift+(tire_radius), car_roof, side_shift},
        {windshield_shift              , car_roof, side_shift},
      }},
      {{ // front right chassis top
        {windshield_shift                           , car_roof, side_shift},
        {front_axle_shift-(tire_radius+fender_shift), car_hood, side_shift},
        {windshield_shift                           , car_roof, side_shift},
        {front_axle_shift-(tire_radius+fender_shift), car_hood, side_shift},
      }},
      {{ // hood
        {front_axle_shift-(tire_radius+fender_shift)                   , car_hood, side_shift},
        {front_axle_shift+(tire_radius+fender_shift+front_bumper_shift), car_front_bumper, side_shift},
        {front_axle_shift-(tire_radius+fender_shift)                   , car_hood, side_shift},
        {front_axle_shift+(tire_radius+fender_shift+front_bumper_shift), car_front_bumper, side_shift},
      }},
      {{ // hood
        {front_axle_shift+(tire_radius+fender_shift+front_bumper_shift), car_front_bumper,  side_shift},
        {front_axle_shift+(tire_radius+fender_shift+front_bumper_shift), car_front_bumper, -side_shift},
        {front_axle_shift+(tire_radius+fender_shift+front_bumper_shift), car_front_bumper,  side_shift},
        {front_axle_shift+(tire_radius+fender_shift+front_bumper_shift), car_front_bumper, -side_shift},
      }},
      {{ // hood
        {front_axle_shift+(tire_radius+fender_shift+front_bumper_shift), car_front_bumper, -side_shift},
        {front_axle_shift-(tire_radius+fender_shift)                   , car_hood, -side_shift},
        {front_axle_shift+(tire_radius+fender_shift+front_bumper_shift), car_front_bumper, -side_shift},
        {front_axle_shift-(tire_radius+fender_shift)                   , car_hood, -side_shift},
      }},
      {{ // front left chassis top
        {front_axle_shift-(tire_radius+fender_shift), car_hood, -side_shift},
        {windshield_shift                           , car_roof, -side_shift},
        {front_axle_shift-(tire_radius+fender_shift), car_hood, -side_shift},
        {windshield_shift                           , car_roof, -side_shift},
      }},
      {{ // left side chassis top
        {windshield_shift                           , car_roof, -side_shift},
        {-back_axle_shift+(tire_radius)             , car_roof, -side_shift},
        {windshield_shift                           , car_roof, -side_shift},
        {-back_axle_shift+(tire_radius)             , car_roof, -side_shift},
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
      {{ // down - up trunk
        {-back_axle_shift-(tire_radius+fender_shift+rear_bumper_shift), rear_bumper_begin_y, -side_shift},
        {-back_axle_shift-(tire_radius+fender_shift+rear_bumper_shift), car_rear_bumper    , -side_shift},
        {-back_axle_shift-(tire_radius+fender_shift+rear_bumper_shift), rear_bumper_begin_y, -side_shift},
        {-back_axle_shift-(tire_radius+fender_shift+rear_bumper_shift), car_rear_bumper    , -side_shift},
      }},
      {{ // down - up trunk
        {-back_axle_shift-(tire_radius+fender_shift+rear_bumper_shift), rear_bumper_begin_y, side_shift},
        {-back_axle_shift-(tire_radius+fender_shift+rear_bumper_shift), car_rear_bumper                       , side_shift},
        {-back_axle_shift-(tire_radius+fender_shift+rear_bumper_shift), rear_bumper_begin_y, side_shift},
        {-back_axle_shift-(tire_radius+fender_shift+rear_bumper_shift), car_rear_bumper                       , side_shift},
      }},
      {{ // rear chassis top
        {-back_axle_shift+(tire_radius), car_roof, side_shift},
        {-back_axle_shift+(tire_radius), car_roof, -side_shift},
        {-back_axle_shift+(tire_radius), car_roof, side_shift},
        {-back_axle_shift+(tire_radius), car_roof, -side_shift},
      }},
      {{ // front chassis top
        {windshield_shift, car_roof, side_shift},
        {windshield_shift, car_roof, -side_shift},
        {windshield_shift, car_roof, side_shift},
        {windshield_shift, car_roof, -side_shift},
      }},
      {{ // windshield
        {front_axle_shift-(tire_radius+fender_shift), car_hood, side_shift},
        {front_axle_shift-(tire_radius+fender_shift), car_hood, -side_shift},
        {front_axle_shift-(tire_radius+fender_shift), car_hood, side_shift},
        {front_axle_shift-(tire_radius+fender_shift), car_hood, -side_shift},
      }},
      {{ // down - up hood
        {front_axle_shift+(tire_radius+fender_shift+front_bumper_shift), front_bumper_begin_y, side_shift},
        {front_axle_shift+(tire_radius+fender_shift+front_bumper_shift), car_front_bumper    , side_shift},
        {front_axle_shift+(tire_radius+fender_shift+front_bumper_shift), front_bumper_begin_y, side_shift},
        {front_axle_shift+(tire_radius+fender_shift+front_bumper_shift), car_front_bumper    , side_shift},
      }},
      {{ // down - up hood
        {front_axle_shift+(tire_radius+fender_shift+front_bumper_shift), front_bumper_begin_y, -side_shift},
        {front_axle_shift+(tire_radius+fender_shift+front_bumper_shift), car_front_bumper    , -side_shift},
        {front_axle_shift+(tire_radius+fender_shift+front_bumper_shift), front_bumper_begin_y, -side_shift},
        {front_axle_shift+(tire_radius+fender_shift+front_bumper_shift), car_front_bumper    , -side_shift},
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
      {{ // roof (back - front)
        {{ 
          {-back_axle_shift+(tire_radius), car_roof, -side_shift},
          {windshield_shift              , car_roof, -side_shift},
          {-back_axle_shift+(tire_radius), car_roof, -side_shift},
          {windshield_shift              , car_roof, -side_shift},
        }},
        {{
          {-back_axle_shift+(tire_radius), car_roof, -side_shift/2},
          {windshield_shift              , car_roof, -side_shift/2},
          {-back_axle_shift+(tire_radius), car_roof, -side_shift/2},
          {windshield_shift              , car_roof, -side_shift/2},
        }},
        {{
          {-back_axle_shift+(tire_radius), car_roof, side_shift/2},
          {windshield_shift              , car_roof, side_shift/2},
          {-back_axle_shift+(tire_radius), car_roof, side_shift/2},
          {windshield_shift              , car_roof, side_shift/2},
        }},
        {{
          {-back_axle_shift+(tire_radius), car_roof, side_shift},
          {windshield_shift              , car_roof, side_shift},
          {-back_axle_shift+(tire_radius), car_roof, side_shift},
          {windshield_shift              , car_roof, side_shift},
        }},
        // {{ // example of curvated surface
        //   {-back_axle_shift+(tire_radius)    , car_roof     , side_shift},
        //   {-back_axle_shift+(tire_radius)+0.5, car_roof+0.05, side_shift},
        //   {windshield_shift-0.15             , car_roof+0.05, side_shift},
        //   {windshield_shift                  , car_roof     , side_shift},
        // }},
      }},
      {{ // trunk top (back - front)
        {{ // left side
          {-back_axle_shift-(tire_radius+fender_shift)                  , car_rear_bumper, -side_shift},
          {-back_axle_shift-(tire_radius+fender_shift+rear_bumper_shift), car_rear_bumper, -side_shift},
          {-back_axle_shift-(tire_radius+fender_shift)                  , car_rear_bumper, -side_shift},
          {-back_axle_shift-(tire_radius+fender_shift+rear_bumper_shift), car_rear_bumper, -side_shift},
        }},
        {{
          {-back_axle_shift-(tire_radius+fender_shift)                  , car_rear_bumper, -side_shift/2},
          {-back_axle_shift-(tire_radius+fender_shift+rear_bumper_shift), car_rear_bumper, -side_shift/2},
          {-back_axle_shift-(tire_radius+fender_shift)                  , car_rear_bumper, -side_shift/2},
          {-back_axle_shift-(tire_radius+fender_shift+rear_bumper_shift), car_rear_bumper, -side_shift/2},
        }},
        {{
          {-back_axle_shift-(tire_radius+fender_shift)                  , car_rear_bumper, side_shift/2},
          {-back_axle_shift-(tire_radius+fender_shift+rear_bumper_shift), car_rear_bumper, side_shift/2},
          {-back_axle_shift-(tire_radius+fender_shift)                  , car_rear_bumper, side_shift/2},
          {-back_axle_shift-(tire_radius+fender_shift+rear_bumper_shift), car_rear_bumper, side_shift/2},
        }},
        {{ // right side
          {-back_axle_shift-(tire_radius+fender_shift)                  , car_rear_bumper, side_shift},
          {-back_axle_shift-(tire_radius+fender_shift+rear_bumper_shift), car_rear_bumper, side_shift},
          {-back_axle_shift-(tire_radius+fender_shift)                  , car_rear_bumper, side_shift},
          {-back_axle_shift-(tire_radius+fender_shift+rear_bumper_shift), car_rear_bumper, side_shift},
        }},
      }},
      {{ // trunk back (down - up)
        {{ // left side
          {-back_axle_shift-(tire_radius+fender_shift+rear_bumper_shift), rear_bumper_begin_y, -side_shift},
          {-back_axle_shift-(tire_radius+fender_shift+rear_bumper_shift), car_rear_bumper    , -side_shift},
          {-back_axle_shift-(tire_radius+fender_shift+rear_bumper_shift), rear_bumper_begin_y, -side_shift},
          {-back_axle_shift-(tire_radius+fender_shift+rear_bumper_shift), car_rear_bumper    , -side_shift},
        }},
        {{
          {-back_axle_shift-(tire_radius+fender_shift+rear_bumper_shift), rear_bumper_begin_y, -side_shift/2},
          {-back_axle_shift-(tire_radius+fender_shift+rear_bumper_shift), car_rear_bumper    , -side_shift/2},
          {-back_axle_shift-(tire_radius+fender_shift+rear_bumper_shift), rear_bumper_begin_y, -side_shift/2},
          {-back_axle_shift-(tire_radius+fender_shift+rear_bumper_shift), car_rear_bumper    , -side_shift/2},
        }},
        {{
          {-back_axle_shift-(tire_radius+fender_shift+rear_bumper_shift), rear_bumper_begin_y, side_shift/2},
          {-back_axle_shift-(tire_radius+fender_shift+rear_bumper_shift), car_rear_bumper    , side_shift/2},
          {-back_axle_shift-(tire_radius+fender_shift+rear_bumper_shift), rear_bumper_begin_y, side_shift/2},
          {-back_axle_shift-(tire_radius+fender_shift+rear_bumper_shift), car_rear_bumper    , side_shift/2},
        }},
        {{ // right side
          {-back_axle_shift-(tire_radius+fender_shift+rear_bumper_shift), rear_bumper_begin_y, side_shift},
          {-back_axle_shift-(tire_radius+fender_shift+rear_bumper_shift), car_rear_bumper    , side_shift},
          {-back_axle_shift-(tire_radius+fender_shift+rear_bumper_shift), rear_bumper_begin_y, side_shift},
          {-back_axle_shift-(tire_radius+fender_shift+rear_bumper_shift), car_rear_bumper    , side_shift},
        }},
      }},
      {{ // hood (back - front)
        {{ // left side
          {front_axle_shift-(tire_radius+fender_shift)                   , car_hood        , -side_shift},
          {front_axle_shift+(tire_radius+fender_shift+front_bumper_shift), car_front_bumper, -side_shift},
          {front_axle_shift-(tire_radius+fender_shift)                   , car_hood        , -side_shift},
          {front_axle_shift+(tire_radius+fender_shift+front_bumper_shift), car_front_bumper, -side_shift},
        }},
        {{
          {front_axle_shift-(tire_radius+fender_shift)                   , car_hood        , -side_shift/2},
          {front_axle_shift+(tire_radius+fender_shift+front_bumper_shift), car_front_bumper, -side_shift/2},
          {front_axle_shift-(tire_radius+fender_shift)                   , car_hood        , -side_shift/2},
          {front_axle_shift+(tire_radius+fender_shift+front_bumper_shift), car_front_bumper, -side_shift/2},
        }},
        {{
          {front_axle_shift-(tire_radius+fender_shift)                   , car_hood        , side_shift/2},
          {front_axle_shift+(tire_radius+fender_shift+front_bumper_shift), car_front_bumper, side_shift/2},
          {front_axle_shift-(tire_radius+fender_shift)                   , car_hood        , side_shift/2},
          {front_axle_shift+(tire_radius+fender_shift+front_bumper_shift), car_front_bumper, side_shift/2},
        }},
        {{ // right side
          {front_axle_shift-(tire_radius+fender_shift)                   , car_hood        , side_shift},
          {front_axle_shift+(tire_radius+fender_shift+front_bumper_shift), car_front_bumper, side_shift},
          {front_axle_shift-(tire_radius+fender_shift)                   , car_hood        , side_shift},
          {front_axle_shift+(tire_radius+fender_shift+front_bumper_shift), car_front_bumper, side_shift},
        }},
      }},
      {{ // front (down - up)
        {{ // left side
          {front_axle_shift+(tire_radius+fender_shift+front_bumper_shift), front_bumper_begin_y, -side_shift},
          {front_axle_shift+(tire_radius+fender_shift+front_bumper_shift), car_front_bumper    , -side_shift},
          {front_axle_shift+(tire_radius+fender_shift+front_bumper_shift), front_bumper_begin_y, -side_shift},
          {front_axle_shift+(tire_radius+fender_shift+front_bumper_shift), car_front_bumper    , -side_shift},
        }},
        {{
          {front_axle_shift+(tire_radius+fender_shift+front_bumper_shift), front_bumper_begin_y, -side_shift/2},
          {front_axle_shift+(tire_radius+fender_shift+front_bumper_shift), car_front_bumper    , -side_shift/2},
          {front_axle_shift+(tire_radius+fender_shift+front_bumper_shift), front_bumper_begin_y, -side_shift/2},
          {front_axle_shift+(tire_radius+fender_shift+front_bumper_shift), car_front_bumper    , -side_shift/2},
        }},
        {{
          {front_axle_shift+(tire_radius+fender_shift+front_bumper_shift), front_bumper_begin_y, side_shift/2},
          {front_axle_shift+(tire_radius+fender_shift+front_bumper_shift), car_front_bumper    , side_shift/2},
          {front_axle_shift+(tire_radius+fender_shift+front_bumper_shift), front_bumper_begin_y, side_shift/2},
          {front_axle_shift+(tire_radius+fender_shift+front_bumper_shift), car_front_bumper    , side_shift/2},
        }},
        {{ // right side
          {front_axle_shift+(tire_radius+fender_shift+front_bumper_shift), front_bumper_begin_y, side_shift},
          {front_axle_shift+(tire_radius+fender_shift+front_bumper_shift), car_front_bumper    , side_shift},
          {front_axle_shift+(tire_radius+fender_shift+front_bumper_shift), front_bumper_begin_y, side_shift},
          {front_axle_shift+(tire_radius+fender_shift+front_bumper_shift), car_front_bumper    , side_shift},
        }},
      }},
      
      {{ // rear left side 1 (down - up)
        {{ // frontside
          {-back_line_shift, up_shift, -side_shift},
          {-back_line_shift, car_roof, -side_shift},
          {-back_line_shift, up_shift, -side_shift},
          {-back_line_shift, car_roof, -side_shift},
        }},
        {{
          {-back_line_shift, up_shift, -side_shift},
          {-back_line_shift, car_roof, -side_shift},
          {-back_line_shift, up_shift, -side_shift},
          {-back_line_shift, car_roof, -side_shift},
        }},
        {{
          {-back_axle_shift+(tire_radius+fender_shift), up_shift, -side_shift},
          {-back_axle_shift+(tire_radius+fender_shift), car_roof, -side_shift},
          {-back_axle_shift+(tire_radius+fender_shift), up_shift, -side_shift},
          {-back_axle_shift+(tire_radius+fender_shift), car_roof, -side_shift},
        }},
        {{ // backside
          {-back_axle_shift+(tire_radius+fender_shift), up_shift, -side_shift},
          {-back_axle_shift+(tire_radius+fender_shift), car_roof, -side_shift},
          {-back_axle_shift+(tire_radius+fender_shift), up_shift, -side_shift},
          {-back_axle_shift+(tire_radius)             , car_roof, -side_shift},
        }},
      }},
      {{ // rear left side 2 (down - up)
        {{ // frontside
          {-back_axle_shift+(tire_radius+fender_shift), up_shift, -side_shift},
          {-back_axle_shift+(tire_radius+fender_shift), car_roof, -side_shift},
          {-back_axle_shift+(tire_radius+fender_shift), up_shift, -side_shift},
          {-back_axle_shift+(tire_radius)             , car_roof, -side_shift},
        }},
        {{
          {-back_axle_shift+(tire_radius+fender_shift), up_shift+((float)0.8*new_radius), -side_shift},
          {-back_axle_shift-(tire_radius+fender_shift), car_rear_bumper                 , -side_shift},
          {-back_axle_shift+(tire_radius+fender_shift), up_shift+((float)0.8*new_radius), -side_shift},
          {-back_axle_shift-(tire_radius+fender_shift), car_rear_bumper                 , -side_shift},
        }},
        {{
          {-back_axle_shift+(tire_radius+fender_shift)-((float)0.86*new_radius), up_shift+((float)1.2*new_radius), -side_shift},
          {-back_axle_shift+(tire_radius)                                      , car_roof                        , -side_shift},
          {-back_axle_shift+(tire_radius+fender_shift)-((float)0.86*new_radius), up_shift+((float)1.2*new_radius), -side_shift},
          {-back_axle_shift+(tire_radius)                                      , car_roof                        , -side_shift},
        }},
        {{ // backside
          {-rear_bumper_begin_x                       , rear_bumper_begin_y, -side_shift},
          {-back_axle_shift-(tire_radius+fender_shift), car_rear_bumper    , -side_shift},
          {-rear_bumper_begin_x                       , rear_bumper_begin_y, -side_shift},
          {-back_axle_shift-(tire_radius+fender_shift), car_rear_bumper    , -side_shift},
        }},
      }},
      {{ // rear left side 3 (down - up)
        {{ // frontside
          {-rear_bumper_begin_x                       , rear_bumper_begin_y, -side_shift},
          {-back_axle_shift-(tire_radius+fender_shift), car_rear_bumper    , -side_shift},
          {-rear_bumper_begin_x                       , rear_bumper_begin_y, -side_shift},
          {-back_axle_shift-(tire_radius+fender_shift), car_rear_bumper    , -side_shift},
        }},
        {{
          {-back_axle_shift-(tire_radius+fender_shift+rear_bumper_shift), rear_bumper_begin_y, -side_shift},
          {-back_axle_shift-(tire_radius+fender_shift+rear_bumper_shift), car_rear_bumper    , -side_shift},
          {-back_axle_shift-(tire_radius+fender_shift+rear_bumper_shift), rear_bumper_begin_y, -side_shift},
          {-back_axle_shift-(tire_radius+fender_shift+rear_bumper_shift), car_rear_bumper    , -side_shift},
        }},
        {{
          {-rear_bumper_begin_x                       , rear_bumper_begin_y, -side_shift},
          {-back_axle_shift-(tire_radius+fender_shift), car_rear_bumper    , -side_shift},
          {-rear_bumper_begin_x                       , rear_bumper_begin_y, -side_shift},
          {-back_axle_shift-(tire_radius+fender_shift), car_rear_bumper    , -side_shift},
        }},
        {{ // backside
          {-back_axle_shift-(tire_radius+fender_shift+rear_bumper_shift), rear_bumper_begin_y, -side_shift},
          {-back_axle_shift-(tire_radius+fender_shift+rear_bumper_shift), car_rear_bumper    , -side_shift},
          {-back_axle_shift-(tire_radius+fender_shift+rear_bumper_shift), rear_bumper_begin_y, -side_shift},
          {-back_axle_shift-(tire_radius+fender_shift+rear_bumper_shift), car_rear_bumper    , -side_shift},
        }},
      }},
      
      {{ // rear right side 1 (down - up)
        {{ // frontside
          {-back_line_shift, up_shift, side_shift},
          {-back_line_shift, car_roof, side_shift},
          {-back_line_shift, up_shift, side_shift},
          {-back_line_shift, car_roof, side_shift},
        }},
        {{
          {-back_line_shift, up_shift, side_shift},
          {-back_line_shift, car_roof, side_shift},
          {-back_line_shift, up_shift, side_shift},
          {-back_line_shift, car_roof, side_shift},
        }},
        {{
          {-back_axle_shift+(tire_radius+fender_shift), up_shift, side_shift},
          {-back_axle_shift+(tire_radius+fender_shift), car_roof, side_shift},
          {-back_axle_shift+(tire_radius+fender_shift), up_shift, side_shift},
          {-back_axle_shift+(tire_radius+fender_shift), car_roof, side_shift},
        }},
        {{ // backside
          {-back_axle_shift+(tire_radius+fender_shift), up_shift, side_shift},
          {-back_axle_shift+(tire_radius+fender_shift), car_roof, side_shift},
          {-back_axle_shift+(tire_radius+fender_shift), up_shift, side_shift},
          {-back_axle_shift+(tire_radius)             , car_roof, side_shift},
        }},
      }},
      {{ // rear right side 2 (down - up)
        {{ // frontside
          {-back_axle_shift+(tire_radius+fender_shift), up_shift, side_shift},
          {-back_axle_shift+(tire_radius+fender_shift), car_roof, side_shift},
          {-back_axle_shift+(tire_radius+fender_shift), up_shift, side_shift},
          {-back_axle_shift+(tire_radius)             , car_roof, side_shift},
        }},
        {{
          {-back_axle_shift+(tire_radius+fender_shift), up_shift+((float)0.8*new_radius), side_shift},
          {-back_axle_shift-(tire_radius+fender_shift), car_rear_bumper                 , side_shift},
          {-back_axle_shift+(tire_radius+fender_shift), up_shift+((float)0.8*new_radius), side_shift},
          {-back_axle_shift-(tire_radius+fender_shift), car_rear_bumper                 , side_shift},
        }},
        {{
          {-back_axle_shift+(tire_radius+fender_shift)-((float)0.86*new_radius), up_shift+((float)1.2*new_radius), side_shift},
          {-back_axle_shift+(tire_radius)                                      , car_roof                        , side_shift},
          {-back_axle_shift+(tire_radius+fender_shift)-((float)0.86*new_radius), up_shift+((float)1.2*new_radius), side_shift},
          {-back_axle_shift+(tire_radius)                                      , car_roof                        , side_shift},
        }},
        {{ // backside
          {-rear_bumper_begin_x                       , rear_bumper_begin_y, side_shift},
          {-back_axle_shift-(tire_radius+fender_shift), car_rear_bumper    , side_shift},
          {-rear_bumper_begin_x                       , rear_bumper_begin_y, side_shift},
          {-back_axle_shift-(tire_radius+fender_shift), car_rear_bumper    , side_shift},
        }},
      }},
      {{ // rear right side 3 (down - up)
        {{ // frontside
          {-rear_bumper_begin_x                       , rear_bumper_begin_y, side_shift},
          {-back_axle_shift-(tire_radius+fender_shift), car_rear_bumper    , side_shift},
          {-rear_bumper_begin_x                       , rear_bumper_begin_y, side_shift},
          {-back_axle_shift-(tire_radius+fender_shift), car_rear_bumper    , side_shift},
        }},
        {{
          {-back_axle_shift-(tire_radius+fender_shift+rear_bumper_shift), rear_bumper_begin_y, side_shift},
          {-back_axle_shift-(tire_radius+fender_shift+rear_bumper_shift), car_rear_bumper    , side_shift},
          {-back_axle_shift-(tire_radius+fender_shift+rear_bumper_shift), rear_bumper_begin_y, side_shift},
          {-back_axle_shift-(tire_radius+fender_shift+rear_bumper_shift), car_rear_bumper    , side_shift},
        }},
        {{
          {-rear_bumper_begin_x                       , rear_bumper_begin_y, side_shift},
          {-back_axle_shift-(tire_radius+fender_shift), car_rear_bumper    , side_shift},
          {-rear_bumper_begin_x                       , rear_bumper_begin_y, side_shift},
          {-back_axle_shift-(tire_radius+fender_shift), car_rear_bumper    , side_shift},
        }},
        {{ // backside
          {-back_axle_shift-(tire_radius+fender_shift+rear_bumper_shift), rear_bumper_begin_y, side_shift},
          {-back_axle_shift-(tire_radius+fender_shift+rear_bumper_shift), car_rear_bumper    , side_shift},
          {-back_axle_shift-(tire_radius+fender_shift+rear_bumper_shift), rear_bumper_begin_y, side_shift},
          {-back_axle_shift-(tire_radius+fender_shift+rear_bumper_shift), car_rear_bumper    , side_shift},
        }},
      }},
      
      {{ // front left side 1 (down - up)
        {{ // frontside
          {front_axle_shift+(tire_radius+fender_shift+front_bumper_shift), front_bumper_begin_y, -side_shift},
          {front_axle_shift+(tire_radius+fender_shift+front_bumper_shift), car_front_bumper    , -side_shift},
          {front_axle_shift+(tire_radius+fender_shift+front_bumper_shift), front_bumper_begin_y, -side_shift},
          {front_axle_shift+(tire_radius+fender_shift+front_bumper_shift), car_front_bumper    , -side_shift},
        }},
        {{
          {front_axle_shift+(tire_radius+fender_shift+front_bumper_shift), front_bumper_begin_y, -side_shift},
          {front_axle_shift+(tire_radius+fender_shift+front_bumper_shift), car_front_bumper    , -side_shift},
          {front_axle_shift+(tire_radius+fender_shift+front_bumper_shift), front_bumper_begin_y, -side_shift},
          {front_axle_shift+(tire_radius+fender_shift+front_bumper_shift), car_front_bumper    , -side_shift},
        }},
        {{
          {front_bumper_begin_x                                          , front_bumper_begin_y, -side_shift},
          {front_axle_shift+(tire_radius+fender_shift+front_bumper_shift), car_front_bumper    , -side_shift},
          {front_bumper_begin_x                                          , front_bumper_begin_y, -side_shift},
          {front_axle_shift+(tire_radius+fender_shift+front_bumper_shift), car_front_bumper    , -side_shift},
        }},
        {{ // backside
          {front_bumper_begin_x                                          , front_bumper_begin_y, -side_shift},
          {front_axle_shift+(tire_radius+fender_shift+front_bumper_shift), car_front_bumper    , -side_shift},
          {front_bumper_begin_x                                          , front_bumper_begin_y, -side_shift},
          {front_axle_shift+(tire_radius+fender_shift+front_bumper_shift), car_front_bumper    , -side_shift},
        }},
      }},
      {{ // front left side 2 (down - up)
        {{ // frontside
          {front_bumper_begin_x                                          , front_bumper_begin_y, -side_shift},
          {front_axle_shift+(tire_radius+fender_shift+front_bumper_shift), car_front_bumper    , -side_shift},
          {front_bumper_begin_x                                          , front_bumper_begin_y, -side_shift},
          {front_axle_shift+(tire_radius+fender_shift+front_bumper_shift), car_front_bumper    , -side_shift},
        }},
        {{
          {front_axle_shift-(tire_radius+fender_shift)+((float)1.14*new_radius), up_shift+((float)1.26*new_radius), -side_shift},
          {front_axle_shift+(tire_radius+fender_shift+front_bumper_shift)      , car_front_bumper                 , -side_shift},
          {front_axle_shift-(tire_radius+fender_shift)+((float)1.14*new_radius), up_shift+((float)1.26*new_radius), -side_shift},
          {front_axle_shift+(tire_radius+fender_shift+front_bumper_shift)      , car_front_bumper                 , -side_shift},
        }},
        {{
          {front_axle_shift-(tire_radius+fender_shift), up_shift+(new_radius), -side_shift},
          {front_axle_shift-(tire_radius+fender_shift), car_hood             , -side_shift},
          {front_axle_shift-(tire_radius+fender_shift), up_shift+(new_radius), -side_shift},
          {front_axle_shift-(tire_radius+fender_shift), car_hood             , -side_shift},
        }},
        {{ // backside
          {front_axle_shift-(tire_radius+fender_shift), up_shift, -side_shift},
          {front_axle_shift-(tire_radius+fender_shift), car_hood, -side_shift},
          {front_axle_shift-(tire_radius+fender_shift), up_shift, -side_shift},
          {front_axle_shift-(tire_radius+fender_shift), car_hood, -side_shift},
        }},
      }},
      {{ // front left side 3 (down - up)
        {{ // frontside
          {front_axle_shift-(tire_radius+fender_shift), up_shift, -side_shift},
          {front_axle_shift-(tire_radius+fender_shift), car_hood, -side_shift},
          {front_axle_shift-(tire_radius+fender_shift), up_shift, -side_shift},
          {front_axle_shift-(tire_radius+fender_shift), car_hood, -side_shift},
        }},
        {{
          {front_axle_shift-(tire_radius+fender_shift), up_shift, -side_shift},
          {front_axle_shift-(tire_radius+fender_shift), car_hood, -side_shift},
          {front_axle_shift-(tire_radius+fender_shift), up_shift, -side_shift},
          {front_axle_shift-(tire_radius+fender_shift), car_hood, -side_shift},
        }},
        {{
          {front_axle_shift-(tire_radius+3*fender_shift), up_shift, -side_shift},
          {front_axle_shift-(tire_radius+3*fender_shift), car_hood, -side_shift},
          {front_axle_shift-(tire_radius+3*fender_shift), up_shift, -side_shift},
          {front_axle_shift-(tire_radius+3*fender_shift), car_hood, -side_shift},
        }},
        {{ // backside
          {front_axle_shift-(tire_radius+3*fender_shift), up_shift, -side_shift},
          {front_axle_shift-(tire_radius+3*fender_shift), car_hood, -side_shift},
          {front_axle_shift-(tire_radius+3*fender_shift), up_shift, -side_shift},
          {front_axle_shift-(tire_radius+3*fender_shift), car_hood, -side_shift},
        }},
      }},
      {{ // front left side 4 (down - up)
        {{ // frontside
          {front_axle_shift-(tire_radius+fender_shift), car_hood, -side_shift},
          {windshield_shift                           , car_roof, -side_shift},
          {front_axle_shift-(tire_radius+fender_shift), car_hood, -side_shift},
          {windshield_shift                           , car_roof, -side_shift},
        }},
        {{
          {front_axle_shift-(tire_radius+fender_shift), car_hood, -side_shift},
          {windshield_shift                           , car_roof, -side_shift},
          {front_axle_shift-(tire_radius+fender_shift), car_hood, -side_shift},
          {windshield_shift                           , car_roof, -side_shift},
        }},
        {{
          {front_axle_shift-(tire_radius+3*fender_shift), car_hood, -side_shift},
          {windshield_shift                             , car_roof, -side_shift},
          {front_axle_shift-(tire_radius+3*fender_shift), car_hood, -side_shift},
          {windshield_shift                             , car_roof, -side_shift},
        }},
        {{ // backside
          {front_axle_shift-(tire_radius+3*fender_shift), car_hood, -side_shift},
          {windshield_shift                             , car_roof, -side_shift},
          {front_axle_shift-(tire_radius+3*fender_shift), car_hood, -side_shift},
          {windshield_shift                             , car_roof, -side_shift},
        }},
      }},
      
      {{ // front right side 1 (down - up)
        {{ // frontside
          {front_axle_shift+(tire_radius+fender_shift+front_bumper_shift), front_bumper_begin_y, side_shift},
          {front_axle_shift+(tire_radius+fender_shift+front_bumper_shift), car_front_bumper    , side_shift},
          {front_axle_shift+(tire_radius+fender_shift+front_bumper_shift), front_bumper_begin_y, side_shift},
          {front_axle_shift+(tire_radius+fender_shift+front_bumper_shift), car_front_bumper    , side_shift},
        }},
        {{
          {front_axle_shift+(tire_radius+fender_shift+front_bumper_shift), front_bumper_begin_y, side_shift},
          {front_axle_shift+(tire_radius+fender_shift+front_bumper_shift), car_front_bumper    , side_shift},
          {front_axle_shift+(tire_radius+fender_shift+front_bumper_shift), front_bumper_begin_y, side_shift},
          {front_axle_shift+(tire_radius+fender_shift+front_bumper_shift), car_front_bumper    , side_shift},
        }},
        {{
          {front_bumper_begin_x                                          , front_bumper_begin_y, side_shift},
          {front_axle_shift+(tire_radius+fender_shift+front_bumper_shift), car_front_bumper    , side_shift},
          {front_bumper_begin_x                                          , front_bumper_begin_y, side_shift},
          {front_axle_shift+(tire_radius+fender_shift+front_bumper_shift), car_front_bumper    , side_shift},
        }},
        {{ // backside
          {front_bumper_begin_x                                          , front_bumper_begin_y, side_shift},
          {front_axle_shift+(tire_radius+fender_shift+front_bumper_shift), car_front_bumper    , side_shift},
          {front_bumper_begin_x                                          , front_bumper_begin_y, side_shift},
          {front_axle_shift+(tire_radius+fender_shift+front_bumper_shift), car_front_bumper    , side_shift},
        }},
      }},
      {{ // front right side 2 (down - up)
        {{ // frontside
          {front_bumper_begin_x                                          , front_bumper_begin_y, side_shift},
          {front_axle_shift+(tire_radius+fender_shift+front_bumper_shift), car_front_bumper    , side_shift},
          {front_bumper_begin_x                                          , front_bumper_begin_y, side_shift},
          {front_axle_shift+(tire_radius+fender_shift+front_bumper_shift), car_front_bumper    , side_shift},
        }},
        {{
          {front_axle_shift-(tire_radius+fender_shift)+((float)1.14*new_radius), up_shift+((float)1.26*new_radius), side_shift},
          {front_axle_shift+(tire_radius+fender_shift+front_bumper_shift)      , car_front_bumper                 , side_shift},
          {front_axle_shift-(tire_radius+fender_shift)+((float)1.14*new_radius), up_shift+((float)1.26*new_radius), side_shift},
          {front_axle_shift+(tire_radius+fender_shift+front_bumper_shift)      , car_front_bumper                 , side_shift},
        }},
        {{
          {front_axle_shift-(tire_radius+fender_shift), up_shift+(new_radius), side_shift},
          {front_axle_shift-(tire_radius+fender_shift), car_hood             , side_shift},
          {front_axle_shift-(tire_radius+fender_shift), up_shift+(new_radius), side_shift},
          {front_axle_shift-(tire_radius+fender_shift), car_hood             , side_shift},
        }},
        {{ // backside
          {front_axle_shift-(tire_radius+fender_shift), up_shift, side_shift},
          {front_axle_shift-(tire_radius+fender_shift), car_hood, side_shift},
          {front_axle_shift-(tire_radius+fender_shift), up_shift, side_shift},
          {front_axle_shift-(tire_radius+fender_shift), car_hood, side_shift},
        }},
      }},
      {{ // front right side 3 (down - up)
        {{ // frontside
          {front_axle_shift-(tire_radius+fender_shift), up_shift, side_shift},
          {front_axle_shift-(tire_radius+fender_shift), car_hood, side_shift},
          {front_axle_shift-(tire_radius+fender_shift), up_shift, side_shift},
          {front_axle_shift-(tire_radius+fender_shift), car_hood, side_shift},
        }},
        {{
          {front_axle_shift-(tire_radius+fender_shift), up_shift, side_shift},
          {front_axle_shift-(tire_radius+fender_shift), car_hood, side_shift},
          {front_axle_shift-(tire_radius+fender_shift), up_shift, side_shift},
          {front_axle_shift-(tire_radius+fender_shift), car_hood, side_shift},
        }},
        {{
          {front_axle_shift-(tire_radius+3*fender_shift), up_shift, side_shift},
          {front_axle_shift-(tire_radius+3*fender_shift), car_hood, side_shift},
          {front_axle_shift-(tire_radius+3*fender_shift), up_shift, side_shift},
          {front_axle_shift-(tire_radius+3*fender_shift), car_hood, side_shift},
        }},
        {{ // backside
          {front_axle_shift-(tire_radius+3*fender_shift), up_shift, side_shift},
          {front_axle_shift-(tire_radius+3*fender_shift), car_hood, side_shift},
          {front_axle_shift-(tire_radius+3*fender_shift), up_shift, side_shift},
          {front_axle_shift-(tire_radius+3*fender_shift), car_hood, side_shift},
        }},
      }},
      {{ // front right side 4 (down - up)
        {{ // frontside
          {front_axle_shift-(tire_radius+fender_shift), car_hood, side_shift},
          {windshield_shift                           , car_roof, side_shift},
          {front_axle_shift-(tire_radius+fender_shift), car_hood, side_shift},
          {windshield_shift                           , car_roof, side_shift},
        }},
        {{
          {front_axle_shift-(tire_radius+fender_shift), car_hood, side_shift},
          {windshield_shift                           , car_roof, side_shift},
          {front_axle_shift-(tire_radius+fender_shift), car_hood, side_shift},
          {windshield_shift                           , car_roof, side_shift},
        }},
        {{
          {front_axle_shift-(tire_radius+3*fender_shift), car_hood, side_shift},
          {windshield_shift                             , car_roof, side_shift},
          {front_axle_shift-(tire_radius+3*fender_shift), car_hood, side_shift},
          {windshield_shift                             , car_roof, side_shift},
        }},
        {{ // backside
          {front_axle_shift-(tire_radius+3*fender_shift), car_hood, side_shift},
          {windshield_shift                             , car_roof, side_shift},
          {front_axle_shift-(tire_radius+3*fender_shift), car_hood, side_shift},
          {windshield_shift                             , car_roof, side_shift},
        }},
      }},
    };

    for(int i = 0; i < surface_ctrlpoints.size(); i++){
      glMap2f(GL_MAP2_VERTEX_3, 0, 1, 3, 4,
            0, 1, 12, 4, &surface_ctrlpoints[i][0][0][0]);

      // glEvalMesh2(GL_LINE, 0, RESOLUTION, 0, RESOLUTION);
      glEvalMesh2(GL_FILL, 0, RESOLUTION, 0, RESOLUTION);
    }
  
    glColor4ubv (car_window_color); // paints the car

    // define the points of the windows surfaces
    vector<array<array<array<GLfloat, 3>, 4>, 4>> windows_ctrlpoints = {
      {{ // windshield (down - up)
        {{ // left
          {front_axle_shift-(tire_radius+fender_shift), car_hood, -side_shift},
          {windshield_shift                           , car_roof, -side_shift},
          {front_axle_shift-(tire_radius+fender_shift), car_hood, -side_shift},
          {windshield_shift                           , car_roof, -side_shift},
        }},
        {{
          {front_axle_shift-(tire_radius+fender_shift), car_hood, -side_shift},
          {windshield_shift                           , car_roof, -side_shift},
          {front_axle_shift-(tire_radius+fender_shift), car_hood, -side_shift},
          {windshield_shift                           , car_roof, -side_shift},
        }},
        {{
          {front_axle_shift-(tire_radius+fender_shift), car_hood, side_shift},
          {windshield_shift                           , car_roof, side_shift},
          {front_axle_shift-(tire_radius+fender_shift), car_hood, side_shift},
          {windshield_shift                           , car_roof, side_shift},
        }},
        {{ // right
          {front_axle_shift-(tire_radius+fender_shift), car_hood, side_shift},
          {windshield_shift                           , car_roof, side_shift},
          {front_axle_shift-(tire_radius+fender_shift), car_hood, side_shift},
          {windshield_shift                           , car_roof, side_shift},
        }},
        // {{ // example of curvated surface
        //   {-back_axle_shift+(tire_radius)    , car_roof     , side_shift},
        //   {-back_axle_shift+(tire_radius)+0.5, car_roof+0.05, side_shift},
        //   {windshield_shift-0.15             , car_roof+0.05, side_shift},
        //   {windshield_shift                  , car_roof     , side_shift},
        // }},
      }},
      {{ // rear window (down - up)
        {{ // left
          {-back_axle_shift-(tire_radius+fender_shift), car_rear_bumper, -side_shift},
          {-back_axle_shift+(tire_radius)             , car_roof       , -side_shift},
          {-back_axle_shift-(tire_radius+fender_shift), car_rear_bumper, -side_shift},
          {-back_axle_shift+(tire_radius)             , car_roof       , -side_shift},
        }},
        {{
          {-back_axle_shift-(tire_radius+fender_shift), car_rear_bumper, -side_shift},
          {-back_axle_shift+(tire_radius)             , car_roof       , -side_shift},
          {-back_axle_shift-(tire_radius+fender_shift), car_rear_bumper, -side_shift},
          {-back_axle_shift+(tire_radius)             , car_roof       , -side_shift},
        }},
        {{
          {-back_axle_shift-(tire_radius+fender_shift), car_rear_bumper, side_shift},
          {-back_axle_shift+(tire_radius)             , car_roof       , side_shift},
          {-back_axle_shift-(tire_radius+fender_shift), car_rear_bumper, side_shift},
          {-back_axle_shift+(tire_radius)             , car_roof       , side_shift},
        }},
        {{ // right
          {-back_axle_shift-(tire_radius+fender_shift), car_rear_bumper, side_shift},
          {-back_axle_shift+(tire_radius)             , car_roof       , side_shift},
          {-back_axle_shift-(tire_radius+fender_shift), car_rear_bumper, side_shift},
          {-back_axle_shift+(tire_radius)             , car_roof       , side_shift},
        }},
      }},
    };

    for(int i = 0; i < windows_ctrlpoints.size(); i++){
      glMap2f(GL_MAP2_VERTEX_3, 0, 1, 3, 4,
            0, 1, 12, 4, &windows_ctrlpoints[i][0][0][0]);

      // glEvalMesh2(GL_LINE, 0, RESOLUTION, 0, RESOLUTION);
      glEvalMesh2(GL_FILL, 0, RESOLUTION, 0, RESOLUTION);
    }
  }
}