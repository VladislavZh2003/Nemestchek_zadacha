#include <iostream>

#include "figures.h"

#ifndef PLANT_H
#define PLANT_H

using namespace std;

class Plant
{
public:
    Shape *fig;

    Plant(double instance1, double instance2);

    Plant(int figura_number, double instance1);

    ~Plant();
};

#endif
