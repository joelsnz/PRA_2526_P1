#include "Point2D.h"
#include <cmath>

Point2D::Point2D(double x, double y) : x(x), y(y) {}

double Point2D::distance(const Point2D& a, const Point2D& b) {
  double x_diff = pow((a.x - b.x), 2);
  double y_diff = pow((a.y - b.y), 2);

  return sqrt(x_diff + y_diff);
}

bool operator==(const Point2D& a, const Point2D& b) {
  return (a.x == b.x) && (a.y == b.y);
}

bool operator!=(const Point2D& a, const Point2D& b) {
  return (a.x != b.x) || (a.y != b.y);
}

std::ostream& operator<<(std::ostream& out, const Point2D& p) {
  out << "(" << p.x << ", " << p.y << ")";
  return out;
}
