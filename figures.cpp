#include "figures.h"

Shape::Shape() {}
Shape::~Shape() {}

Oval::Oval(double radius1, double radius2)
{
    this->radius1 = radius1;
    this->radius2 = radius2;
    circumscribed_rectangle_side_a = radius2 + radius2;
    circumscribed_rectangle_side_b = radius1 + radius1;
    name = "Oval";
}
double Oval::area()
{
    return (PI * radius1 * radius2);
}
Oval::~Oval() {}

Circle::Circle(double radius)
{
    this->radius = radius;
    circumscribed_rectangle_side_a = radius + radius;
    circumscribed_rectangle_side_b = radius + radius;
    name = "Circle";
}
double Circle::area()
{
    return (PI * (radius * radius));
}
Circle::~Circle() {}

Triangle::Triangle(double side)
{
    this->side = side;
    circumscribed_rectangle_side_a = side;
    circumscribed_rectangle_side_b = (sqrt(3) / 2 * side);
    name = "Triangle";
}
double Triangle::area()
{
    return ((sqrt(3) / 4) * (side * side));
}
Triangle::~Triangle() {}

Hexagon::Hexagon(double side)
{
    this->side = side;
    circumscribed_rectangle_side_a = side * 2;
    circumscribed_rectangle_side_b = (sqrt(3) / 2 * side) * 2;
    name = "Hexagon";
}
double Hexagon::area()
{
    return ((3 * sqrt(3) * (side * side)) / 2);
}
Hexagon::~Hexagon() {}
