/*
 * File Name: shape.cpp
 * Assignment: Lab 1 Exercise B
 * Lab Section: B02
 * Completed by: Stephen Ravelo, Aaron Lauang
 * Submission Date: September 20, 2025
 */

#include <iostream>
#include <iomanip>
#include <math.h>
#include <cstring>

using namespace std;

#include "shape.h"

Shape::Shape(double x, double y, const char *shapeName)
    : originM(Point(x, y)), shapeNameM(new char[strlen(shapeName) + 1])
{
    strcpy(shapeNameM, shapeName);
}

Shape::Shape(const Shape &source)
    : originM(Point(source.getOrigin().getX(), source.getOrigin().getY())), shapeNameM(new char[strlen(source.shapeNameM) + 1])
{
    strcpy(shapeNameM, source.shapeNameM);
}

Shape &Shape::operator=(const Shape &rhs)
{
    if (this != &rhs)
    {
        delete[] shapeNameM;
        shapeNameM = new char[strlen(rhs.shapeNameM) + 1];
        originM.setX(rhs.originM.getX());
        originM.setY(rhs.originM.getY());
    }

    return *this;
}

Shape::~Shape() { delete[] shapeNameM; }

const Point &Shape::getOrigin() const { return originM; }
char *Shape::getName() const { return shapeNameM; }

void Shape::display() const
{
    cout << fixed << setprecision(2);

    cout << "Shape Name: " << shapeNameM << endl
         << "X-coordinate: " << originM.getX() << endl
         << "Y-coordinate: " << originM.getY() << endl;
}

double Shape::distance(Shape &other)
{
    return sqrt(pow(other.getOrigin().getX() - originM.getX(), 2) + pow(other.getOrigin().getY() - originM.getY(), 2));
}

double Shape::distance(Shape &s1, Shape &s2)
{
    return sqrt(pow(s2.getOrigin().getX() - s1.getOrigin().getX(), 2) + pow(s2.getOrigin().getY() - s1.getOrigin().getY(), 2));
}

void Shape::move(double dx, double dy)
{
    originM.setX(originM.getX() + dx);
    originM.setY(originM.getY() + dy);
}