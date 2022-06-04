//
// Created by Razvan on 23-May-22.
//

#include "UtilityClass.h"

void UtilityClass::verificarePermis(User &user, Vehicul &vehicul) {

    FileLog::append("(" + user.getUsername() + ") Verificare Permis");

    std::cout << "\n" << "(" << user.getUsername() << ") Se cauta permis categoria " << vehicul.getCategorie()
              << " pentru " << vehicul.getMarca()
              << " " << vehicul.getModel() << "...\n";


    for (char cat : user.getCategoriiPermis())
        if (cat == vehicul.getCategorie()) {

            std::cout << "(" << user.getUsername() << ") Permis verificat!\n\n";
            return;

        }


    std::cout << "(" << user.getUsername()
              << ") Nu detineti permis categoria " << vehicul.getCategorie() << "!\n\n";

}

bool UtilityClass::Check(User &user, Vehicul &vehicul) {

    if(vehicul.getStatus() == "Vandut" || vehicul.getPret() > user.getBuget())
        return false;

    for (char cat : user.getCategoriiPermis())
        if (cat == vehicul.getCategorie())
            return true;

    return false;

}

void UtilityClass::Search(User &user, Catalog &catalog) {

    int results = 0;

    std::cout << "\n" << "(" << user.getUsername() << ") Se cauta masini pentru lista de categorii permis "
              << user.catPermisToString() << "si bugetul de " << user.getBuget() << " Euro...\n\n";

    for(int i = 0; i < catalog.getVehicule().size(); i++)
        if (Check(user, *(catalog.getVehicule()[i]))) {

            catalog.getVehicule()[i]->Afis();
            std::cout << "Index in Catalog: " << i << "\n\n";
            results++;}


    if(results) {
        std::cout << "Incheierea cautarii\n\n";
        return; }

    std::cout << "Nu s-au gasit rezultate!\n\n";

}

void UtilityClass::AplicaDiscount(User &user, Catalog &catalog, int index) {

    std::cout << "(" << user.getUsername() << ")" << "\n";
    if(!catalog.getVehicule()[index]->verificaDiscount())
        return;

    std::cout << "(" << user.getUsername() << ") Aplicati? (Y / N)\n";

    char input;
    std::cin >> input;

    if(tolower(input) == 'y') {

        catalog.getVehicule()[index]->setPret(catalog.getVehicule()[index]->getPret() -
                                              catalog.getVehicule()[index]->getPret() / 20);

        std::cout << "Pret actualizat: " << catalog.getVehicule()[index]->getMarca() << " "
                  << catalog.getVehicule()[index]->getModel() << " - "
                  << catalog.getVehicule()[index]->getPret() << " Euro\n\n";

        catalog.getVehicule()[index]->setDiscCheck(true);
    }


}

void UtilityClass::Oferta(User &user, Catalog &catalog, int i) {

    FileLog::append("(" + user.getUsername() + ") Oferta Initiata");

    std::string input;

    std::cout << "\n(" + user.getUsername() + ") Doriti sa faceti o oferta pentru "
                << catalog.getVehicule()[i]->getMarca() << " "
              << catalog.getVehicule()[i]->getModel() << " "
              << catalog.getVehicule()[i]->getAnFabricatie() << " ? (Da / Nu)\n";

    std::cin >> input;

    if (input == "Nu") {
        std::cout << "\n";
        return;
    }

    if (!Check(user, *(catalog.getVehicule()[i]))) {
        std::cout << "Anunt indisponibil / Nu detineti categoria aferenta / Buget depasit\n\n";
        return;
    }

    std::cout << "Oferta trimisa!\n\n";
    user.setBuget(user.getBuget() - catalog.getVehicule()[i]->getPret());

    catalog.getVehicule()[i]->setStatus("Vandut");

}

UtilityClass &UtilityClass::getInstance() {

    static UtilityClass instance;
    return instance;

}
