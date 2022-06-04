//
// Created by Razvan on 23-May-22.
//

#ifndef POO_PROJV2_MASINA_H
#define POO_PROJV2_MASINA_H

#include <ostream>
#include "Vehicul.h"


enum cutieViteze {Manuala, Automata, na};

class Masina : public Vehicul{
protected:

    cutieViteze CV;
    int numarUsi;

    std::string cutieToString() const;

    friend class MasinaBuilder;

    Masina(const std::string &marca, const std::string &model, float motor, const std::string &culoare, SH secondHand,
           int anFabricatie, int km, int pret, float km100, const std::string &status, int numarUsi);

public:

    cutieViteze getCv() const;
    void setCv(cutieViteze cv);
    int getNumarUsi() const;
    void setNumarUsi(int numarUsi);


    Masina(const std::string &marca, const std::string &model, float motor, const std::string &culoare, SH secondHand,
           int anFabricatie, int km, int pret, float km100, cutieViteze CV, int nrUsi, const std::string &status);

    Masina();

    virtual ~Masina() override = default;

    friend std::ostream &operator<<(std::ostream &os, const Masina &masina);

    virtual bool verificaDiscount() override;


    virtual void Afis() override;

};


class MasinaFactory {

public:
    static Masina DACIA() {

        return Masina ("Dacia", "1300", 1.3, "Rosu", Da,
                            1977, 300000, 300, 25.3, Manuala, 4, "Colectie");
    }

    static Masina OPEL() {

        return Masina ("Opel", "Corsa", 1.5, "Rosu", Da,
                              1982, 600000, 500, 18.3, Manuala, 4, "Colectie");
    }

};



#endif //POO_PROJV2_MASINA_H
