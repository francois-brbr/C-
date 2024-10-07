#ifndef POLAIRE_HPP
#define POLAIRE_HPP   

#include "point.hpp"
#include "cartesien.hpp"
#include <iostream>
#include <sstream>
#include <cmath>

class Polaire : public Point {
    
    double angle;
    double distance;

    public:
        Polaire();
        Polaire(const double, const double);
        Polaire(Cartesien &c);
        double getAngle() const;
        double getDistance() const;
        void setAngle(const double);
        void setDistance(const double);
        void afficher(std::ostream&) const;
        void convertir(Cartesien &c) const override;
        void convertir(Polaire &p) const override;
};

#endif