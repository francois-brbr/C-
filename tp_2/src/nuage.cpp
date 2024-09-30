#include "nuage.hpp"
#include "cartesien.hpp"
#include "polaire.hpp"

void Nuage::ajouter(Point& p) {
    points.push_back(&p); 
}

std::size_t Nuage::size() const {
    return points.size(); 
}

Nuage::const_iterator Nuage::begin() const {
    return points.begin();
}

Nuage::const_iterator Nuage::end() const {
    return points.end();
}

Cartesien barycentre(const Nuage &n) {
    double sommeX = 0.0;
    double sommeY = 0.0;
    
    for (const auto& point : n) {
        Cartesien cart;
        point->convertir(cart); // Conversion des points en Cartesien
        sommeX += cart.getX();
        sommeY += cart.getY();
    }
    
    // Calcul du barycentre en prenant la moyenne des coordonnées X et Y
    double moyX = sommeX / n.size();
    double moyY = sommeY / n.size();
    
    return Cartesien(moyX, moyY);
}