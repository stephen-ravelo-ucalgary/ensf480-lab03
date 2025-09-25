/*
 * File Name: circle.cpp
 * Assignment: Lab 3 Exercise A
 * Lab Section: B02
 * Completed by: Stephen Ravelo, Aaron Lauang
 * Submission Date: September 20, 2025
 */

#include <iostream>
#include <cmath>
#include <iomanip>
#include "circle.h"
using namespace std;

Circle::Circle(double x, double y, double radius, const char* shapeName) : Shape(x, y, shapeName) {
    radiusM = radius;
}

Circle& Circle::operator = (const Circle &rhs) {
    if (this != &rhs) {
        Shape::operator=(rhs);
        set_radius(rhs.get_radius());
    }
    return *this;
}

Circle::Circle(const Circle &source) : Shape(source.getOrigin().getX(), source.getOrigin().getY(), source.getName()) {
    radiusM = source.radiusM;    
}

double Circle::get_radius() const {
    return radiusM;
}

void Circle::set_radius(const double radius) {
    radiusM = radius;
}

double Circle::area() const {
    return M_PI * pow(radiusM, 2);
}

double Circle::perimeter() const {
    return 2 * M_PI * radiusM;
}

void Circle::display() const {
    cout << fixed;
    cout << setprecision(2);
    cout << "Circle Name: " << getName() << endl;
    cout << "X-coordinate: " << getOrigin().getX() << endl;
    cout << "Y-coordinate: " << getOrigin().getY() << endl;
    cout << "Radius: " << radiusM << endl;
    cout << "Area: " << area() << endl;
    cout << "Perimeter: " << perimeter() << endl;
}