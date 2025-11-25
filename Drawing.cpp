#include "Drawing.h"

#include "Circle.h"
#include "ListLinked.h"
#include "Square.h"

Drawing::Drawing() { this->shapes = new ListLinked<Shape *>(); }

Drawing::~Drawing() { delete this->shapes; }

void Drawing::add_front(Shape *shape) {
  this->shapes->prepend(shape);
}

void Drawing::add_back(Shape *shape) { this->shapes->append(shape); }

void Drawing::print_all() {
  int size = this->shapes->size();
  for(int i = 0; i < size; i++) {
    this->shapes->get(i)->print();
    std::cout << std::endl;
  }
}

double Drawing::get_area_all_circles() {
  int size = this->shapes->size();
  double area = 0;
  for(int i = 0; i < size; i++) {
    Circle *c = dynamic_cast<Circle *>(this->shapes->get(i));
    if(c != nullptr) area += c->area();
  }
  return area;
}

void Drawing::move_squares(double incX, double incY) {
  int size = this->shapes->size();
  for(int i = 0; i < size; i++) {
    Square *s = dynamic_cast<Square *>(this->shapes->get(i));
    if(s != nullptr) s->translate(incX, incY);
  }
}
