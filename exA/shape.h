/*
 * File Name: shape.h
 * Assignment: Lab 1 Exercise B
 * Lab Section: B02
 * Completed by: Stephen Ravelo, Aaron Lauang
 * Submission Date: September 20, 2025
 */

#ifndef SHAPE_H
#define SHAPE_H

#include "point.h"

class Shape
{
public:
    Shape(double x, double y, const char *shapeName);
    Shape(const Shape &source);
    Shape &operator=(const Shape &rhs);
    ~Shape();
    
    const Point &getOrigin() const;
    char *getName() const;

    virtual void display() const;
    double distance(Shape &other);
    static double distance(Shape &s1, Shape &s2);
    void move(double dx, double dy);
    virtual double area() const = 0;
    virtual double perimeter() const = 0;

private:
    Point originM;
    char *shapeNameM;
};

#endif