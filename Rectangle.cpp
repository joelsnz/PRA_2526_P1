#include "Rectangle.h"

bool Rectangle::check(Point2D *vertices) {
  double arista_sup = Point2D::distance(vertices[0], vertices[1]);
  double arista_inf = Point2D::distance(vertices[2], vertices[3]);
  double arista_izq = Point2D::distance(vertices[0], vertices[3]);
  double arista_der = Point2D::distance(vertices[1], vertices[2]);

  return (arista_sup == arista_inf) && (arista_izq == arista_der);
}

Rectangle::Rectangle() : Shape() {
  this->vs = new Point2D[N_VERTICES];
  this->vs[0] = Point2D(-1, 0.5);
  this->vs[1] = Point2D(1, 0.5);
  this->vs[2] = Point2D(1, -0.5);
  this->vs[3] = Point2D(-1, -0.5);
}

Rectangle::Rectangle(std::string color, Point2D *vertices)
    : Shape(color) {
  if(!Rectangle::check(vertices))
    throw std::invalid_argument("Provided vertices do not build a valid rectangle");
  this->vs = new Point2D[N_VERTICES];
  for(int i = 0; i < N_VERTICES; i++)
    this->vs[i] = vertices[i];
}

Rectangle::Rectangle(const Rectangle &r) : Shape(r.color) {
  this->vs = new Point2D[N_VERTICES];
  for(int i = 0; i < N_VERTICES; i++)
    this->vs[i] = r.vs[i];
}

Rectangle::~Rectangle() { delete[] this->vs; }

Point2D Rectangle::get_vertex(int ind) const {
  if(ind >= N_VERTICES) throw std::out_of_range("Invalid index");
  return this->vs[ind];
}

Point2D Rectangle::operator[](int ind) const {
  return get_vertex(ind);
}

void Rectangle::set_vertices(Point2D *vertices) {
  if(!Rectangle::check(vertices))
    throw std::invalid_argument("Provided vertices do not build a valid rectangle");
  this->vs = new Point2D[N_VERTICES];
  for(int i = 0; i < N_VERTICES; i++)
    this->vs[i] = vertices[i];
}

Rectangle &Rectangle::operator=(const Rectangle &r) {
  this->color = r.color;
  delete[] this->vs;
  this->vs = new Point2D[N_VERTICES];
  for(int i = 0; i < N_VERTICES; i++)
    this->vs[i] = r.vs[i];

  return *this;
}

std::ostream &operator<<(std::ostream &out, const Rectangle &r) {
  out << "[Rectangle: color = " << r.color;
  for(int i = 0; i < Rectangle::N_VERTICES; i++) {
    out << "; v" << i << " = " << r.vs[i];
  }
  out << "]";

  return out;
}

double Rectangle::area() const {
  double base = Point2D::distance(this->vs[2], this->vs[3]);
  double altura = Point2D::distance(this->vs[0], this->vs[3]);

  return base * altura;
}

double Rectangle::perimeter() const {
  double base = Point2D::distance(this->vs[2], this->vs[3]);
  double altura = Point2D::distance(this->vs[0], this->vs[3]);

  return (base + altura) * 2;
}

void Rectangle::translate(double incX, double incY) {
  for(int i = 0; i < N_VERTICES; i++) {
    this->vs[i].x += incX;
    this->vs[i].y += incY;
  }
}

void Rectangle::print() { std::cout << *this; }
