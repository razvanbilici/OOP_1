//
// Created by Razvan on 24-Dec-21.
//

#include "MasinaElectrica.h"

MasinaElectrica::MasinaElectrica(const std::string &marca, const std::string &model, float motor,
                                 const std::string &culoare, const std::string &secondHand, char categorie,
                                 int anFabricatie, int km, int pret, float km100, const std::string &status,
                                 int baterie, char fastCharging) : Masina(marca, model, motor, culoare,
                                                                          secondHand, categorie,
                                                                          anFabricatie, km, pret, km100,
                                                                          status){

    Baterie = baterie;
    FastCharging = fastCharging;
}

void MasinaElectrica::afis() {

    std::cout << "Marca: " << marca
              << "\nModel: " << model
              << "\nCapacitate cilindrica motor (L): " << motor
              << "\nCuloare: " << culoare
              << "\nSecond Hand (Da / Nu): " << second_hand
              << "\nCategorie Permis Conducere: " << categorie
              << "\nAnul Fabricarii: " << an_fabricatie
              << "\nKm: " << km
              << "\nPret: " << pret << " Euro"
              << "\nTimp 100 km/h (s): " << km100
              << "\nStatus: " << status
              << "\nBaterie: "<< Baterie << "kW"
              << "\nFast Charging (Y / N): " << FastCharging << "\n\n";

}

void MasinaElectrica::AplicaDiscount() {

    std::cout << marca << " " << model << ", " << pret << " Euro - Se cauta discount...\n";

    if(discCheck == 0 || status == "Vandut") {   //In implementarea initiala se putea aplica discount-ul la infinit

        std::cout << "Discount deja verificat / aplicat sau masina vanduta!\n\n";
        return ;
    }

    if(FastCharging == 'Y') {

        std::cout << marca << " " << model << ": Masina cu Fast Charging - Fara Discount\n\n";
        discCheck = false;
        return;
    }


    std::cout << marca << " " << model << ": Discount de 5% - Masina fara Fast Charging\n";

    pret -= pret / 20;

    std::cout << "Pret actualizat: " << marca << " " << model << " - " << pret << " Euro\n\n";

    discCheck = false;

}

void MasinaElectrica::ShowTimer100() const {

    std::cout << "\n" << marca << " " << model << " " << ", Baterie: " << Baterie
              << "kW" << " - Timer 100 km/h:\n";

    int secunde = 1;

    std::cout << "0s...0 km/h\nAccelerare...\n";

    for(int j = 0; j < int(floor(km100)); j++){

        for(int i = 0 ; i < 1 ; i++) {

            usleep(pow(1000, 2));

        }

        std::cout << secunde << "s...\n";
        secunde++;
    }


    usleep((km100 - floor(km100)) * 1000000);

    std::cout << km100 << "s...100 km/h\n\n";

}
