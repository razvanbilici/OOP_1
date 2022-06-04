//
// Created by Razvan on 04-Jun-22.
//

#ifndef MAIN_CPP_MASINABUILDER_H
#define MAIN_CPP_MASINABUILDER_H


class MasinaBuilder {

private:
    Masina masina;

public:
    MasinaBuilder() = default;

    MasinaBuilder& marca(const std::string &marca) {

        masina.marca = marca;

        return *this;
    }

    MasinaBuilder& model(const std::string &model) {

        masina.model = model;

        return *this;
    }


    MasinaBuilder& motor(float motor) {

        masina.motor = motor;

        return *this;
    }



    MasinaBuilder& culoare(const std::string& culoare) {
        masina.culoare = culoare;
        return *this;
    }

    MasinaBuilder& SH(SH secondHand) {
        masina.secondHand = secondHand;
        return *this;
    }

    MasinaBuilder& an(int an) {
        masina.anFabricatie = an;
        return *this;
    }

    MasinaBuilder& km(int km) {
        masina.km = km;
        return *this;
    }
    MasinaBuilder& pret(int pret) {
        masina.pret = pret;
        return *this;
    }

    MasinaBuilder& km100(float km100) {

        masina.km100 = km100;
        return *this;
    }

    MasinaBuilder& cutie(cutieViteze cutie) {

        masina.CV = cutie;
        return *this;
    }

    MasinaBuilder& nrUsi(int usi) {

        masina.numarUsi = usi;
        return *this;
    }

    MasinaBuilder& status(const std::string& status) {
        masina.status = status;
        return *this;
    }

    Masina build() {

        FileLog::append("Obiect MASINA creat (((BUILDER CLASS)))");

        return masina;
    }


};


#endif //MAIN_CPP_MASINABUILDER_H
