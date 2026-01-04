#include "Drawing.h"

#include "Circle.h"
#include "ListLinked.h"
#include "Square.h"

Drawing::Drawing() { shapes = new ListLinked<Shape *>(); }

Drawing::~Drawing() { delete shapes; }

void Drawing::add_front(Shape *shape) { shapes->prepend(shape); }

void Drawing::add_back(Shape *shape) { shapes->append(shape); }

void Drawing::print_all() {
  int size = shapes->size();
  for (int i = 0; i < size; i++) {
    shapes->get(i)->print();
    std::cout << std::endl;
  }
}

double Drawing::get_area_all_circles() {
  int size = shapes->size();
  double area = 0;
  for (int i = 0; i < size; i++) {
    Circle *c = dynamic_cast<Circle *>(shapes->get(i));
    if (c != nullptr) // casted c is a circle
      area += c->area();
  }
  return area;
}

void Drawing::move_squares(double incX, double incY) {
  int size = shapes->size();
  for (int i = 0; i < size; i++) {
    Square *s = dynamic_cast<Square *>(shapes->get(i));
    if (s != nullptr) // casted s is a square
      s->translate(incX, incY);
  }
}
