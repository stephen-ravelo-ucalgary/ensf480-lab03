/*
 * File Name: point.cpp
 * Assignment: Lab 1 Exercise B
 * Lab Section: B02
 * Completed by: Stephen Ravelo, Aaron Lauang
 * Submission Date: September 20, 2025
 */

#include <iostream>
#include <cmath>
#include <iomanip>
#include "point.h"
using namespace std;

int Point::count = 0;

Point::Point(double x, double y) : ID(1000 + ++count) {
    xM = x;
    yM = y;
}

double Point::getX() const {
    return xM;
}

double Point::getY() const {
    return yM;
}

void Point::setX(const double x) {
    xM = x;
}

void Point::setY(const double y) {
    yM = y;
}

int Point::counter() {
    return count;
}

int Point::getID() const {
    return ID;
}

double Point::distance(Point& other) {
    return sqrt(pow(other.xM - xM, 2) + pow(other.yM - yM, 2));
}

double Point::distance(Point& the_point, Point& other) {
    return sqrt(pow(other.xM - the_point.xM, 2) + pow(other.yM - the_point.yM, 2));
}

void Point::display() const {
    cout << fixed;
    cout << setprecision(2);
    cout << "X-coordinate: " << xM << endl;
    cout << "Y-coordinate: " << yM << endl;
}