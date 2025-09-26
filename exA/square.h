/*
 * File Name: square.h
 * Assignment: Lab 1 Exercise B
 * Lab Section: B02
 * Completed by: Stephen Ravelo, Aaron Lauang
 * Submission Date: September 20, 2025
 */

#ifndef SQUARE_H
#define SQUARE_H

#include "shape.h"

class Square : virtual public Shape
{
public:
    Square(double x, double y, double side_a, const char *shapeName);
    Square(const Square &source);
    Square &operator=(const Square &rhs);
    
    double get_side_a() const;
    void set_side_a(const double side_a);
    
    virtual void display() const;
    double area() const;
    double perimeter() const;

private:
    double side_aM;
};

#endif