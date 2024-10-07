#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>

class Cartesien;
class Polaire;

class Point {
    public:
        Point();
        virtual void afficher(std::ostream&) const = 0;
        virtual void convertir(Cartesien &c) const = 0;
        virtual void convertir(Polaire &p) const = 0;
};

std::ostream& operator<<(std::ostream& os, const Point& p);

#endif