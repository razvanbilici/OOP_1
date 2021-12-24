//
// Created by Razvan on 23-Dec-21.
//

#include "Cumparator.h"

const std::string &Cumparator::getNume() const {
    return nume;
}

void Cumparator::setNume(const std::string &Nume) {
    nume = Nume;
}

const std::string &Cumparator::getCnp() const {
    return CNP;
}

void Cumparator::setCnp(const std::string &cnp) {
    CNP = cnp;
}

const std::string &Cumparator::getCatPermis() const {
    return catPermis;
}

void Cumparator::setCatPermis(const std::string &CatPermis) {
    catPermis = CatPermis;
}

int Cumparator::getBuget() const {
    return buget;
}

void Cumparator::setBuget(int Buget) {
    buget = Buget;
}

Cumparator::Cumparator(const std::string &nume, const std::string &cnp, const std::string &catPermis, int buget) {

    this->nume = nume;
    CNP = cnp;
    this->catPermis = catPermis;
    this->buget = buget;

}

Cumparator::Cumparator() {

    nume = "noname";
    CNP = "0";
    catPermis = "xxxx";
    buget = -1;

}

void Cumparator::showCat() {

    std::cout << "Categorii Permis: ";

    for(int i = 0; i < catPermis.length(); i++) {
        std::cout << catPermis[i] << " ";
    }
}

void Cumparator::VerificarePermis(Masina &m) {

    std::cout << "\nSe cauta permis categoria " << m.getCategorie() << " pentru " << m.getMarca()
              << " " << m.getModel() << "...\n";
    size_t found = catPermis.find(m.getCategorie());

    if (found == std::string::npos) {

        std::cout << "Nu detineti permis categoria " << m.getCategorie() << "!\n\n";
        return ;
    }

    std::cout << "Permis verificat!\n\n";



}

bool Cumparator::Check(Catalog &c, int i) {

    size_t found = catPermis.find(c.getM()[i].getCategorie());

    if (found == std::string::npos || c.getM()[i].getStatus() == "Vandut" || buget < c.getM()[i].getPret()) {

        return false;
    }
    return true;
}

void Cumparator::Search(Catalog &c) {

    int results = 0;

    std::cout << "\nSe cauta masini pentru lista de categorii permis " << catPermis
              << " si bugetul de " << buget <<" Euro...\n\n";

    for(int i = 0; i < c.getM().size(); i++) {

        if (Check(c, i) == 1 && buget >= c.getM()[i].getPret()) {
            std::cout << c.getM()[i];
            results++;

        }
    }

    if(results) {
        std::cout << "\nIncheierea cautarii\n\n";
        return; }

    std::cout << "Nu s-au gasit rezultate!\n\n";

}

void Cumparator::Cumpara(Catalog &c, int i) {

    std::string cp;

    std::cout << "Doriti sa achizitionati " << c.getM()[i].getMarca() << " "
              << c.getM()[i].getModel() << " " << c.getM()[i].getAnFabricatie() << " ?(Da / Nu)\n";

    std::cin >> cp;

    if(cp == "Nu")  {
        std::cout << "\n";
        return; }

    if(Check(c, i) == 0) {
        std::cout << "Anunt indisponibil / Nu detineti categoria aferenta / Buget depasit\n\n";
        return; }

    std::cout << "Automobil achizitionat!\n\n";
    buget -=  c.getM()[i].getPret();

    //Aici ar trebui sa schimb statusul cu c.getM()[i].setStatus("Vandut"), dar nu merge

}

std::ostream &operator<<(std::ostream &os, Cumparator &cumparator) {
    os << "\nNume: " << cumparator.nume
       << "\nCNP: " << cumparator.CNP << "\n";
    cumparator.showCat();                   //*Am evitat invalid use of non-static data member
    os << "\nBuget: " << cumparator.buget << " Euro\n\n";
    return os;
}
