/*
 * File Name: rectangle.cpp
 * Assignment: Lab 1 Exercise B
 * Lab Section: B02
 * Completed by: Stephen Ravelo, Aaron Lauang
 * Submission Date: September 20, 2025
 */

#include <iostream>
#include <cmath>
#include <iomanip>
#include "rectangle.h"
using namespace std;

Rectangle::Rectangle(double x, double y, double side_a, double side_b, const char* shapeName) : Square(x, y, side_a, shapeName) {
    side_bM = side_b;
}

Rectangle& Rectangle::operator =(const Rectangle &rhs) {
    if (this != &rhs) {
        Square::operator=(rhs);
        set_side_a(rhs.get_side_a());
        set_side_b(rhs.get_side_b());
    }
    return *this;
}

Rectangle::Rectangle(const Rectangle &source) : Square(source.getOrigin().getX(), source.getOrigin().getY(), source.get_side_a(), source.getName()) {
    side_bM = source.side_bM;    
}

double Rectangle::get_side_b() const {
    return side_bM;
}

void Rectangle::set_side_b(const double side_b) {
    side_bM = side_b;
}

double Rectangle::area() const {
    return side_bM * get_side_a();
}

double Rectangle::perimeter() const {
    return (side_bM * 2) + (get_side_a() * 2);
}

void Rectangle::display() const {
    cout << fixed;
    cout << setprecision(2);
    cout << "Rectangle Name: " << getName() << endl;
    cout << "X-coordinate: " << getOrigin().getX() << endl;
    cout << "Y-coordinate: " << getOrigin().getY() << endl;
    cout << "Side a: " << get_side_a() << endl;
    cout << "Side b: " << side_bM << endl;
    cout << "Area: " << area() << endl;
    cout << "Perimeter: " << perimeter() << endl;
}