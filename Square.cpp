#include "Square.h"

bool Square::check(Point2D *vertices) {
  double arista_sup = Point2D::distance(vertices[0], vertices[1]);
  double arista_inf = Point2D::distance(vertices[2], vertices[3]);
  double arista_izq = Point2D::distance(vertices[0], vertices[3]);
  double arista_der = Point2D::distance(vertices[1], vertices[2]);

  return (arista_sup == arista_inf) && (arista_izq == arista_der) &&
         (arista_sup == arista_izq);
}

Square::Square() : Rectangle() {
  this->vs[0] = Point2D(-1, 1);
  this->vs[1] = Point2D(1, 1);
  this->vs[2] = Point2D(1, -1);
  this->vs[3] = Point2D(-1, -1);
}

Square::Square(std::string color, Point2D *vertices) : Rectangle() {
  this->color = color;
  if(!Square::check(vertices))
    throw std::invalid_argument("Cuadrado invalido");
  for(int i = 0; i < N_VERTICES; i++)
    this->vs[i] = vertices[i];
}

void Square::set_vertices(Point2D *vertices) {
  if(!Square::check(vertices))
    throw std::invalid_argument("Cuadrado invalido");
  for(int i = 0; i < N_VERTICES; i++)
    this->vs[i] = vertices[i];
}

std::ostream &operator<<(std::ostream &out, const Square &square) {
  out << "[Square: color = " << square.color;
  for(int i = 0; i < Rectangle::N_VERTICES; i++) {
    out << "; v" << i << " = " << square.vs[i];
  }
  out << "]";

  return out;
}

void Square::print() { std::cout << *this; }
