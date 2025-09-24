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

class Square : public Shape
{
public:
    Square(double x, double y, double side_a, const char* shapeName);
    Square &operator=(const Square &rhs);
    Square(const Square &source);
    
    double get_side_a() const;
    void set_side_a(const double side_a);
    
    double area() const;
    double perimeter() const;
    virtual void display() const;

private:
    double side_aM;
};

#endif