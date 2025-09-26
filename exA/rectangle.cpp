/*
 * File Name: rectangle.cpp
 * Assignment: Lab 1 Exercise B
 * Lab Section: B02
 * Completed by: Stephen Ravelo, Aaron Lauang
 * Submission Date: September 20, 2025
 */

#include <iostream>
#include <iomanip>
#include <math.h>
#include <cstring>

using namespace std;

#include "rectangle.h"

Rectangle::Rectangle(double x, double y, double side_a, double side_b, const char *shapeName)
    : Shape(x, y, shapeName),
      Square(x, y, side_a, shapeName), side_bM(side_b)
{
}

Rectangle::Rectangle(const Rectangle &source)
    : Shape(source.getOrigin().getX(), source.getOrigin().getY(), source.getName()),
      Square(source.getOrigin().getX(), source.getOrigin().getY(), source.get_side_a(), source.getName()), side_bM(source.side_bM)
{
}

Rectangle &Rectangle::operator=(const Rectangle &rhs)
{
    if (this != &rhs)
    {
        Square::operator=(rhs);
        set_side_b(rhs.side_bM);
    }

    return *this;
}

double Rectangle::get_side_b() const { return side_bM; }
void Rectangle::set_side_b(double side_b) { side_bM = side_b; }

double Rectangle::area() const { return get_side_a() * side_bM; }
double Rectangle::perimeter() const { return (get_side_a() * 2) + (side_bM * 2); }

void Rectangle::display() const
{
    cout << fixed << setprecision(2);

    cout << "Shape Name: " << getName() << endl
         << "X-coordinate: " << getOrigin().getX() << endl
         << "Y-coordinate: " << getOrigin().getY() << endl
         << "Side a: " << get_side_a() << endl
         << "Side b: " << side_bM << endl
         << "Area: " << area() << endl
         << "Perimeter: " << perimeter() << endl;
}