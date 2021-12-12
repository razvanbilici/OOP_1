#include <iostream>
#include <unistd.h>
#include <cmath>
#include <vector>

//Bilici Mihai-Razvan, 262 - OOP_2

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
    const std::string &getMarca() const {
        return marca;
    }

    void setMarca(const std::string &Marca) {
        marca = Marca;
    }

    const std::string &getModel() const {
        return model;
    }

    void setModel(const std::string &Model) {
        model = Model;
    }

    const std::string &getCuloare() const {
        return culoare;
    }

    void setCuloare(const std::string &Culoare) {
        culoare = Culoare;
    }

    const std::string &getSecondHand() const {
        return second_hand;
    }

    void setSecondHand(const std::string &secondHand) {
        second_hand = secondHand;
    }

    char getCategorie() const {
        return categorie;
    }

    void setCategorie(char Categorie) {
        categorie = Categorie;
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

    void setKm(int Km) {
        Masina::km = Km;
    }

    int getPret() const {
        return pret;
    }

    void setPret(int Pret) {
        pret = Pret;
    }

    float getKm100() const {
        return km100;
    }

    void setKm100(float Km100) {
        km100 = Km100;
    }

    float getMotor() const {
        return motor;
    }

    void setMotor(float Motor) {
        motor = Motor;
    }

    const std::string &getStatus() const {
        return status;
    }

    void setStatus(const std::string &Status) {
        status = Status;
    }

    bool isDiscCheck() const {
        return discCheck;
    }


    //Constructorul de initializare
    Masina(const std::string &marca, const std::string &model, float motor, const std::string &culoare,
           const std::string &secondHand, char categorie,
           int anFabricatie, int km, int pret, float km100, const std::string &status) {

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


    //Constructor de initializare (fara lista de parametri)
    Masina() {

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


    //Constructorul de copiere
    Masina(const Masina &copy) {

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

    // Operatorul =
    Masina& operator=(const Masina &eg){

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

    //Destructorul
    ~Masina(){}

    //Operator de afisare
    friend std::ostream &operator<<(std::ostream &os, const Masina &masina) {

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


    //Arata numarul de secunde in care masina ajunge la 100/km (*de implementat un GUI*)
    void ShowTimer100() const {

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

    friend void Compara(Masina &m1, Masina &m2){

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

    friend void AplicaDiscount(Masina &m) {

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


};

class Catalog{

    std::string nume;       // Colectia toamna / primavara / etc ??

    std::vector <Masina> m;     /*Am observat dupa ce am implementat functiile de search si cumparare ca in vector se fac
                                       copii ale masinilor ( / se apeleaza constructorul iar),
                                       un pointer aici cred ca ar fi rezolvat problema asta */

public:

    Catalog(const std::string &nume, const std::vector<Masina> &m) {

        this->nume = nume;
        this->m = m;
    }

    Catalog();


    const std::string &getNume() const {
        return nume;
    }

    void setNume(const std::string &Nume) {
        nume = Nume;
    }

    const std::vector<Masina> &getM() const {
        return m;
    }

    void setM(const std::vector<Masina> &M) {
        m = M;
    }

};


class Cumparator {

    std::string nume;
    std::string CNP;

    std::string catPermis;  //ex. ABC daca are mai multe categorii

    int buget;

public:
    const std::string &getNume() const {
        return nume;
    }

    void setNume(const std::string &Nume) {
        nume = Nume;
    }

    const std::string &getCnp() const {
        return CNP;
    }

    void setCnp(const std::string &cnp) {
        CNP = cnp;
    }

    const std::string &getCatPermis() const {
        return catPermis;
    }

    void setCatPermis(const std::string &CatPermis) {
        catPermis = CatPermis;
    }

    int getBuget() const {
        return buget;
    }

    void setBuget(int Buget) {
        buget = Buget;
    }

    Cumparator(const std::string &nume, const std::string &cnp, const std::string &catPermis, int buget){

        this->nume = nume;
        CNP = cnp;
        this->catPermis = catPermis;
        this->buget = buget;

    };

    Cumparator(){

        nume = "noname";
        CNP = "0";
        catPermis = "xxxx";
        buget = -1;

    }


private:

    //Pentru operatorul << de mai jos
    void showCat(){

        std::cout << "Categorii Permis: ";

        for(int i = 0; i < catPermis.length(); i++) {
            std::cout << catPermis[i] << " ";
        }
    }

public:
    //Pentru afisare direct pe ecran
    void VerificarePermis(Masina &m){

        std::cout << "\nSe cauta permis categoria " << m.getCategorie() << " pentru " << m.getMarca()
                  << " " << m.getModel() << "...\n";
        size_t found = catPermis.find(m.getCategorie());

        if (found == std::string::npos) {

            std::cout << "Nu detineti permis categoria " << m.getCategorie() << "!\n\n";
            return ;
        }

        std::cout << "Permis verificat!\n\n";



    }
    //Pentru functia Search de mai jos
    bool Check(Catalog &c, int i){

        size_t found = catPermis.find(c.getM()[i].getCategorie());

        if (found == std::string::npos || c.getM()[i].getStatus() == "Vandut" || buget < c.getM()[i].getPret()) {

            return false;
        }
        return true;
    }

    void Search(Catalog &c){

        int results = 0;

        std::cout << "\nSe cauta masini pentru lista de categorii permis " << catPermis
                  << " si bugetul de " << buget <<" Euro...\n\n";

        for(int i = 0; i < c.getM().size(); i++) {

            if (Check(c, i) == 1 && buget >= c.getM()[i].getPret()) {
                std::cout << c.getM()[i];
                results++;

            }
        }

        if(results) {
            std::cout << "\nIncheierea cautarii\n\n";
            return; }

        std::cout << "Nu s-au gasit rezultate!\n\n";

    }

    void Cumpara(Catalog &c, int i){

        std::string cp;

        std::cout << "Doriti sa achizitionati " << c.getM()[i].getMarca() << " "
                  << c.getM()[i].getModel() << " " << c.getM()[i].getAnFabricatie() << " ?(Da / Nu)\n";

        std::cin >> cp;

        if(cp == "Nu")  {
            std::cout << "\n";
            return; }

        if(Check(c, i) == 0) {
            std::cout << "Anunt indisponibil / Nu detineti categoria aferenta / Buget depasit\n\n";
            return; }

        std::cout << "Automobil achizitionat!\n\n";
        buget -=  c.getM()[i].getPret();
        //Aici ar trebui sa schimb statusul cu c.getM()[i].setStatus("Vandut"), dar nu merge

    }

    friend std::ostream &operator<<(std::ostream &os, Cumparator &cumparator) {
        os << "\nNume: " << cumparator.nume
           << "\nCNP: " << cumparator.CNP << "\n";
        cumparator.showCat();                   //*Am evitat invalid use of non-static data member
        os << "\nBuget: " << cumparator.buget << "\n\n";
        return os;
    }


};



int main() {



    Masina m1("Volkswagen", "Passat", 1.9, "Gri", "Da", 'B', 2003, 270000, 3500, 16.1, "Disponibil");
    Masina m2("Fiat", "500x", 1.4, "Alb", "Nu", 'B', 2016, 0, 11000, 11.2, "Vandut");
    Masina m3("Dacia", "Logan MCV", 1.6, "Albastru", "Da", 'B', 2012, 143000, 3890, 15.2, "Disponibil");
    Masina m4("DAF", "XF", 12.7, "Gri", "Da", 'C', 2016, 203000, 54990, 33.3, "Disponibil");

    Cumparator c1("Alin Popescu", "59484112", "AB", 5500);

    Catalog cat1("Carzz.ro", {m1, m2, m3, m4});


    m2.ShowTimer100();


    AplicaDiscount(m3);         //Masina dupa 2005..

    AplicaDiscount(m1);
    AplicaDiscount(m1);         //Am verificat daca discount-ul e aplicat doar o singura data

    Compara(m2, m4);        //Categorii diferite..
    Compara(m1, m3);

    c1.VerificarePermis(m4);    //Categorie diferita..
    c1.VerificarePermis(m1);    //Categorie ok

    c1.Search(cat1);

    c1.Cumpara(cat1, 3);    //Categorie diferita..
    c1.Cumpara(cat1, 0);    //Ok..
    c1.Cumpara(cat1, 2);    //Buget depasit..

    std::cout << c1;



    return 0;
}
