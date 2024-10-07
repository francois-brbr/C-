#include "cartesien.hpp"
#include <iostream> 

Cartesien::Cartesien() : X(0.0), Y(0.0) {}

Cartesien::Cartesien(const double abs, const double ord) : X(abs), Y(ord) {}

Cartesien::Cartesien(Polaire &p) {
    X = p.getDistance() * std::cos(p.getAngle() * M_PI / 180);
    Y = p.getDistance() * std::sin(p.getAngle() * M_PI / 180);
}

double Cartesien::getX() const {
    return X;
}

double Cartesien::getY() const {
    return Y;
}

void Cartesien::setX(const double x) {
    X = x;
}

void Cartesien::setY(const double y) {
    Y = y;
}

void Cartesien::afficher(std::ostream& flux) const {
    flux << "(x=" << X << ";y=" << Y << ")";
}

void Cartesien::convertir(Polaire &p) const {
    double a = std::atan2(Y,X) * 180 / M_PI;
    double d = std::hypot(X,Y);
    p.setAngle(a);
    p.setDistance(d);
}

void Cartesien::convertir(Cartesien &c) const {
    c.setX(X);
    c.setY(Y);
}

