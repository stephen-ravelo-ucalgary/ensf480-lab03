/*
 * File Name: square.cpp
 * Assignment: Lab 1 Exercise B
 * Lab Section: B02
 * Completed by: Stephen Ravelo, Aaron Lauang
 * Submission Date: September 20, 2025
 */

#include <iostream>
#include <cmath>
#include <iomanip>
#include "square.h"
using namespace std;

Square::Square(double x, double y, double side_a, const char* shapeName) : Shape(x, y, shapeName) {
    side_aM = side_a;
}

Square& Square::operator = (const Square &rhs) {
    if (this != &rhs) {
        Shape::operator=(rhs);
        set_side_a(rhs.get_side_a());
    }
    return *this;
}

Square::Square(const Square &source) : Shape(source.getOrigin().getX(), source.getOrigin().getY(), source.getName()) {
    side_aM = source.side_aM;    
}

double Square::get_side_a() const {
    return side_aM;
}

void Square::set_side_a(const double side_a) {
    side_aM = side_a;
}

double Square::area() const {
    return side_aM * side_aM;
}

double Square::perimeter() const {
    return side_aM * 4;
}

void Square::display() const {
    cout << fixed;
    cout << setprecision(2);
    cout << "Square Name: " << getName() << endl;
    cout << "X-coordinate: " << getOrigin().getX() << endl;
    cout << "Y-coordinate: " << getOrigin().getY() << endl;
    cout << "Side a: " << side_aM << endl;
    cout << "Area: " << area() << endl;
    cout << "Perimeter: " << perimeter() << endl;
}