//Mag.h

#pragma once
#include "Postac.h" 

class Mag : public Postac {  // Mag dziedziczy po Postac
public:
    Mag(std::string imie);  // konstruktor
    ~Mag();                 // destruktor

    void atakuj() override;  // override oznacza, że nadpisujemy metodę wirtualną z klasy bazowej
};