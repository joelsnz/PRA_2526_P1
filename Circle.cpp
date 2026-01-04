#include "Circle.h"

#include <cmath>
#include <iostream>

Circle::Circle() : Shape(), center(Point2D()), radius(1) {}

Circle::Circle(std::string color, Point2D center, double radius)
    : Shape(color), center(center), radius(radius) {}

Point2D Circle::get_center() const { return center; }

void Circle::set_center(Point2D p) { center = p; }

double Circle::get_radius() const { return radius; }

void Circle::set_radius(double r) { radius = r; }

std::ostream &operator<<(std::ostream &out, const Circle &c) {
  out << "[Circle: color = " << c.color << "; ";
  out << "center = " << c.center << "; radius = " << c.radius << "]";
  return out;
}

double Circle::area() const { return M_PI * pow(radius, 2); }

double Circle::perimeter() const { return 2 * M_PI * radius; }

void Circle::translate(double incX, double incY) {
  center.x += incX;
  center.y += incY;
}

void Circle::print() { std::cout << *this; }
