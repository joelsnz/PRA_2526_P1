#include "Shape.h"

Shape::Shape() : color("red") {}

Shape::Shape(std::string color) {
  std::string valid_colors[] = {"red", "green", "blue"};
  bool is_valid = false;
  for(std::string c : valid_colors) {
    if(color == c) {
      is_valid = true;
      break;
    }
  }

  if(!is_valid) throw std::invalid_argument("color invalido");

  this->color = color;
}

std::string Shape::get_color() const { return this->color; }

void Shape::set_color(std::string c) { this->color = c; }
