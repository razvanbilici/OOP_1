//
// Created by Razvan on 04-Jun-22.
//

#ifndef MAIN_CPP_PREMIUMUSER_H
#define MAIN_CPP_PREMIUMUSER_H


#include <memory>
#include "User.h"
#include "Vehicul.h"

class PremiumUser : public User{
private:

    std::vector<std::shared_ptr<Vehicul>> wishlist;

public:

    PremiumUser() = default;

    ~PremiumUser() override = default;

    PremiumUser(const std::string &nume, const std::string &cnp, const std::vector<char> &categoriiPermis, int buget,
                const std::string &username, const std::string &email, const std::string &password, int yor,
                const std::vector<std::shared_ptr<Vehicul>> &wishlist);

    const std::vector<std::shared_ptr<Vehicul>> &getWishlist() const;

    void userToString() override {

        User::userToString();

        std::cout << "Wishlist:";

        for(const std::shared_ptr<Vehicul>& vehicul : wishlist)
            vehicul->Afis();

    }

    void setWishlist(const std::vector<std::shared_ptr<Vehicul>> &wishlist);


};


#endif //MAIN_CPP_PREMIUMUSER_H
