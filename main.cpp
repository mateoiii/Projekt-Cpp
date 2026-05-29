#include <iostream>
#include <string>
#include <vector>
#include "Mag.h"
#include "Wojownik.h"
#include "Przeciwnik.h" 

int main(){

Postac* gracz = new Wojownik("Geralt");
Postac* wrog = new Przeciwnik();

std::cout << "--- ROZPOCZYNA SIE WALKA ---" << std::endl;
wrog->przedstawSie();

while (gracz->czyZyje() && wrog->czyZyje()){                       
                                            
    std::cout << "Wybierz akcje: " << std::endl;
    std::cout << "1.Atak" << std::endl;
    std::cout << "2.Plecak" << std::endl;
    std::cout << "3.Ulecz się" << std::endl;

    char wybor = '0';
    std::cin >> wybor;

    switch (wybor){
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

    if (wrog->czyZyje()) wrog->atakuj(gracz);
}

if (gracz->czyZyje()) std::cout << "Zwyciestwo!" << std::endl;
else std::cout << "Polegles w walce..." << std::endl;

std::cout << "Czy chcesz zapisac gre? (1-Tak, 2-Nie)" << std::endl;
char wybor_ = '0';
std::cin >> wybor_;
if (wybor_ == 1) gracz->zapiszBohatera();
else if (wybor_ == 2) std::cout << "Gra nie zostala zapisana." << std::endl;
else std::cout << "Zly wybor!" << std::endl;


delete gracz;
delete wrog;

return 0;
}