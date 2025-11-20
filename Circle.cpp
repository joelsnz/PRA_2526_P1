#include "Circle.h"
#include <cmath>
#include <iostream>

Circle::Circle() : Shape(), center(Point2D()), radius(1) {}

Circle::Circle(std::string color, Point2D center, double radius) :
                Shape(color), center(center), radius(radius) {}

Point2D Circle::get_center() const {
  return this->center;
}

void Circle::set_center(Point2D p) {
  this->center = p;
}

double Circle::get_radius() const {
  return this->radius;
}

void Circle::set_radius(double r) {
  this->radius = r;
}

std::ostream& operator<<(std::ostream& out, const Circle& c) {
  out << "Center: " << c.center << "\tRadius: " << c.radius;
  return out;
}

double Circle::area() const { return M_PI * pow(this->radius, 2); }

double Circle::perimeter() const { return 2 * M_PI * this->radius; }

void Circle::translate(double incX, double incY) {
  this->center.x += incX;
  this->center.y += incY;
}

void Circle::print() { std::cout << *this; }
