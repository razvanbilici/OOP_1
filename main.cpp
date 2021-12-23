#include "cmake-build-debug/Cumparator.h"

//Bilici Mihai-Razvan, 262 - OOP_2

int main() {



    Masina m1("Volkswagen", "Passat", 1.9, "Gri", "Da", 'B', 2003, 270000, 3500, 16.1, "Disponibil");
    Masina m2("Fiat", "500x", 1.4, "Alb", "Nu", 'B', 2016, 0, 11000, 11.2, "Vandut");
    Masina m3("Dacia", "Logan MCV", 1.6, "Albastru", "Da", 'B', 2012, 143000, 3890, 15.2, "Disponibil");
    Masina m4("DAF", "XF", 12.7, "Gri", "Da", 'C', 2016, 203000, 54990, 33.3, "Disponibil");

    Cumparator c1("Alin Popescu", "59484112", "AB", 5500);

    std::vector<Masina> msn = {m1,m2,m3, m4};

    Catalog cat1("Carzz.ro", msn);


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
