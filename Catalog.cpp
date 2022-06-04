//
// Created by Razvan on 23-May-22.
//

#include "Catalog.h"

void Catalog::showVehicule() const {

    for (Vehicul *vehicul : vehicule)
        vehicul->Afis();

}

Catalog::Catalog(const std::string &titlu, const std::vector<Vehicul *> &vehicule) {

    this->titlu = titlu;
    this->vehicule = vehicule;

    catalogNO++;

    id += std::to_string(catalogNO) + titlu;

}

Catalog::Catalog() {

    catalogNO++;
    id += std::to_string(catalogNO);

    titlu = "default";
    vehicule = {};

}

Catalog::~Catalog() {

    catalogNO--;

}

const std::string &Catalog::getTitlu() const {
    return titlu;
}

void Catalog::setTitlu(const std::string &titlu) {
    this->titlu = titlu;
}

const std::vector<Vehicul *> &Catalog::getVehicule() const {
    return vehicule;
}

void Catalog::setVehicule(const std::vector<Vehicul *> &vehicule) {
    this->vehicule = vehicule;
}

void Catalog::add(Vehicul &v) {

    vehicule.push_back(&v);

}

std::ostream &operator<<(std::ostream &os, const Catalog &catalog) {

    os << "\n[[  ID CATALOG: " << catalog.id << "  ]]"
       "\nTitlu: " << catalog.titlu <<
       "\nVehicule: " << "\n";

    catalog.showVehicule();

    os << "--Sfarsit--\n";
    return os;
}


