//
// Created by Razvan on 04-Jun-22.
//

#include "MasinaElectrica.h"


float MasinaElectrica::getBaterie() const {
    return baterie;
}

void MasinaElectrica::setBaterie(float baterie) {
    MasinaElectrica::baterie = baterie;
}

bool MasinaElectrica::isFastCharge() const {
    return fastCharge;
}

void MasinaElectrica::setFastCharge(bool fastCharge) {
    MasinaElectrica::fastCharge = fastCharge;
}

bool MasinaElectrica::verificaDiscount() {
    std::cout << marca << " " << model << ", " << pret << " Euro - Se cauta discount...\n";

    if(discCheck || status == "Vandut") {

        std::cout << "Discount deja verificat / aplicat sau masina vanduta!\n\n";
        return false;
    }

    if(fastCharge) {

        std::cout << marca << " " << model << ": Masina Electrica cu FAST CHARGING - Fara Discount\n\n";
        discCheck = true;
        return false;
    }


    std::cout << marca << " " << model << ": Discount aplicabil de 5% - Masina Electrica fara FAST CHARGING\n";

    return true;

}

void MasinaElectrica::Afis() {

    Masina::Afis();

    std::cout << "Baterie(kWh): " << baterie << "\n";

    if(!fastCharge) {
        std::cout << "Fast Charging: NU\n\n";
        return; }

    std::cout << "Fast Charging: DA\n\n";

}

MasinaElectrica::MasinaElectrica(const std::string &marca, const std::string &model, float motor,
                                 const std::string &culoare, SH secondHand, int anFabricatie, int km, int pret,
                                 float km100, const std::string &status, int numarUsi, float baterie, bool fastCharge)
        : Masina(marca, model, motor, culoare, secondHand, anFabricatie, km, pret, km100, status, numarUsi),
          baterie(baterie), fastCharge(fastCharge) {

    categorie = 'B';
    id += categorie + marca + std::to_string(anFabricatie);

    CV = Automata;
}
