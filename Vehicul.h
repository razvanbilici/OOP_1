//
// Created by Razvan on 23-May-22.
//

#ifndef POO_PROJV2_VEHICUL_H
#define POO_PROJV2_VEHICUL_H


#include <string>
#include <iostream>
#include <cmath>
#include <chrono>
#include <thread>

#include "FileLog.h"
#include "Erori.h"


//Clasa abstracta

using namespace std::chrono_literals;

enum SH {Nu, Da, NA};

class Vehicul {

protected:

    static int vehiculNO;
    std::string id;

    std::string marca;
    std::string model;

    float motor;

    std::string culoare;
    SH secondHand;

    char categorie;

    int anFabricatie;
    int km;
    int pret;

    float km100;            // In cate secunde se ajunge la 100 km / h

    std::string status;     // De vanzare / Vanduta

    bool discCheck;         //Verifica daca a fost aplicat un discount

    //Pentru afisare
    std::string shToString() const;


public:

    static int getVehiculNo();
    const std::string &getMarca() const;
    void setMarca(const std::string &marca);
    const std::string &getModel() const;
    void setModel(const std::string &model);
    float getMotor() const;
    void setMotor(float motor);
    const std::string &getCuloare() const;
    void setCuloare(const std::string &culoare);
    SH getSecondHand() const;
    void setSecondHand(SH secondHand);
    char getCategorie() const;
    void setCategorie(char categorie);
    int getAnFabricatie() const;
    void setAnFabricatie(int anFabricatie);
    int getKm() const;
    void setKm(int km);
    int getPret() const;
    void setPret(int pret);
    float getKm100() const;
    void setKm100(float km100);
    const std::string &getStatus() const;
    void setStatus(const std::string &status);
    bool isDiscCheck() const;
    void setDiscCheck(bool discCheck);
    const std::string &getId() const;


    Vehicul(const std::string &marca, const std::string &model, float motor, const std::string &culoare,
            SH secondHand, int anFabricatie, int km, int pret, float km100,
            const std::string &status);

    Vehicul();

    virtual ~Vehicul();

    Vehicul(const Vehicul &copy);

    Vehicul &operator=(const Vehicul &copy) = default;

    void showTimer100() const;

    friend void Compara(Vehicul &v1, Vehicul &v2);

    virtual bool verificaDiscount() = 0;
    virtual void Afis() = 0;


};



#endif //POO_PROJV2_VEHICUL_H
