/*
 * File Name: shape.cpp
 * Assignment: Lab 1 Exercise B
 * Lab Section: B02
 * Completed by: Stephen Ravelo, Aaron Lauang
 * Submission Date: September 20, 2025
 */

#include <iostream>
#include <cmath>
#include <iomanip>
#include "shape.h"
using namespace std;

Shape::Shape(double x, double y, const char* shapeName) : originM(Point(x, y)) {
    shapeNameM = new char[strlen(shapeName) + 1];
    strcpy(shapeNameM, shapeName);
}

Shape& Shape::operator = (const Shape &rhs) {
    if (this != &rhs) {
        delete [] shapeNameM;
        shapeNameM = new char[strlen(rhs.shapeNameM) + 1];
        strcpy(shapeNameM, rhs.shapeNameM);
        originM.setX(rhs.originM.getX());
        originM.setY(rhs.originM.getY());
    }
    return *this;
}

Shape::Shape(const Shape &source) : originM(Point(source.originM.getX(), source.originM.getY())) {
    shapeNameM = new char[strlen(source.shapeNameM) + 1];
    strcpy(shapeNameM, source.shapeNameM);

}

Shape::~Shape() {
    delete [] shapeNameM;
}

const Point& Shape::getOrigin() const {
    return originM;
}

char* Shape::getName() const {
    return shapeNameM;
}

void Shape::setName(const char* shapeName) {
    if (shapeName) {
        delete [] shapeNameM;
        shapeNameM = new char[strlen(shapeName) + 1];
        strcpy(shapeNameM, shapeName);
    }
    else {
        delete [] shapeNameM;
        shapeNameM = nullptr;
    }
}

void Shape::display() const {
    cout << fixed;
    cout << setprecision(2);
    cout << "Shape Name: " << shapeNameM << endl;
    cout << "X-coordinate: " << originM.getX() << endl;
    cout << "Y-coordinate: " << originM.getY() << endl;
}

double Shape::distance(Shape& other) {
    return sqrt(pow(other.originM.getX() - originM.getX(), 2) + pow(other.originM.getY() - originM.getY(), 2));
}

double Shape::distance(Shape &s1, Shape &s2) {
    return sqrt(pow(s2.originM.getX() - s1.originM.getX(), 2) + pow(s2.originM.getY() - s1.originM.getY(), 2));

}

void Shape::move(double dx, double dy) {
    originM.setX(originM.getX() + dx);
    originM.setY(originM.getY() + dy);
}