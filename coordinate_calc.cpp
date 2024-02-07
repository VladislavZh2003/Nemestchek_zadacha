#include "coordinate_calc.h"

Coordinate_system_calculations::Coordinate_system_calculations(double rot_angle, double side_x, double side_y)
{
    this->rotation_angle = rot_angle;

    this->x1 = 0;
    this->y1 = 0;

    this->x2 = side_x;
    this->y2 = 0;

    this->x3 = side_x;
    this->y3 = side_y;

    this->x4 = 0;
    this->y4 = side_y;
}

void Coordinate_system_calculations::geometric_center_after_rotation_XY(double *xy_arr)
{
    double x_point = geometric_center_before_rotation_X_point();
    double y_point = geometric_center_before_rotation_Y_point();

    double sin_angle = sin(rotation_angle * PI / 180);
    double cos_angle = cos(rotation_angle * PI / 180);

    xy_arr[0] = x_point * cos_angle - y_point * sin_angle;
    xy_arr[1] = x_point * sin_angle + y_point * cos_angle;
}

inline double Coordinate_system_calculations::geometric_center_before_rotation_X_point() const { return ((x1 + x2 + x3 + x4) / 4); }

inline double Coordinate_system_calculations::geometric_center_before_rotation_Y_point() const { return ((y1 + y2 + y3 + y4) / 4); }

Coordinate_system_calculations::~Coordinate_system_calculations() {}
