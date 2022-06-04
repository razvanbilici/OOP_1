//
// Created by Razvan on 02-Jun-22.
//

#ifndef MAIN_CPP_ERORI_H
#define MAIN_CPP_ERORI_H


class motor_error : public std::runtime_error{

public:
    motor_error() : std::runtime_error("Capacitate motor invalida!\n"){};

};



class cnp_error : public std::runtime_error{
public:

    cnp_error() : std::runtime_error("CNP INVALID!\n"){};

};

class shKM_error : public std::runtime_error{

public:

    shKM_error() : std::runtime_error("Kilometraj invalid pentru Vehicul NOU\n"){};
};



#endif //MAIN_CPP_ERORI_H
