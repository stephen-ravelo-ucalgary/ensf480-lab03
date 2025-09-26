/*
 * File Name: curveCut.h
 * Assignment: Lab 3 Exercise A
 * Lab Section: B02
 * Completed by: Stephen Ravelo, Aaron Lauang
 * Submission Date: September 28, 2025
 */

#ifndef CURVECUT_H
#define CURVECUT_H

#include "rectangle.h"
#include "circle.h"

class CurveCut : public Rectangle, public Circle
{
public:
    CurveCut(double x, double y, double side_a, double side_b, double radius, const char *shapeName);
    CurveCut(const CurveCut &source);
    CurveCut &operator=(const CurveCut &rhs);

    void display() const;
    double area() const;
    double perimeter() const;
};

#endif