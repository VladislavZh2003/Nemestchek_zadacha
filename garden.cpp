#include "garden.h"

Garden::Garden(double width_garden, double height_garden, double rot_angle)
{
    this->width = width_garden;
    this->height = height_garden;
    this->rotation_angle = rot_angle;
    this->garden_area = width * height;
}

void Garden::fill_garden(Plant plant)
{
    double plant_width = plant.fig->circumscribed_rectangle_side_a;
    double plant_height = plant.fig->circumscribed_rectangle_side_b;

    for (double i = plant_height; i <= height; i += plant_height)
    {
        for (double j = plant_width; j <= width; j += plant_width)
        {
            plants.push_back(plant);
        }
    }
}

int Garden::plants_in_garden()
{
    return plants.size();
}

double Garden::filling_area_in_percentages()
{
    if (plants_in_garden() == 0)
        return 0;
    double all_bush_area = plants[0].fig->area() * plants_in_garden();
    double filling_percentages = (all_bush_area / garden_area) * 100;
    return filling_percentages;
}

void Garden::garden_geometric_center(double *xy_arr)
{
    Coordinate_system_calculations garden_center(rotation_angle, width, height);
    garden_center.geometric_center_after_rotation_XY(xy_arr);
}

void Garden::bush_geometric_center(double *xy_arr, Plant plant)
{
    if (plants_in_garden() == 0)
    {
        xy_arr[0] = 0;
        xy_arr[1] = 0;
        return;
    }
    double all_bushes_side_X = 0;
    double all_bushes_side_Y = 0;

    double plant_width = plant.fig->circumscribed_rectangle_side_a;
    double plant_height = plant.fig->circumscribed_rectangle_side_b;

    for (double i = plant_height; i <= height; i += plant_height)
    {
        for (double j = plant_width; j <= width; j += plant_width)
        {
            all_bushes_side_X = j;
        }
        all_bushes_side_Y = i;
    }

    Coordinate_system_calculations bush_center(rotation_angle, all_bushes_side_X, all_bushes_side_Y);
    bush_center.geometric_center_after_rotation_XY(xy_arr);
}

Garden::~Garden() {}
