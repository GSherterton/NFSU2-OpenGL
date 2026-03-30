#include "Chassis.h"

Chassis::Chassis(){}

Chassis::~Chassis(){}

void Chassis::drawChassis(){
  // glPointSize(4.0);
  glLineWidth(4.0); // line width
  glColor3ubv (car_color); // paints the car

  // the x axle is the front-back direction, the y axle is the up-down direction and the z axle is the left-right direction
  // define the points of the down splines
  vector<array<array<GLfloat, 3>, 4>> down_ctrlpoints = {
    {{ // rear left fender
      {-back_axle_shift+(tire_radius+fender_shift), up_shift                                         , -side_shift},
      {-back_axle_shift+(tire_radius+fender_shift), up_shift+((float)1.33*(tire_radius+fender_shift)), -side_shift},
      {-back_axle_shift-(tire_radius+fender_shift), up_shift+((float)1.33*(tire_radius+fender_shift)), -side_shift},
      {-back_axle_shift-(tire_radius+fender_shift), up_shift                                         , -side_shift},
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
      {-back_axle_shift-(tire_radius+fender_shift), up_shift                                         , side_shift},
      {-back_axle_shift-(tire_radius+fender_shift), up_shift+((float)1.33*(tire_radius+fender_shift)), side_shift},
      {-back_axle_shift+(tire_radius+fender_shift), up_shift+((float)1.33*(tire_radius+fender_shift)), side_shift},
      {-back_axle_shift+(tire_radius+fender_shift), up_shift                                         , side_shift},
    }},
    {{ // right side skirt
      {-back_axle_shift+(tire_radius+fender_shift), up_shift, side_shift},
      {front_axle_shift-(tire_radius+fender_shift), up_shift, side_shift},
      {-back_axle_shift+(tire_radius+fender_shift), up_shift, side_shift},
      {front_axle_shift-(tire_radius+fender_shift), up_shift, side_shift},
    }},
    {{ // front right fender
      {front_axle_shift-(tire_radius+fender_shift), up_shift                                         , side_shift},
      {front_axle_shift-(tire_radius+fender_shift), up_shift+((float)1.33*(tire_radius+fender_shift)), side_shift},
      {front_axle_shift+(tire_radius+fender_shift), up_shift+((float)1.33*(tire_radius+fender_shift)), side_shift},
      {front_axle_shift+(tire_radius+fender_shift), up_shift                                         , side_shift},
    }},
    {{ // front bumper
      {front_axle_shift+(tire_radius+fender_shift)                   , up_shift, side_shift},
      {front_axle_shift+(tire_radius+fender_shift+front_bumper_shift), up_shift, side_shift},
      {front_axle_shift+(tire_radius+fender_shift)                   , up_shift, side_shift},
      {front_axle_shift+(tire_radius+fender_shift+front_bumper_shift), up_shift, side_shift},
    }},
    {{ // front bumper
      {front_axle_shift+(tire_radius+fender_shift+front_bumper_shift), up_shift,  side_shift},
      {front_axle_shift+(tire_radius+fender_shift+front_bumper_shift), up_shift, -side_shift},
      {front_axle_shift+(tire_radius+fender_shift+front_bumper_shift), up_shift,  side_shift},
      {front_axle_shift+(tire_radius+fender_shift+front_bumper_shift), up_shift, -side_shift},
    }},
    {{ // front bumper
      {front_axle_shift+(tire_radius+fender_shift)                   , up_shift, -side_shift},
      {front_axle_shift+(tire_radius+fender_shift+front_bumper_shift), up_shift, -side_shift},
      {front_axle_shift+(tire_radius+fender_shift)                   , up_shift, -side_shift},
      {front_axle_shift+(tire_radius+fender_shift+front_bumper_shift), up_shift, -side_shift},
    }},
    {{ // front left fender
      {front_axle_shift+(tire_radius+fender_shift), up_shift                                         , -side_shift},
      {front_axle_shift+(tire_radius+fender_shift), up_shift+((float)1.33*(tire_radius+fender_shift)), -side_shift},
      {front_axle_shift-(tire_radius+fender_shift), up_shift+((float)1.33*(tire_radius+fender_shift)), -side_shift},
      {front_axle_shift-(tire_radius+fender_shift), up_shift                                         , -side_shift},
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

  // define the points of the up splines
  vector<array<array<GLfloat, 3>, 4>> up_ctrlpoints = {
    {{ // rear left chassis top
      {-back_axle_shift+(tire_radius)             , car_roof, -side_shift},
      {-back_axle_shift-(tire_radius+fender_shift), car_rear_bumper, -side_shift},
      {-back_axle_shift+(tire_radius)             , car_roof, -side_shift},
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
      {-back_axle_shift+(tire_radius)             , car_roof  , side_shift},
      {-back_axle_shift-(tire_radius+fender_shift), car_rear_bumper, side_shift},
      {-back_axle_shift+(tire_radius)             , car_roof  , side_shift},
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
    {{ //right side chassis top
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
      {-back_axle_shift-(tire_radius+fender_shift+rear_bumper_shift), up_shift+bumper_elevation_shift, -side_shift},
      {-back_axle_shift-(tire_radius+fender_shift+rear_bumper_shift), car_rear_bumper                       , -side_shift},
      {-back_axle_shift-(tire_radius+fender_shift+rear_bumper_shift), up_shift+bumper_elevation_shift, -side_shift},
      {-back_axle_shift-(tire_radius+fender_shift+rear_bumper_shift), car_rear_bumper                       , -side_shift},
    }},
    {{ // down - up trunk
      {-back_axle_shift-(tire_radius+fender_shift+rear_bumper_shift), up_shift+bumper_elevation_shift, side_shift},
      {-back_axle_shift-(tire_radius+fender_shift+rear_bumper_shift), car_rear_bumper                       , side_shift},
      {-back_axle_shift-(tire_radius+fender_shift+rear_bumper_shift), up_shift+bumper_elevation_shift, side_shift},
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
      {front_axle_shift+(tire_radius+fender_shift+front_bumper_shift), up_shift, side_shift},
      {front_axle_shift+(tire_radius+fender_shift+front_bumper_shift), car_front_bumper, side_shift},
      {front_axle_shift+(tire_radius+fender_shift+front_bumper_shift), up_shift, side_shift},
      {front_axle_shift+(tire_radius+fender_shift+front_bumper_shift), car_front_bumper, side_shift},
    }},
    {{ // down - up hood
      {front_axle_shift+(tire_radius+fender_shift+front_bumper_shift), up_shift, -side_shift},
      {front_axle_shift+(tire_radius+fender_shift+front_bumper_shift), car_front_bumper, -side_shift},
      {front_axle_shift+(tire_radius+fender_shift+front_bumper_shift), up_shift, -side_shift},
      {front_axle_shift+(tire_radius+fender_shift+front_bumper_shift), car_front_bumper, -side_shift},
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