//
// Created by Razvan on 23-May-22.
//

#ifndef POO_PROJV2_CATALOG_H
#define POO_PROJV2_CATALOG_H


#include <vector>
#include <memory>
#include <ostream>
#include "Vehicul.h"

class Catalog {

    static int catalogNO;
    std::string id;

    std::string titlu;
    std::vector<Vehicul *> vehicule;

    void showVehicule() const;

public:

    Catalog(const std::string &titlu, const std::vector<Vehicul *> &vehicule);

    Catalog();;

    ~Catalog();

    const std::string &getTitlu() const;

    void setTitlu(const std::string &titlu);

    const std::vector<Vehicul*> &getVehicule() const;

    void setVehicule(const std::vector<Vehicul*> &vehicule);

    void add(Vehicul &v);

    friend std::ostream &operator<<(std::ostream &os, const Catalog &catalog);


};


#endif //POO_PROJV2_CATALOG_H
