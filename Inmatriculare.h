//
// Created by Razvan on 04-Jun-22.
//

#ifndef MAIN_CPP_INMATRICULARE_H
#define MAIN_CPP_INMATRICULARE_H

#include "MasinaElectrica.h"

template <typename T>
class Inmatriculare {

    T codInmatriculare;
    std::string oras;
    std::shared_ptr<Vehicul> vehicul;

public:
    Inmatriculare(T codInmatriculare, const std::string &oras, const std::shared_ptr<Vehicul> &vehicul)
            : codInmatriculare(codInmatriculare), oras(oras), vehicul(vehicul) {};

    ~Inmatriculare() = default;



};


#endif //MAIN_CPP_INMATRICULARE_H
