//
// Created by Razvan on 23-Dec-21.
//

#ifndef OOP_CUMPARATOR_H
#define OOP_CUMPARATOR_H


#include <iostream>
#include "Catalog.h"

class Cumparator {

    std::string nume;
    std::string CNP;

    std::string catPermis;  //ex. ABC daca are mai multe categorii

    int buget;

public:

    const std::string &getNume() const;
    void setNume(const std::string &Nume);
    const std::string &getCnp() const;
    void setCnp(const std::string &cnp);
    const std::string &getCatPermis() const;
    void setCatPermis(const std::string &CatPermis);
    int getBuget() const;
    void setBuget(int Buget);

    Cumparator(const std::string &nume, const std::string &cnp, const std::string &catPermis, int buget);;

    Cumparator();


    //Pentru operatorul << de mai jos
    void showCat();


    //Pentru afisare direct pe ecran
    void VerificarePermis(Masina &m);


    //Pentru functia Search de mai jos
    bool Check(Catalog &c, int i);

    void Search(Catalog &c);

    void Cumpara(Catalog &c, int i);

    friend std::ostream &operator<<(std::ostream &os, Cumparator &cumparator);


};


#endif //OOP_CUMPARATOR_H
