/*
 * File Name: circle.h
 * Assignment: Lab 3 Exercise A
 * Lab Section: B02
 * Completed by: Stephen Ravelo, Aaron Lauang
 * Submission Date: September 20, 2025
 */

#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"

class Circle : virtual public Shape
{
public:
    Circle(double x, double y, double radius, const char* shapeName);
    Circle &operator=(const Circle &rhs);
    Circle(const Circle &source);
    
    double get_radius() const;
    void set_radius(const double radius);
    
    double area() const;
    double perimeter() const;
    virtual void display() const;

private:
    double radiusM;
};

#endif