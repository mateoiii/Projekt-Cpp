#include <iostream>
#include <string>
#include <vector>
#include "Mag.h"
#include "Wojownik.h"
#include "Przeciwnik.h" 

int main() {
    Postac* gracz = new Wojownik("Geralt");

    std::cout << "------ MENU GLOWNE ------" << std::endl;
    std::cout << "Czy chcesz wczytac poprzedni zapis gry? (1-Tak, 2-Nie): ";
    char wyborOdczytu = '0';
    std::cin >> wyborOdczytu;

    if (wyborOdczytu == '1') {
        if (gracz->wczytajBohatera()) gracz->przedstawSie();
        
    } 
    else {
        std::cout << "Zaczynamy nowa gre jako Geralt!" << std::endl;
    }

    //WALKA
    Postac* wrog = new Przeciwnik();

    std::cout << "\n------ ROZPOCZYNA SIE WALKA ------" << std::endl;
    wrog->przedstawSie();

    while (gracz->czyZyje() && wrog->czyZyje()) {                                           
        std::cout << "\nWybierz akcje: " << std::endl;
        std::cout << "1. Atak" << std::endl;
        std::cout << "2. Plecak" << std::endl;
        std::cout << "3. Ulecz sie" << std::endl;

        char wyborAkcji = '0';
        std::cin >> wyborAkcji;

        switch (wyborAkcji) {
        case '1':
            gracz->atakuj(wrog);
            break;
        case '2':
            gracz->pokazPlecak();
            continue; 
        case '3':
            gracz->uzyjMikstury();
            break;
        default:
            std::cout << "Zly wybor! Sprobuj ponownie." << std::endl;
            continue; 
        }

        if (wrog->czyZyje()) {
            wrog->atakuj(gracz);
        }
    }

    //WYNIK I ZAPIS GRY
    if (gracz->czyZyje()) {
        std::cout << "\nZwyciestwo!" << std::endl;
        
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> expDrop(30, 60);
        gracz->zdobadzDoswiadczenie(expDrop(gen));

        // 2. Generujemy losowy lup (Drop System)
        std::vector<std::string> tablicaLupow = {"Zelazny Miecz", "Skorzany Pancerz", "Zloty Pierscien", "Tajemniczy Zwoj", "Stary But"};
        std::uniform_int_distribution<> rzutOPrzedmiot(0, tablicaLupow.size() - 1);
        
        std::string zdobytyPrzedmiot = tablicaLupow[rzutOPrzedmiot(gen)];
        std::cout << "Z pokonanego wroga wypada: [" << zdobytyPrzedmiot << "]!" << std::endl;
        
        gracz->podniesPrzedmiot(zdobytyPrzedmiot);
        
        std::cout << "Czy chcesz zapisac gre? (1-Tak, 2-Nie): ";
        char wyborZapisu = '0';
        std::cin >> wyborZapisu;
        
        if (wyborZapisu == '1') {
            gracz->zapiszBohatera();
        } else if (wyborZapisu == '2') {
            std::cout << "Gra nie zostala zapisana." << std::endl;
        } else {
            std::cout << "Zly wybor! Gra niezapisana." << std::endl;
        }
    } else {
        std::cout << "\nPolegles w walce..." << std::endl;
    }

    delete gracz;
    delete wrog;

    return 0;
}