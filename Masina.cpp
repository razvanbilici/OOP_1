//
// Created by Razvan on 23-May-22.
//

#include "Masina.h"

std::string Masina::cutieToString() const {

    switch(CV){

        case Automata:
            return "Automata";

        case Manuala:
            return "Manuala";

    }
    return "N/A";

}


cutieViteze Masina::getCv() const {
    return CV;
}

void Masina::setCv(cutieViteze cv) {
    CV = cv;
}

int Masina::getNumarUsi() const {
    return numarUsi;
}

void Masina::setNumarUsi(int numarUsi) {
    this->numarUsi = numarUsi;
}

Masina::Masina(const std::string &marca, const std::string &model, float motor, const std::string &culoare,
               SH secondHand, int anFabricatie, int km, int pret, float km100, cutieViteze CV, int nrUsi,
               const std::string &status) :
        Vehicul(marca, model, motor, culoare, secondHand, anFabricatie, km, pret, km100, status) {


    categorie = 'B';
    id += categorie + marca + std::to_string(anFabricatie);

    this->CV = CV;
    numarUsi = nrUsi;

    FileLog::append("Obiect MASINA creat");


}


Masina::Masina() : Vehicul() {

    numarUsi = -1;
    CV = na;
}


bool Masina::verificaDiscount() {
    std::cout << marca << " " << model << ", " << pret << " Euro - Se cauta discount...\n";

    if(discCheck || status == "Vandut") {

        std::cout << "Discount deja verificat / aplicat sau masina vanduta!\n\n";
        return false;
    }

    if(anFabricatie > 2005) {

        std::cout << marca << " " << model << ": Masina fabricata dupa anul 2005 - Fara Discount\n\n";
        discCheck = true;
        return false;
    }


    std::cout << marca << " " << model << ": Discount aplicabil de 5% - masina fabricata inainte de anul 2005\n";

    return true;

}

void Masina::Afis() {
    std::cout << "\n[[  ID MASINA: " << id << "  ]]" <<
              "\nMarca: " << marca <<
              "\nModel: " << model <<
              "\nMotor: " << motor <<
              "\nCuloare: " << culoare <<
              "\nSecond Hand: " << shToString() <<
              "\nAn Fabricatie: " << anFabricatie <<
              "\nkm: " << km <<
              "\nTimp 100km/h: " << km100 << "s" <<
              "\nCutie Viteza: " << cutieToString() <<
              "\nNumar Usi: " << numarUsi <<
              "\nPret: " << pret << " Euro"
              "\nStatus: " << status << "\n";

}

std::ostream &operator<<(std::ostream &os, const Masina &masina) {
    os << "\n[[  ID MASINA: " << masina.id << "  ]]"
       "\nMarca: " << masina.marca <<
       "\nModel: " << masina.model <<
       "\nMotor: " << masina.motor <<
       "\nCuloare: " << masina.culoare <<
       "\nSecond Hand: " << masina.shToString() <<
       "\nAn Fabricatie: " << masina.anFabricatie <<
       "\nkm: " << masina.km <<
       "\nTimp 100km/h: " << masina.km100 << "s" <<
       "\nCutie Viteza: " << masina.cutieToString() <<
       "\nNumar Usi: " << masina.numarUsi <<
       "\nPret: " << masina.pret << " Euro" <<
       "\nStatus: " << masina.status << "\n";
    return os;
}

//Pentru mostenire (masina electrica)
Masina::Masina(const std::string &marca, const std::string &model, float motor, const std::string &culoare,
               SH secondHand, int anFabricatie, int km, int pret, float km100, const std::string &status, int numarUsi)
        : Vehicul(marca, model, motor, culoare, secondHand, anFabricatie, km, pret, km100, status),
          numarUsi(numarUsi) {}

