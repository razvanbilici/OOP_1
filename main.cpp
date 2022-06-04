
#include "MasinaElectrica.h"
#include "UtilityClass.h"
#include "MasinaBuilder.h"
#include "Inmatriculare.h"


int Vehicul::vehiculNO = 0;
int Catalog::catalogNO = 0;
int User::userNo = 0;

int main() {

    auto &utilityClass = UtilityClass::getInstance();

    FileLog::append("Main Run");

    //------------------------------------------------------------


    try{

    Masina DACIA_motor_error("Dacia", "Logan", -5, "Rosu", Da,
                 2001, 300000, 3500, 10.1, Manuala, 2, "De Vanzare"); }
    catch(motor_error &e) {

        FileLog::append("Eroare la crearea obiectului!");

        std::cout << "Obiectul nu a fost creat!\n";
        std::cout << e.what() << "\n";
    }

    try{

    Masina LOGAN_km_error("Dacia", "Logan", 1.6, "Rosu", Da,
                          2001, 300000, 3500, 10.1, Manuala, 2, "De Vanzare"); }

    catch(shKM_error &e) {

        FileLog::append("Eroare la crearea obiectului!");

        std::cout << "Obiectul nu a fost creat!\n";
        std::cout << e.what() << "\n";
    }

    Masina LOGAN("Dacia", "Logan", 1.6, "Rosu", Da,
             2001, 300000, 3500, 10.1, Manuala, 2, "De Vanzare");

    Masina ASTRA("Opel", "Astra", 2.5, "Alb", Nu,
                 2013, 0, 15000, 8.2, Automata, 4, "De Vanzare");

    Masina CORSA = MasinaFactory::OPEL();

    MasinaElectrica TESLA_X("Tesla", "Model X", 1, "Alb", Nu,
                 2019, 0, 55000, 5.2,"De Vanzare", 4,  45, false);

    // --------------------------------------------------

    MasinaBuilder builder;

    Masina SANDERO = builder.marca("DACIA")
                            .model("SANDERO")
                            .motor(2.6)
                            .culoare("Gri")
                            .SH(Nu)
                            .an(2015)
                            .km(0)
                            .pret(15000)
                            .km100(15.2)
                            .cutie(Automata)
                            .nrUsi(4)
                            .status("De Vanzare")
                            .build();

    Catalog VARA("Vara", {&LOGAN, &ASTRA, &TESLA_X});

    std::cout << VARA;

    //----------------------------------------------------

    try{

    User ANON("Ion Popescu", "548z5092871025", {'A', 'B'}, 5000,
    "ionPopescu1", "ionpopesc@yahoo.com", "ionpopescu99", 2019);

    }
    catch(cnp_error &e)
    {
        std::cout << "Obiectul nu a fost creat!\n";
        std::cout << e.what() << "\n";
    }

    //--------------------------------------------------------------------------

    //Nu aveam idei prea speciale aici :(

    Inmatriculare<std::string> CLUJ("Cluj015", "Cluj",
                                    std::make_shared<Masina>(SANDERO));

    Inmatriculare<int> ARAD(591, "Cluj",
                                    std::make_shared<MasinaElectrica>(TESLA_X));

    //-------------------------------------------------------------------------------


    User JOHN_DOE("Ion Popescu", "5485092871025", {'A', 'B'}, 5000,
              "ionPopescu1", "ionpopesc@yahoo.com", "ionpopescu99", 2019);

    std::vector<std::shared_ptr<Vehicul>> deppWishlist;
    deppWishlist.emplace_back(std::make_shared<Masina>(SANDERO));
    deppWishlist.emplace_back(std::make_shared<Masina>(CORSA));
    deppWishlist.emplace_back(std::make_shared<MasinaElectrica>(TESLA_X));

    PremiumUser JON_PREMIUM("Johnny Depp", "5485098771025", {'B'}, 1500000,
                            "JDEPP22", "jdepp@gmail.com", "jdepp@@", 2021, deppWishlist);

    JON_PREMIUM.userToString();

    std::cout << "-----------------------\n";

    //-------------------------------------------------------------------



    utilityClass.verificarePermis(JOHN_DOE, LOGAN);
    utilityClass.Search(JOHN_DOE, VARA);

    utilityClass.AplicaDiscount(JOHN_DOE, VARA, 1);
    utilityClass.AplicaDiscount(JOHN_DOE, VARA, 1);

    utilityClass.AplicaDiscount(JOHN_DOE, VARA, 0);
    utilityClass.AplicaDiscount(JOHN_DOE, VARA, 0);

    //Pretul ar trebui sa fie updatat
    std::cout << LOGAN;

// ------------------------------------------

    utilityClass.Oferta(JON_PREMIUM, VARA, 2);

    std::cout << TESLA_X;
    //Daca oferta este initiata statusul ar trebui sa fie schimbat in "Vandut"


    FileLog::append("Main Exited Successfully\n---------------------------------------------\n");


    return 0;
}
