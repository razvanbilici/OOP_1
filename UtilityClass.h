//
// Created by Razvan on 23-May-22.
//

#ifndef POO_PROJV2_UTILITYCLASS_H
#define POO_PROJV2_UTILITYCLASS_H

#include "PremiumUser.h"
#include "Catalog.h"

//Singleton
class UtilityClass {


private:
    UtilityClass() = default;

public:

    UtilityClass(const UtilityClass &) = delete;
    UtilityClass& operator=(const UtilityClass &) = delete;
    static UtilityClass & getInstance();

    void verificarePermis(User &user, Vehicul &vehicul);

    //Pentru functia search de mai jos

private:

    bool Check(User &user, Vehicul &vehicul);
public:
    void Search(User &user, Catalog &catalog);


    void AplicaDiscount(User &user, Catalog &catalog, int index);

    void Oferta(User &user, Catalog &catalog, int i);

};


#endif //POO_PROJV2_UTILITYCLASS_H
