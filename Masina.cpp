//
// Created by Razvan on 23-Dec-21.
//

#include "Masina.h"

const std::string &Masina::getMarca() const {
    return marca;
}

void Masina::setMarca(const std::string &Marca) {
    marca = Marca;
}

const std::string &Masina::getModel() const {
    return model;
}

void Masina::setModel(const std::string &Model) {
    model = Model;
}

const std::string &Masina::getCuloare() const {
    return culoare;
}

void Masina::setCuloare(const std::string &Culoare) {
    culoare = Culoare;
}

const std::string &Masina::getSecondHand() const {
    return second_hand;
}

void Masina::setSecondHand(const std::string &secondHand) {
    second_hand = secondHand;
}

char Masina::getCategorie() const {
    return categorie;
}

void Masina::setCategorie(char Categorie) {
    categorie = Categorie;
}

int Masina::getAnFabricatie() const {
    return an_fabricatie;
}

void Masina::setAnFabricatie(int anFabricatie) {
    an_fabricatie = anFabricatie;
}

int Masina::getKm() const {
    return km;
}

void Masina::setKm(int Km) {
    Masina::km = Km;
}

int Masina::getPret() const {
    return pret;
}

void Masina::setPret(int Pret) {
    pret = Pret;
}

float Masina::getKm100() const {
    return km100;
}

void Masina::setKm100(float Km100) {
    km100 = Km100;
}

float Masina::getMotor() const {
    return motor;
}

void Masina::setMotor(float Motor) {
    motor = Motor;
}

const std::string &Masina::getStatus() const {
    return status;
}

void Masina::setStatus(const std::string &Status) {
    status = Status;
}

bool Masina::isDiscCheck() const {
    return discCheck;
}

Masina::Masina(const std::string &marca, const std::string &model, float motor, const std::string &culoare,
               const std::string &secondHand, char categorie, int anFabricatie, int km, int pret, float km100,
               const std::string &status) {

    this->marca = marca;
    this->model = model;

    this->motor = motor;

    this->culoare = culoare;
    second_hand = secondHand;

    this->categorie = categorie;

    an_fabricatie = anFabricatie;
    this->km = km;
    this->pret = pret;

    this->km100 = km100;

    this->status = status;

    discCheck = true;
}

Masina::Masina() {

    marca = "noname";
    model = "nn";

    motor = -1;

    culoare = "N/A";
    second_hand = "N/A";

    categorie = 'x';

    an_fabricatie = -1;
    km = -1;
    pret = -1;

    km100 = -1;

    status = "N/A";

    discCheck = true;

}

Masina::Masina(const Masina &copy) {

    this->marca = copy.marca;
    this->model = copy.model;

    this->motor = copy.motor;

    this->culoare = copy.culoare;
    this->second_hand = copy.second_hand;

    this->categorie = copy.categorie;

    this->an_fabricatie = copy.an_fabricatie;
    this->km = copy.km;
    this->pret = copy.pret;

    this->km100 = copy.km100;

    this->status = copy.status;

    this->discCheck = copy.discCheck;

}

Masina &Masina::operator=(const Masina &eg) {

    this->marca = eg.marca;
    this->model = eg.model;

    this->motor = eg.motor;

    this->culoare = eg.culoare;
    this->second_hand = eg.second_hand;

    this->categorie = eg.categorie;

    this->an_fabricatie = eg.an_fabricatie;
    this->km = eg.km;
    this->pret = eg.pret;

    this->status = eg.status;

    this->km100 = eg.km100;



    return *this;

}

std::ostream &operator<<(std::ostream &os, const Masina &masina) {

    os << "Marca: " << masina.marca
       << "\nModel: " << masina.model
       << "\nCapacitate cilindrica motor (L): " << masina.motor
       << "\nCuloare: " << masina.culoare
       << "\nSecond Hand (Da / Nu): " << masina.second_hand
       << "\nCategorie Permis Conducere: " << masina.categorie
       << "\nAnul Fabricarii: " << masina.an_fabricatie
       << "\nKm: " << masina.km
       << "\nPret: " << masina.pret << " Euro"
       << "\nTimp 100 km/h (s): " << masina.km100
       << "\nStatus: " << masina.status << "\n\n";

    return os;
}

void Masina::ShowTimer100() const {

    std::cout << "\n" << marca << " " << model << " - Timer 100 km/h:\n";

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

void Compara(Masina &m1, Masina &m2) {

    std::cout << "\nCompara autovehicule:\n";

    double p1, p2;     //Puncte avantaj

    std::cout << m1.marca << " " << m1.model << " " << m1.an_fabricatie << ", motor " << m1.motor
              << ": " << m1.pret << " Euro, " << m1.km << " Km, Categorie permis: " << m1.categorie
              << ", Second Hand: " << m1.second_hand << "\n";

    std::cout << m2.marca << " " << m2.model << " " << m2.an_fabricatie << ", motor " << m2.motor
              << ": " << m2.pret << " Euro, " << m2.km << " Km, Categorie permis: " << m2.categorie
              << ", Second Hand: " << m2.second_hand << "\n\n";

    if(m1.categorie != m2.categorie){

        std::cout << "Categorii diferite - Nu se pot compara!\n\n";
        return ;
    }

    //Masina mai noua, motor mai mare, pret mai mic -> punctaj mai mare
    p1 = m1.motor * 10 + m1.an_fabricatie * 0.001 - m1.pret / 100000 - m1.km / 100000;
    p2 = m2.motor * 10 + m2.an_fabricatie * 0.001 - m2.pret / 100000 - m2.km / 100000;

    if(m1.second_hand == "Nu")
        p1 += 10;

    if(m2.second_hand == "Nu")
        p2 += 10;

    std::cout << "Puncte avantaj " << m1.marca << " " << m1.model << ": " << p1
              << "\nPuncte avantaj " << m2.marca << " " << m2.model << ": " << p2 << "\n";

    if(p1 > p2) {
        std::cout << "Deal mai avantajos: " << m1.marca << " " << m1.model << ", " << m1.pret << " Euro\n\n";
        return ; }

    if(p2 > p1) {
        std::cout << "Deal mai avantajos: " << m2.marca << " " << m2.model << ", " << m2.pret << " Euro\n\n";
        return ; }

    std::cout << "Numar egal de puncte avantaj!\n\n";


}

void AplicaDiscount(Masina &m) {

    std::cout << m.marca << " " << m.model << ", " << m.pret << " Euro - Se cauta discount...\n";

    if(m.discCheck == 0 || m.status == "Vandut") {   //In implementarea initiala se putea aplica discount-ul la infinit

        std::cout << "Discount deja verificat / aplicat sau masina vanduta!\n\n";
        return ;
    }

    if(m.an_fabricatie > 2005) {

        std::cout << m.marca << " " << m.model << ": Masina fabricata dupa anul 2005 - Fara Discount\n\n";
        m.discCheck = false;
        return;
    }


    std::cout << m.marca << " " << m.model << ": Discount de 5% - masina fabricata inainte de anul 2005\n";

    m.pret -= m.pret / 20;

    std::cout << "Pret actualizat: " << m.marca << " " << m.model << " - " << m.pret << " Euro\n\n";

    m.discCheck = false;

}
