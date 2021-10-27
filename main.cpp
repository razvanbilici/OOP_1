#include <iostream>

class Masina {

    std::string marca;          // Atribute - private by default
    std::string model;
    std::string culoare;
    std::string second_hand;    // Da/Nu - Mergea si cu un bool I guess
    int an_fabricatie;
    int km;
    int pret;

public:
    Masina(const std::string &marca, const std::string &model, const std::string &culoare,
                                    const std::string &second_hand, int an_fabricatie, int km, int pret) {

        this->marca = marca;
        this->model = model;
        this->culoare = culoare;
        this->second_hand = second_hand;
        this->an_fabricatie = an_fabricatie;
        this->km = km;
        this->pret = pret;

    }                                           // Constructorul


    const std::string &getMarca() const {
        return marca;
    }

    void setMarca(const std::string &S_marca) {
        marca = S_marca;
    }

    const std::string &getCuloare() const {
        return culoare;
    }

    void setCuloare(const std::string &S_culoare) {
        culoare = S_culoare;
    }

    const std::string &getModel() const {
        return model;
    }

    void setModel(const std::string &S_model) {
        model = S_model;
    }

    const std::string &getSecondHand() const {
        return second_hand;
    }

    void setSecondHand(const std::string &secondHand) {
        second_hand = secondHand;
    }

    int getAnFabricatie() const {
        return an_fabricatie;
    }

    void setAnFabricatie(int anFabricatie) {
        an_fabricatie = anFabricatie;
    }

    int getKm() const {
        return km;
    }

    void setKm(int S_km) {
        km = S_km;
    }

    int getPret() const {
        return pret;
    }

    void setPret(int S_pret) {
        pret = S_pret;
    }
    // Getteri si Setteri


    friend std::ostream &operator<<(std::ostream &os, const Masina &masina) {
        os << "Marca: " << masina.marca
           << "\nModel: " << masina.model
           << "\nCuloare: " << masina.culoare
           << "\nSecond Hand: " << masina.second_hand
           << "\nAn Fabricatie: " << masina.an_fabricatie
           << "\nKm (Doar Second Hand): " << masina.km
           << "\nPret (Euro): " << masina.pret << "\n";

        return os;
    }                                           // Operator de afisare


    Masina(const Masina& copy) {
        this->marca = copy.marca;
        this->model = copy.model;
        this->culoare = copy.culoare;
        this->second_hand = copy.second_hand;
        this->an_fabricatie = copy.an_fabricatie;
        this->km = copy.km;
        this->pret = copy.pret;

    }                                           //Constructorul de copiere


    Masina& operator=(const Masina& copy){
        this->marca = copy.marca;
        this->model = copy.model;
        this->culoare = copy.culoare;
        this->second_hand = copy.second_hand;
        this->an_fabricatie = copy.an_fabricatie;
        this->km = copy.km;
        this->pret = copy.pret;

        std::cout << "Operatorul=(Masina)\n";

        return *this;

    }                                           // Operatorul =

    ~Masina(){

        std::cout << "\n" << *this << "\n";
    }
                                                //Destructorul

       void VerificaDiscount() {

        if(an_fabricatie < 2005) {

            std::cout << marca << " " << model << ": Discount de 5% - masina fabricata inainte de anul 2005\n";
            pret -= pret / 20;
            std::cout << "Pret actualizat: " << marca << " " << model << " - " << pret << " Euro\n";
            return ;
                        }

           std::cout << marca << " " << model << ": Masina fabricata dupa anul 2005 - Fara Discount\n";
    }


};


class Cumparator {

    std::string nume;
    std::string CNP;
    char catPermis;

public:

    Cumparator(const std::string &nume, const std::string &CNP, char catPermis) {

        this->nume = nume;
        this->CNP = CNP;
        this->catPermis = catPermis;
    }

    const std::string &getNume() const {

        return nume;
    }

    void setNume(const std::string &S_nume) {
        nume = S_nume;
    }

    const std::string &getCnp() const {
        return CNP;
    }

    void setCnp(const std::string &S_CNP) {
        CNP = S_CNP;
    }

    char getCatPermis() const {
        return catPermis;
    }

    void setCatPermis(char S_catPermis) {

        catPermis = S_catPermis;
    }

    friend std::ostream &operator<<(std::ostream &os, const Cumparator &cumparator) {

        os << "Nume: " << cumparator.nume
           << "\nCNP: " << cumparator.CNP
           << "\nCategorie Permis: " << cumparator.catPermis <<"\n";

        return os;
    }

    void checkPermis (){

        if (catPermis != 'B') {

            std::cout << nume << ": trebuie sa detineti permis categoria B!\n";
            return ;
        }

        std::cout << nume <<": permis verificat!\n";
    }


};


class MasinaElectrica : public Masina{

    int baterie;    // kW
    char FastCharging;  // Y/N

public:

    MasinaElectrica(const std::string &marca, const std::string &model, const std::string &culoare,
                    const std::string &secondHand, int anFabricatie, int km, int pret, int baterie, char FastCharging)
                    : Masina(marca, model, culoare, secondHand, anFabricatie, km, pret) {

            this->baterie = baterie;
            this->FastCharging = FastCharging;
    }


    int getBaterie() const {
        return baterie;
    }

    void setBaterie(int S_baterie) {

        baterie = S_baterie;
    }

    char getFastCharging() const {
        return FastCharging;
    }

    void setFastCharging(char S_FastCharging) {
        FastCharging = S_FastCharging;
    }

    void CheckFC (){

        if (FastCharging != 'Y')  {

            std::cout << "\n" << getMarca() << " " << getModel() << ": Fara Fast Charging! Se aplica reducere de 5%!\n";


            setPret(getPret() - getPret() / 20);

            std::cout << "Pret actualizat: " << getMarca() << " " << getModel() << ": " << getPret() << " Euro\n";

            return ;

        }

        std::cout << "\n" << getMarca() << " " << getModel() << " are Fast Charging - Fara reducere!\n";

    }

};

int main(){

    MasinaElectrica mE1{"Suda", "SD10", "Rosu", "Nu", 2016, 0,9900,80,'N'};

    Masina mB1{"Volvo", "S60", "Negru", "Da", 2003, 500000, 5000};

    mB1.VerificaDiscount();
    mE1.CheckFC();



}