//
// Created by Razvan on 23-Dec-21.
//

#ifndef OOP_MASINA_H
#define OOP_MASINA_H


#include <iostream>
#include <cmath>
#include <unistd.h>

class Masina{

    std::string marca;          // Atribute - private by default
    std::string model;

    float motor;

    std::string culoare;
    std::string second_hand;

    char categorie;

    int an_fabricatie;
    int km;
    int pret;

    float km100;            // In cate secunde se ajunge la 100 km / h

    std::string status;     // De vanzare / Vanduta

    bool discCheck;         //Verifica daca a fost aplicat un discount

public:



    //Setteri & Getteri
    const std::string &getMarca() const;
    void setMarca(const std::string &Marca);
    const std::string &getModel() const;
    void setModel(const std::string &Model);
    const std::string &getCuloare() const;
    void setCuloare(const std::string &Culoare);
    const std::string &getSecondHand() const;
    void setSecondHand(const std::string &secondHand);
    char getCategorie() const;
    void setCategorie(char Categorie);
    int getAnFabricatie() const;
    void setAnFabricatie(int anFabricatie);
    int getKm() const;
    void setKm(int Km);
    int getPret() const;
    void setPret(int Pret);
    float getKm100() const;
    void setKm100(float Km100);
    float getMotor() const;
    void setMotor(float Motor);
    const std::string &getStatus() const;
    void setStatus(const std::string &Status);
    bool isDiscCheck() const;


    //Constructorul de initializare
    Masina(const std::string &marca, const std::string &model, float motor, const std::string &culoare,
           const std::string &secondHand, char categorie,
           int anFabricatie, int km, int pret, float km100, const std::string &status);


    //Constructor de initializare (fara lista de parametri)
    Masina();


    //Constructorul de copiere
    Masina(const Masina &copy);

    // Operatorul =
    Masina& operator=(const Masina &eg);

    //Destructorul
    ~Masina(){}

    //Operator de afisare
    friend std::ostream &operator<<(std::ostream &os, const Masina &masina);


    //Arata numarul de secunde in care masina ajunge la 100/km (*de implementat un GUI*)
    void ShowTimer100() const;

    friend void Compara(Masina &m1, Masina &m2);

    friend void AplicaDiscount(Masina &m);


};

#endif //OOP_MASINA_H
