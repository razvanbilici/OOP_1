//
// Created by Razvan on 23-May-22.
//

#ifndef POO_PROJV2_USER_H
#define POO_PROJV2_USER_H

#include <chrono>
#include <string>
#include <vector>
#include <iostream>
#include "Erori.h"


using namespace std::chrono_literals;

class User {
protected:

    static int userNo;
    std::string userId;

    std::string nume;
    std::string CNP;

    std::vector<char> categoriiPermis;  //ex. ABC daca are mai multe categorii

    int buget;

    std::string username;
    std::string email;
    std::string password;

    int yearOfRegistration;


public:


    User(const std::string &nume, const std::string &cnp, const std::vector<char> &categoriiPermis, int buget,
         const std::string &username, const std::string &email, const std::string &password, int YOR);

    User();

    virtual ~User();


    static int getUserNo();


    const std::string &getUserId() const;

    const std::string &getNume() const;

    void setNume(const std::string &nume);

    const std::string &getCnp() const;

    void setCnp(const std::string &cnp);

    const std::vector<char> &getCategoriiPermis() const;

    void setCategoriiPermis(const std::vector<char> &categoriiPermis);

    int getBuget() const;

    void setBuget(int buget);


    const std::string &getUsername() const;

    void setUsername(const std::string &username);

    const std::string &getEmail() const;

    void setEmail(const std::string &email);

    const std::string &getPassword() const;

    void setPassword(const std::string &password);

    int getYearOfRegistration() const;

    void setYearOfRegistration(int yearOfRegistration);

    virtual void userToString();

    std::string catPermisToString() const;

    friend std::ostream &operator<<(std::ostream &os, const User &user);


};

#endif //POO_PROJV2_USER_H
