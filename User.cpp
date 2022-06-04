//
// Created by Razvan on 23-May-22.
//

#include "User.h"

User::User(const std::string &nume, const std::string &cnp, const std::vector<char> &categoriiPermis, int buget,
           const std::string &username, const std::string &email, const std::string &password, int YOR) {

    if (cnp.length() != 13)
        throw cnp_error();

    userNo++;

    this->nume = nume;
    CNP = cnp;
    this->categoriiPermis = categoriiPermis;
    this->buget = buget;
    this->username = username;
    this->email = email;
    this->password = password;

    yearOfRegistration = YOR;

    userId += std::to_string(userNo) + username.substr(0, 3) + std::to_string(yearOfRegistration)
              + nume.substr(0, 2);


}

User::User() {

    nume = "noname";
    categoriiPermis = {};
    username = "default";
    email = "email@nodomain.com";
    CNP = "0";
    categoriiPermis = {};
    buget = 0;

    userNo++;

    yearOfRegistration = time(nullptr) / 31537970 + 1970;

    userId += std::to_string(userNo) + std::to_string(yearOfRegistration);

}

User::~User() {

    userNo--;
}

int User::getUserNo() {
    return userNo;
}

const std::string &User::getUserId() const {
    return userId;
}

const std::string &User::getNume() const {
    return nume;
}

void User::setNume(const std::string &nume) {
    User::nume = nume;
}

const std::string &User::getCnp() const {
    return CNP;
}

void User::setCnp(const std::string &cnp) {
    CNP = cnp;
}

const std::vector<char> &User::getCategoriiPermis() const {
    return categoriiPermis;
}

void User::setCategoriiPermis(const std::vector<char> &categoriiPermis) {
    User::categoriiPermis = categoriiPermis;
}

int User::getBuget() const {
    return buget;
}

void User::setBuget(int buget) {
    User::buget = buget;
}

const std::string &User::getUsername() const {
    return username;
}

void User::setUsername(const std::string &username) {
    this->username = username;
}

const std::string &User::getEmail() const {
    return email;
}

void User::setEmail(const std::string &email) {
    this->email = email;
}

const std::string &User::getPassword() const {
    return password;
}

void User::setPassword(const std::string &password) {
    this->password = password;
}

void User::setYearOfRegistration(int yearOfRegistration) {
    this->yearOfRegistration = yearOfRegistration;
}

int User::getYearOfRegistration() const {
    return yearOfRegistration;
}

std::string User::catPermisToString() const {

    std::string catPermis;

    for (char c : categoriiPermis) {

        catPermis += c;
        catPermis += ' '; }

    return catPermis;
}

std::ostream &operator<<(std::ostream &os, const User &user) {
    os << "\n[[  ID USER: " << user.userId << "  ]]"
    << "\nNume: " << user.nume
    << "\nCategorii Permis: " << user.catPermisToString()
    << "\nBuget: " << user.buget << " Euro"
    << "\nUsername: " << user.username
    << "\nEmail: " << user.email
    << "\nAnul Inregistrarii: " << user.yearOfRegistration <<"\n";
    return os;
}

void User::userToString() {

    std::cout << "\n[[  ID USER: " << userId << "  ]]"
              << "\nNume: " << nume
              << "\nCategorii Permis: " << catPermisToString()
              << "\nBuget: " << buget << " Euro"
              << "\nUsername: " << username
              << "\nEmail: " << email
              << "\nAnul Inregistrarii: " << yearOfRegistration <<"\n";

}




