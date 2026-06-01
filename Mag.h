//Mag.h

#pragma once
#include "Postac.h" 

class Mag:public Postac{                            // Mag dziedziczy po Postac, rodzaj dziedziczenia to public bo rzecy public i protected zostają takie same
private:
    int m_mana;                                     // dodatkowy atrybut dla Maga
public:
    explicit Mag(std::string imie);                 // konstruktor

    ~Mag();                                         // destruktor

    void atakuj(Postac* cel) override;              // override oznacza, że nadpisujemy metodę wirtualną z klasy bazowej

};