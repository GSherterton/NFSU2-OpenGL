#include "Door.h"

Door::Door() {}

Door::~Door() {}

void Door::drawDoor() {
    // glPointSize(4.0);
    glLineWidth(4.0);       // line width
    glColor3ubv(car_color); // paints the car

    // the x axle is the front-back direction, the y axle is the up-down direction and the z axle is the left-right direction
    // define the points of the door splines
    vector<array<array<GLfloat, 3>, 4>> door_ctrlpoints = {
        {{
            // backline
            {-back_line_shift, up_shift, 0.0},
            {-back_line_shift, car_roof, 0.0},
            {-back_line_shift, up_shift, 0.0},
            {-back_line_shift, car_roof, 0.0},
        }},
        {{
            // topline
            {-back_line_shift, car_roof, 0.0},
            {windshield_shift, car_roof, 0.0},
            {-back_line_shift, car_roof, 0.0},
            {windshield_shift, car_roof, 0.0},
        }},
        {{
            // topline
            {windshield_shift, car_roof, 0.0},
            {front_axle_shift - (tire_radius + 3 * fender_shift), car_hood, 0.0},
            {windshield_shift, car_roof, 0.0},
            {front_axle_shift - (tire_radius + 3 * fender_shift), car_hood, 0.0},
        }},
        {{
            // frontline
            {front_axle_shift - (tire_radius + 3 * fender_shift), car_hood, 0.0},
            {front_axle_shift - (tire_radius + 3 * fender_shift), up_shift, 0.0},
            {front_axle_shift - (tire_radius + 3 * fender_shift), car_hood, 0.0},
            {front_axle_shift - (tire_radius + 3 * fender_shift), up_shift, 0.0},
        }},
        {{
            // downline
            {front_axle_shift - (tire_radius + 3 * fender_shift), up_shift, 0.0},
            {-back_line_shift, up_shift, 0.0},
            {front_axle_shift - (tire_radius + 3 * fender_shift), up_shift, 0.0},
            {-back_line_shift, up_shift, 0.0},
        }},
    };

    for (int i = 0; i < door_ctrlpoints.size(); i++) {
        glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 4, &door_ctrlpoints[i][0][0]);

        glBegin(GL_LINE_STRIP);
        for (int j = 0; j <= RESOLUTION; j++)
            glEvalCoord1f((GLfloat) float(j) / RESOLUTION);
        glEnd();
    }
}