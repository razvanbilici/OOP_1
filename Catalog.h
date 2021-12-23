//
// Created by Razvan on 23-Dec-21.
//

#ifndef OOP_CATALOG_H
#define OOP_CATALOG_H


#include <string>
#include <vector>
#include "Masina.h"

class Catalog{

    std::string nume;       // Colectia toamna / primavara / etc ??

    std::vector <Masina> &m;

public:

    Catalog(const std::string &nume, std::vector<Masina> &m);

    Catalog();

    //Getteri, setteri
    const std::string &getNume() const;
    void setNume(const std::string &Nume);
    const std::vector<Masina> &getM() const;
    void setM(const std::vector<Masina> &M);

};

#endif //OOP_CATALOG_H
