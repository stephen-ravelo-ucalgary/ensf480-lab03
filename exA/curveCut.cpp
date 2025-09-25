/*
 * File Name: curveCut.cpp
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

#include "curveCut.h"

CurveCut::CurveCut(double x, double y, double side_a, double side_b, double radius, const char *shapeName)
    : Shape(x, y, shapeName),
      Rectangle(x, y, side_a, side_b, shapeName),
      Circle(x, y, radius, shapeName)
{
    if (radius > side_a || radius > side_b)
    {
        cout << "Error: CurveCut circle radius is greater than side_a or side_b." << endl;
        exit(1);
    }
}

CurveCut::CurveCut(const CurveCut &source)
    : Shape(source.getOrigin().getX(), source.getOrigin().getY(), source.getName()),
      Rectangle(source.getOrigin().getX(), source.getOrigin().getY(), source.get_side_a(), source.get_side_b(), source.getName()),
      Circle(source.getOrigin().getX(), source.getOrigin().getX(), source.get_radius(), source.getName())
{
}

CurveCut &CurveCut::operator=(const CurveCut &rhs)
{
    if (this != &rhs)
    {
        Rectangle::operator=(rhs);
        Circle::operator=(rhs);
    }

    return *this;
}

double CurveCut::area() const
{
    double circle_area = M_PI * pow(get_radius(), 2);
    double rectangle_area = get_side_a() * get_side_b();

    return rectangle_area - circle_area / 4;
}
double CurveCut::perimeter() const
{
    return 2 * (get_side_a() + get_side_b() - get_radius()) + M_PI * get_radius() / 2;
}

void CurveCut::display() const
{
    cout << fixed << setprecision(2);

    cout << "Shape Name: " << getName() << endl
         << "X-coordinate: " << getOrigin().getX() << endl
         << "Y-coordinate: " << getOrigin().getY() << endl
         << "Width: " << get_side_a() << endl
         << "Length: " << get_side_b() << endl
         << "Radius: " << get_radius() << endl
         << "Area: " << area() << endl
         << "Perimeter: " << perimeter() << endl;
}