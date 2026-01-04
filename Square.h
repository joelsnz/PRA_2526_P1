#ifndef SQUARE_H
#define SQUARE_H

#include "Point2D.h"
#include "Rectangle.h"
#include "Shape.h"

#include <iostream>
#include <stdexcept>

class Square : public Rectangle {
public:
  void print() override final;
  static bool check(Point2D *vertices);
  Square();
  Square(std::string color, Point2D *vertices);
  void set_vertices(Point2D *vertices) override final;
  friend std::ostream &operator<<(std::ostream &out, const Square &square);
};

#endif // SQUARE_H
