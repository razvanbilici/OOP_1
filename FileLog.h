//
// Created by Razvan on 03-Jun-22.
//

#ifndef MAIN_CPP_FILELOG_H
#define MAIN_CPP_FILELOG_H

#include <fstream>

class FileLog {
public:

    static void append(const std::string& event){

        std::chrono::system_clock::time_point p = std::chrono::system_clock::now();
        std::time_t t = std::chrono::system_clock::to_time_t(p);


        std::ofstream appFile;

        appFile.open("..\\log.txt", std::fstream::app | std::fstream::out);
        appFile << std::ctime(&t) << " " << event << "\n\n";



    }

};


#endif //MAIN_CPP_FILELOG_H
