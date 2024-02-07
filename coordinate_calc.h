#include <iostream>
#include <cmath>
#include <math.h>

#define PI 3.14159265

#ifndef COORDINATE_CALC_H
#define COORDINATE_CALC_H

class Coordinate_system_calculations
{
private:
    double x1, x2, x3, x4;
    double y1, y2, y3, y4;
    double rotation_angle;

public:
    Coordinate_system_calculations(double rot_angle, double side_x, double side_y);

    void geometric_center_after_rotation_XY(double *xy_arr);

    inline double geometric_center_before_rotation_X_point() const;

    inline double geometric_center_before_rotation_Y_point() const;

    ~Coordinate_system_calculations();
};

#endif
