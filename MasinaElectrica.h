//
// Created by Razvan on 04-Jun-22.
//

#ifndef MAIN_CPP_MASINAELECTRICA_H
#define MAIN_CPP_MASINAELECTRICA_H


#include "Masina.h"

class MasinaElectrica : virtual public Masina {

private:

    float baterie; //kWh;
    bool fastCharge;

public:
    MasinaElectrica(const std::string &marca, const std::string &model, float motor, const std::string &culoare,
                    SH secondHand, int anFabricatie, int km, int pret, float km100, const std::string &status,
                    int numarUsi, float baterie, bool fastCharge);

    float getBaterie() const;

    void setBaterie(float baterie);

    bool isFastCharge() const;

    void setFastCharge(bool fastCharge);

    ~MasinaElectrica() override = default;

    bool verificaDiscount() override;

    void Afis() override;

};


#endif //MAIN_CPP_MASINAELECTRICA_H
