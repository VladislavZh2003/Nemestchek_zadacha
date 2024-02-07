#include <iostream>
#include <vector>

#include "plant.h"
#include "coordinate_calc.h"

#ifndef GARDEN_H
#define GARDEN_H

class Garden
{
private:
    double width;
    double height;
    double rotation_angle;
    double garden_area;
    vector<Plant> plants;

public:
    Garden(double width_garden, double height_garden, double rot_angle);

    void fill_garden(Plant plant);

    int plants_in_garden();

    double filling_area_in_percentages();

    void garden_geometric_center(double *xy_arr);

    void bush_geometric_center(double *xy_arr, Plant plant);

    ~Garden();
};

#endif
