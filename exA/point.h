/*
 * File Name: point.h
 * Assignment: Lab 1 Exercise B
 * Lab Section: B02
 * Completed by: Stephen Ravelo, Aaron Lauang
 * Submission Date: September 20, 2025
 */

#ifndef POINT_H
#define POINT_H

class Point
{
public:
    Point(double x, double y);

    double getX() const;
    void setX(const double x);
    double getY() const;
    void setY(const double y);
    int getID() const;

    void display() const;
    static int counter();
    double distance (Point &other);
    static double distance(Point &p1,Point &p2);

private:
    double xM;
    double yM;
    const int ID;
    static int count;
};

#endif