/*
 * File Name: rectangle.h
 * Assignment: Lab 1 Exercise B
 * Lab Section: B02
 * Completed by: Stephen Ravelo, Aaron Lauang
 * Submission Date: September 20, 2025
 */

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "square.h"

class Rectangle : public Square
{
public:
    Rectangle(double x, double y, double side_a, double side_b, const char* shapeName);
    Rectangle &operator=(const Rectangle &rhs);
    Rectangle(const Rectangle &source);

    
    double get_side_b() const;
    void set_side_b(const double side_b);
    
    double area() const;
    double perimeter() const;
    void display() const;

private:
    double side_bM;
};

#endif