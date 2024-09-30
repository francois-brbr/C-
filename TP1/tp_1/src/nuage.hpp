#ifndef NUAGE_HPP
#define NUAGE_HPP

#include <vector>
#include "point.hpp"
#include "cartesien.hpp"
#include "polaire.hpp"

class Nuage {
    private:
        std::vector<Point*> points; 

    public:
        using const_iterator = std::vector<Point*>::const_iterator;
        using iterator = std::vector<Point*>::iterator;
        Nuage() = default;
        const_iterator begin() const;
        const_iterator end() const;
        void ajouter(Point& p);
        std::size_t size() const;
};

Cartesien barycentre(const Nuage &n);

#endif