//Postac.h

#pragma once                                                        //zapobiego dołaczaniu tego samego pliku nagłówkowego wielokrotnie
#include <iostream>
#include <string>

class Postac{ 
protected:                                                          // protected bo dostępne dla klas dziedziczących
    std::string m_imie;                                             // std dlatego że w plikach .h nie robimy using namespace std bo przy podłączaniu do inncyh plików mogłoby narobić błędy
    int m_poziom;
    int m_hp;
public:
    Postac(std::string imie): m_imie(imie), m_poziom(1), m_hp(100){ // : znaczy lista inicjalizacyjna, "zanim"
    }                                                               // tu jest konstruktor 

    virtual ~Postac(){}                                             // to jest destruktor, dodajemy virtual bo przy dziedziczeniu mógłby wystąpić problem z usuwaniem, a tak najpierw sprawdzi destruktor klasy pochodnej potem bazowej i wszytsko bęzie usunięte

    virtual void atakuj() = 0;                                      // to jest metoda wirtualna, czyli musi być zaimplementowana w klasie dziedziczącej, a = 0 oznacza że nie ma implementacji w tej klasie

    void przedstawSie() const{                                      // const bo nie zmieniamy żadnych danych         
        std::cout << "Moje imię to: " << m_imie << std::endl;
        std::cout << "Mój poziom to: " << m_poziom << std::endl;
    }

};