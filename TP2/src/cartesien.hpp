#ifndef CARTESIEN_HPP
#define CARTESIEN_HPP   

#include "point.hpp"
#include "polaire.hpp"
#include <iostream>
#include <sstream>
#include <cmath>

class Cartesien : public Point {
    
    double X;
    double Y;

    public:
        Cartesien();
        Cartesien(const double, const double);
        Cartesien(Polaire &p);
        double getX() const;
        double getY() const;
        void setX(const double);
        void setY(const double);
        void afficher(std::ostream&) const;
        void convertir(Polaire &p) const override;
        void convertir(Cartesien &c) const override;
};

#endif