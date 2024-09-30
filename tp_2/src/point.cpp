#include "point.hpp"

Point::Point() {}

std::ostream& operator<<(std::ostream& os, const Point& p) {
    p.afficher(os);
    return os;
}