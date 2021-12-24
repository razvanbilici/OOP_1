//
// Created by Razvan on 24-Dec-21.
//

#ifndef OOP_MASINAELECTRICA_H
#define OOP_MASINAELECTRICA_H

#include "Masina.h"


class MasinaElectrica : public Masina {

    int Baterie;    // kW
    char FastCharging;  // Y/N

public:

    MasinaElectrica(const std::string &marca, const std::string &model, float motor, const std::string &culoare,
                    const std::string &secondHand, char categorie, int anFabricatie, int km, int pret, float km100,
                    const std::string &status, int baterie, char fastCharging);

    void afis() override;

    void AplicaDiscount() override;

    void ShowTimer100() const override;


};


#endif //OOP_MASINAELECTRICA_H
