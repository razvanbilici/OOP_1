//
// Created by Razvan on 04-Jun-22.
//

#include "PremiumUser.h"

const std::vector<std::shared_ptr<Vehicul>> &PremiumUser::getWishlist() const {
    return wishlist;
}

void PremiumUser::setWishlist(const std::vector<std::shared_ptr<Vehicul>> &wishlist) {
    PremiumUser::wishlist = wishlist;
}

PremiumUser::PremiumUser(const std::string &nume, const std::string &cnp, const std::vector<char> &categoriiPermis,
                         int buget, const std::string &username, const std::string &email, const std::string &password,
                         int yor, const std::vector<std::shared_ptr<Vehicul>> &wishlist) : User(nume, cnp, categoriiPermis, buget,
                                                                                                username, email, password, yor),
                                                                                           wishlist(wishlist) {}
