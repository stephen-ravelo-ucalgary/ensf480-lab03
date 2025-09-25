/*
 * File Name: circle.cpp
 * Assignment: Lab 3 Exercise A
 * Lab Section: B02
 * Completed by: Stephen Ravelo, Aaron Lauang
 * Submission Date: September 28, 2025
 */

#include <iostream>
#include <iomanip>
#include <math.h>
#include <cstring>

using namespace std;

#include "circle.h"

Circle::Circle(double x, double y, double radius, const char *shapeName)
    : Shape(x, y, shapeName), radiusM(radius)
{
}

Circle::Circle(const Circle &source)
    : Shape(source.getOrigin().getX(), source.getOrigin().getY(), source.getName()), radiusM(source.radiusM)
{
}

Circle &Circle::operator=(const Circle &rhs)
{
    if (this != &rhs)
    {
        Shape::operator=(rhs);
        set_radius(rhs.radiusM);
    }

    return *this;
}

double Circle::get_radius() const { return radiusM; }
void Circle::set_radius(double radius) { radiusM = radius; }

double Circle::area() const { return M_PI * pow(radiusM, 2); }
double Circle::perimeter() const { return 2 * M_PI * radiusM; }

void Circle::display() const
{
    cout << fixed << setprecision(2);

    cout << "Shape Name: " << getName() << endl
         << "X-coordinate: " << getOrigin().getX() << endl
         << "Y-coordinate: " << getOrigin().getY() << endl
         << "Radius: " << radiusM << endl
         << "Area: " << area() << endl
         << "Perimeter: " << perimeter() << endl;
}