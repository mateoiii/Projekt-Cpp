// main.cpp

#include <iostream>
#include <string>
#include <vector>
#include "Mag.h"
#include "Wojownik.h"

int main() {
    std::cout << "-----TWORZENIE ORYGINALU-----" << std::endl;
    Mag oryginalnyMag("Czarodziej Bozydar");
    oryginalnyMag.podniesPrzedmiot("Magiczna Rozdzka");
    oryginalnyMag.podniesPrzedmiot("Mikstura Many");
    oryginalnyMag.pokazPlecak();

    std::cout << "\n-----KLONOWANIE (Test Głębokiej Kopii)-----" << std::endl;
    Mag klonMaga = oryginalnyMag; 
    
    klonMaga.podniesPrzedmiot("Zatruty Sztylet"); 
    
    std::cout << "Oryginal:" << std::endl;
    oryginalnyMag.pokazPlecak(); 
    std::cout << "Klon:" << std::endl;
    klonMaga.pokazPlecak();      

    std::cout << "\n--- TEST PRZYPISANIA ---" << std::endl;
    Mag innyMag("Zly Mag");
    innyMag.podniesPrzedmiot("Mroczny Krysztal");
    
    innyMag = klonMaga; 
    
    std::cout << "Zly Mag po nadpisaniu go klonem:" << std::endl;
    innyMag.pokazPlecak(); 

    oryginalnyMag.atakuj(&innyMag);
    oryginalnyMag.atakuj(&innyMag);
    oryginalnyMag.atakuj(&innyMag);
    oryginalnyMag.atakuj(&innyMag);



    return 0;
}