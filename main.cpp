//main.cpp

#include <iostream>
#include <string>
#include <vector>
#include "Mag.h"
#include "Wojownik.h"


int main(){

    std::vector < Postac* > gildia;                 // wektor przyjmuje wskaźniki bo gdyby przyjmowało postac to magowi i wojownikowi ucinaloby ich własne metody i stałe

    Mag mojMag("Czarodziej Bożydar");
    Wojownik mojWoj("Figo");

    gildia.push_back(&mojMag);
    gildia.push_back(&mojWoj);

    for(Postac* bohater : gildia){                  //pętla zakresowa for, tu zamiast skupiać się JAK coś zrobić (zwykła pętla for) to mówimy CO chcemy zrobić. Składnia for(Typ wymyślona_nazwa : kolekcja). Czytamy normalnie, np dla każdegj postaci (którą nazwe bohater) w gidlii zrób:
        bohater -> przedstawSie();
        bohater -> atakuj();

    }





    return 0;
}