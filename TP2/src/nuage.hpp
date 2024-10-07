#ifndef NUAGE_HPP
#define NUAGE_HPP

#include <vector>
#include <cstddef>
#include "cartesien.hpp"
#include "point.hpp"
#include "polaire.hpp"

template <typename T>
class Nuage {
public:
    using iterator = typename std::vector<T>::iterator;
    using const_iterator = typename std::vector<T>::const_iterator;
    
private:
    std::vector<T> points;

public:
    // Ajouter un point au nuage
    void ajouter(const T& p) {
        points.push_back(p);
    }

    // Obtenir la taille du nuage
    std::size_t size() const {
        return points.size();
    }

    // Retourner un itérateur constant sur le début
    const_iterator begin() const {
        return points.begin();
    }

    // Retourner un itérateur constant sur la fin
    const_iterator end() const {
        return points.end();
    }
};

template <typename typePoint>
typePoint barycentre_v1(const Nuage<typePoint>& nuage) {
    if (nuage.size() == 0) {
        return typePoint(); // Retourner un point par défaut si le nuage est vide
    }

    double sommeX = 0.0;
    double sommeY = 0.0;

    for (const auto& point : nuage) {
        Cartesien c;
        point.convertir(c);  // Convertir en Cartesien quel que soit le type de point
        sommeX += c.getX();
        sommeY += c.getY();
    }

    // Calculer les coordonnées moyennes
    sommeX /= nuage.size();
    sommeY /= nuage.size();

    // Retourner le barycentre en tant que typePoint
    Cartesien c(sommeX, sommeY);
    typePoint res;
    c.convertir(res);  // Reconvertir en typePoint (Cartesien ou Polaire)
    return res;
}



#endif // NUAGE_HPP