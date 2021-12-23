//
// Created by Razvan on 23-Dec-21.
//

#include "Catalog.h"

Catalog::Catalog(const std::string &nume, std::vector<Masina> &m) : nume(nume), m(m) {

    this->nume = nume;
    this->m = m;
}

const std::string &Catalog::getNume() const {
    return nume;
}

void Catalog::setNume(const std::string &Nume) {
    nume = Nume;
}

const std::vector<Masina> &Catalog::getM() const {
    return m;
}

void Catalog::setM(const std::vector<Masina> &M) {
    m = M;
}
