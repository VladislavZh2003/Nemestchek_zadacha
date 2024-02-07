#include <iostream>
#include <cmath>
#include <string>
#include <math.h>

#ifndef FIGURES_H
#define FIGURES_H

#define PI 3.14159265

using namespace std;

class Shape
{
public:
    string name;
    double circumscribed_rectangle_side_a;
    double circumscribed_rectangle_side_b;

    Shape();

    virtual double area() = 0;

    virtual ~Shape();
};

class Oval : public Shape
{
private:
    double radius1;
    double radius2;

public:
    Oval(double radius1, double radius2);

    double area() override;

    ~Oval();
};

class Circle : public Shape
{
private:
    double radius;

public:
    Circle(double radius);

    double area() override;

    ~Circle();
};

class Triangle : public Shape
{
private:
    double side;

public:
    Triangle(double side);

    double area() override;

    ~Triangle();
};

class Hexagon : public Shape
{
private:
    double side;

public:
    Hexagon(double side);

    double area() override;

    ~Hexagon();
};
#endif
