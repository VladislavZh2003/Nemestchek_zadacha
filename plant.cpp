#include "plant.h"

Plant::Plant(double instance1, double instance2)
{
    this->fig = new Oval(instance1, instance2);
}

Plant::Plant(int figura_number, double instance1)
{
    switch (figura_number)
    {
    case 2:
        this->fig = new Circle(instance1);
        break;

    case 3:
        this->fig = new Triangle(instance1);
        break;

    case 4:
        this->fig = new Hexagon(instance1);
        break;
    default:
        this->fig = nullptr;
        break;
    }
}

Plant::~Plant()
{
    fig = nullptr;
    delete fig;
}
