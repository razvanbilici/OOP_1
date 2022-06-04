cmake_minimum_required(VERSION 3.19)
project(POO_ProjV2)

set(CMAKE_CXX_STANDARD 14)

add_executable(POO_ProjV2 main.cpp Vehicul.cpp Vehicul.h Masina.cpp Masina.h Catalog.cpp Catalog.h
        UtilityClass.cpp UtilityClass.h User.h User.cpp
        Erori.h FileLog.h MasinaBuilder.h PremiumUser.cpp PremiumUser.h MasinaElectrica.cpp MasinaElectrica.h Inmatriculare.cpp Inmatriculare.h)