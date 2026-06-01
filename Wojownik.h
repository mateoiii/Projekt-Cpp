//Wojownik.h

#pragma once
#include "Postac.h"

class Wojownik:public Postac{
private:
    int m_sila;                                 // dodatkowy atrybut dla Wojownika
public:
    explicit Wojownik(std::string imie);                 // konstruktor

    ~Wojownik();                                // destruktor

    void atakuj(Postac* cel) override;          // override oznacza, że nadpisujemy metodę wirtualną z klasy bazowej
    
};