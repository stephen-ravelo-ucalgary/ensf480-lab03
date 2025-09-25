/*
 * File Name: curveCut.cpp
 * Assignment: Lab 3 Exercise A
 * Lab Section: B02
 * Completed by: Stephen Ravelo, Aaron Lauang
 * Submission Date: September 20, 2025
 */

#include <iostream>
#include <cmath>
#include <iomanip>
#include "curveCut.h"
using namespace std;

CurveCut::CurveCut(double x, double y, double side_a, double side_b, double radius, const char* shapeName)
    : Shape(x, y, shapeName),
    Rectangle(x, y, side_a, side_b, shapeName),
    Circle(x, y, radius, shapeName) {
    if(radius > side_a || radius > side_b) {
        cout << "Radius cannot be bigger than the width or length of the rectangle." << endl;
        exit(1);
    }
}

CurveCut& CurveCut::operator =(const CurveCut &rhs) {
    if (this != &rhs) {
        Square::operator=(rhs);
        Rectangle::operator=(rhs);
        Circle::operator=(rhs);
    }
    return *this;
}

CurveCut::CurveCut(const CurveCut &source)
    : Shape(source.getOrigin().getX(), source.getOrigin().getY(), source.getName()),
    Rectangle(source.getOrigin().getX(), source.getOrigin().getY(), source.get_side_a(), source.get_side_b(), source.getName()),
    Circle(source.getOrigin().getX(), source.getOrigin().getY(), source.get_radius(), source.getName()) {
}

double CurveCut::area() const {
    double circle_area = M_PI * pow(get_radius(), 2);
    double rectangle_area = get_side_a() * get_side_b();
    return rectangle_area - circle_area / 4;
}

double CurveCut::perimeter() const 
{
    return 2 * (get_side_a() + get_side_b() - get_radius()) + M_PI * get_radius() / 2;
}

void CurveCut::display() const {
    cout << fixed;
    cout << setprecision(2);
    cout << "CurveCut Name: " << getName() << endl;
    cout << "X-coordinate: " << getOrigin().getX() << endl;
    cout << "Y-coordinate: " << getOrigin().getY() << endl;
    cout << "Side a: " << get_side_a() << endl;
    cout << "Side b: " << get_side_b() << endl;
    cout << "Radius: " << get_radius() << endl;
    cout << "Area: " << area() << endl;
    cout << "Perimeter: " << perimeter() << endl;
}