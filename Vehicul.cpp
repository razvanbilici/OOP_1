//
// Created by Razvan on 23-May-22.
//

#include "Vehicul.h"

std::string Vehicul::shToString() const {

    switch(secondHand){

        case Nu:
            return "Nu";

        case Da:
            return "Da";

    }
    return "N/A";

}

int Vehicul::getVehiculNo() {
    return vehiculNO;
}

const std::string &Vehicul::getMarca() const {
    return marca;
}

void Vehicul::setMarca(const std::string &marca) {
    this->marca = marca;
}

const std::string &Vehicul::getModel() const {
    return model;
}

void Vehicul::setModel(const std::string &model) {
    this->model = model;
}

float Vehicul::getMotor() const {
    return motor;
}

void Vehicul::setMotor(float motor) {
    this->motor = motor;
}

const std::string &Vehicul::getCuloare() const {
    return culoare;
}

void Vehicul::setCuloare(const std::string &culoare) {
    this->culoare = culoare;
}

SH Vehicul::getSecondHand() const {
    return secondHand;
}

void Vehicul::setSecondHand(SH secondHand) {
    this->secondHand = secondHand;
}

char Vehicul::getCategorie() const {
    return categorie;
}

void Vehicul::setCategorie(char categorie) {
    this->categorie = categorie;
}

int Vehicul::getAnFabricatie() const {
    return anFabricatie;
}

void Vehicul::setAnFabricatie(int anFabricatie) {
    this->anFabricatie = anFabricatie;
}

int Vehicul::getKm() const {
    return km;
}

void Vehicul::setKm(int km) {
    this->km = km;
}

int Vehicul::getPret() const {
    return pret;
}

void Vehicul::setPret(int pret) {
    this->pret = pret;
}

float Vehicul::getKm100() const {
    return km100;
}

void Vehicul::setKm100(float km100) {
    this->km100 = km100;
}

const std::string &Vehicul::getStatus() const {
    return status;
}

void Vehicul::setStatus(const std::string &status) {
    this->status = status;
}

bool Vehicul::isDiscCheck() const {
    return discCheck;
}

void Vehicul::setDiscCheck(bool discCheck) {
    this->discCheck = discCheck;
}

const std::string &Vehicul::getId() const {
    return id;
}

Vehicul::Vehicul(const std::string &marca, const std::string &model, float motor, const std::string &culoare,
                 SH secondHand, int anFabricatie, int km, int pret, float km100, const std::string &status) {

    if (motor <= 0)
        throw motor_error();

    if(secondHand == Nu && km != 0)
        throw shKM_error();

    vehiculNO++;

    id += std::to_string(vehiculNO);

    discCheck = false;

    this->marca = marca;
    this->model = model;
    this->motor = motor;
    this->culoare = culoare;
    this->secondHand = secondHand;

    this->anFabricatie = anFabricatie;
    this->km = km;
    this->pret = pret;
    this->km100 = km100;
    this->status = status;

}

Vehicul::Vehicul() {

    vehiculNO++;

    marca = "noname";
    model = "noname";
    motor = -1.0;
    culoare = "N/A";
    secondHand = NA;
    categorie = '0';
    anFabricatie = -1;
    pret = -1;
    km = -1;
    km100 = -1;
    status = "N/A";
    discCheck = false;
}

Vehicul::~Vehicul() {

    vehiculNO--;

}

Vehicul::Vehicul(const Vehicul &copy) {

    this->marca = copy.marca;
    this->model = copy.model;
    this->motor = copy.motor;
    this->culoare = copy.culoare;
    this->secondHand = copy.secondHand;
    this->categorie = copy.categorie;
    this->anFabricatie = copy.anFabricatie;
    this->km = copy.km;
    this->pret = copy.pret;
    this->km100 = copy.km100;
    this->status = copy.status;
    this->discCheck = copy.discCheck;

    vehiculNO++;

    id += std::to_string(vehiculNO) + categorie + marca + std::to_string(anFabricatie);

}

void Vehicul::showTimer100() const {

    std::cout << "\n" << marca << " " << model << " - Timer 100 km/h:\n";

    int secunde = 1;

    std::cout << "0s...0 km/h\nAccelerare...\n";

    for(int j = 0; j < int(floor(km100)); j++){

        for(int i = 0 ; i < 1 ; i++) {

            std::this_thread::sleep_for(std::chrono::seconds(1));

        }

        std::cout << secunde << "s...\n";
        secunde++;
    }


    std::this_thread::sleep_for(std::chrono::milliseconds(int((km100 - floor(km100)) * 1000)));


    std::cout << km100 << "s...100 km/h\n\n";

}

void Compara(Vehicul &v1, Vehicul &v2) {

    std::cout << "\nCompara autovehicule:\n";

    double p1, p2;     //Puncte avantaj

    std::cout << v1.marca << " " << v1.model << " " << v1.anFabricatie << ", motor " << v1.motor
              << ": " << v1.pret << " Euro, " << v1.km << " Km, Categorie permis: " << v1.categorie
              << ", Second Hand: " << v1.shToString() << "\n";

    std::cout << v2.marca << " " << v2.model << " " << v2.anFabricatie << ", motor " << v2.motor
              << ": " << v2.pret << " Euro, " << v2.km << " Km, Categorie permis: " << v2.categorie
              << ", Second Hand: " << v2.shToString() << "\n\n";

    if(v1.categorie != v2.categorie){

        std::cout << "Categorii diferite - Nu se pot compara!\n\n";
        return ;
    }

    //Masina mai noua, motor mai mare, pret mai mic -> punctaj mai mare
    p1 = v1.motor * 10 + v1.anFabricatie * 0.001 - v1.pret / 100000 - v1.km / 100000;
    p2 = v2.motor * 10 + v2.anFabricatie * 0.001 - v2.pret / 100000 - v2.km / 100000;

    if(v1.secondHand == Nu)
        p1 += 10;

    if(v2.secondHand == Nu)
        p2 += 10;

    std::cout << "Puncte avantaj " << v1.marca << " " << v1.model << ": " << p1
              << "\nPuncte avantaj " << v2.marca << " " << v2.model << ": " << p2 << "\n";

    if(p1 > p2) {
        std::cout << "Deal mai avantajos: " << v1.marca << " " << v1.model << ", " << v1.pret << " Euro\n\n";
        return ; }

    if(p2 > p1) {
        std::cout << "Deal mai avantajos: " << v2.marca << " " << v2.model << ", " << v2.pret << " Euro\n\n";
        return ; }

    std::cout << "Numar egal de puncte avantaj!\n\n";


}




