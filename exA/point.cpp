/*
 * File Name: point.cpp
 * Assignment: Lab 1 Exercise B
 * Lab Section: B02
 * Completed by: Stephen Ravelo, Aaron Lauang
 * Submission Date: September 20, 2025
 */

#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

#include "point.h"

int Point::count = 0;

Point::Point(double x, double y) : xM(x), yM(y), ID((++count) + 1000) {}

double Point::getX() const { return xM; }
double Point::getY() const { return yM; }
int Point::getID() const { return ID; }
int Point::counter() { return count; }

void Point::setX(const double x) { xM = x; }
void Point::setY(const double y) { yM = y; }

void Point::display() const
{
    cout << fixed;
    cout << setprecision(2);
    cout << xM << endl;
    cout << yM << endl;
}

double Point::distance(Point &other) { return sqrt(pow(other.xM - xM, 2) + pow(other.yM - yM, 2)); }
double Point::distance(Point &p1, Point &p2) { return sqrt(pow(p2.xM - p1.xM, 2) + pow(p2.yM - p1.yM, 2)); }