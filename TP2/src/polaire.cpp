#include "polaire.hpp"
#include <iostream>

Polaire::Polaire() : angle(0.0), distance(0.0) {}

Polaire::Polaire(const double a, const double b) : angle(a), distance(b) {}

Polaire::Polaire(Cartesien &c) {
    angle = std::atan2(c.getY(),c.getX()) * 180 / M_PI;
    distance = std::hypot(c.getX(), c.getY());
}

double Polaire::getAngle() const {
    return angle;
}

double Polaire::getDistance() const {
    return distance;
}

void Polaire::setAngle(const double a) {
    angle = a;
}

void Polaire::setDistance(const double b) {
    distance = b;
}

void Polaire::afficher(std::ostream& flux) const {
    flux << "(a=" << angle << ";d=" << distance << ")";
}

void Polaire::convertir(Cartesien &c) const {
    double x = distance * std::cos(angle * M_PI / 180);
    double y = distance * std::sin(angle * M_PI / 180);
    c.setX(x);
    c.setY(y);
}

void Polaire::convertir(Polaire &p) const {
    p.setAngle(angle);
    p.setDistance(distance);
}
