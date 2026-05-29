//Postac.h

#pragma once                                                        //zapobiego dołaczaniu tego samego pliku nagłówkowego wielokrotnie
#include <iostream>
#include <string>
#include <random>
#include <fstream>
#include "Ekwipunek.h"

class Postac{ 
protected:                                                          // protected bo dostępne dla klas dziedziczących
    std::string m_imie;                                             // std dlatego że w plikach .h nie robimy using namespace std bo przy podłączaniu do inncyh plików mogłoby narobić błędy
    int m_poziom;
    int m_exp;
    int m_hp;
    Ekwipunek* m_ekwipunek;
    int m_iloscMikstur = 3;

    int losoweObrazenia(int min, int max);

    bool czyCiosKrytyczny(int szansaWProcentach);

    

public:
    Postac(std::string imie);                                       // tu jest konstruktor 
                                                                    
    virtual ~Postac();                                              // to jest destruktor, dodajemy virtual (bo moża będzie ją potem zastąpić) bo przy dziedziczeniu mógłby wystąpić problem z usuwaniem, a tak najpierw sprawdzi destruktor klasy pochodnej potem bazowej i wszytsko bęzie usunięte

    virtual void atakuj(Postac* cel) = 0;                                      // to jest metoda wirtualna, czyli musi być zaimplementowana w klasie dziedziczącej, a = 0 oznacza że nie ma implementacji w tej klasie

    void otrzymajObrazenia(int otrzymaneObrazenia);

    void przedstawSie() const;                                      // const bo nie zmieniamy żadnych danych         


    Postac(const Postac& innaPostac);                               // to jest konstruktor kopiujący, będzie działał gdy będziemy chcieli skopiować postać i działą on tak że bierze postać& bo potrzebujemy danych z postaci i musimy wkleić je do innaPostac ale robić to z const aby nie zmienić przypadkowo danych postac

    Postac& operator=(const Postac& innaPostac);                    // to jest instrukcja co ma się stać gdy będziemy chcieć w trakcie gty przyrównać istniejące postacie, operator= pozwala zmienić działanie funkcji =, jest typu postac& dla kaskadowych równości x=y=z która wykonuje się od prawej do lewej i robiąc y=z zwróci odwołanie do samej siebie ay wykonać x=wynik(y=z) 
    

    void podniesPrzedmiot(std::string przedmiot);                   // metoda do podnoszenia przedmiotów, będzie po prostu przekazywać przedmiot do ekwipunku musi tu być bo z poziomu main nie mamy dotsępu do funckji ekwipunku, a z poziomu postaci już tak.
    
    void pokazPlecak() const;
    
    bool czyZyje() const {
    return m_hp > 0;
    }

    void uzyjMikstury();

    void zapiszBohatera();
    bool wczytajBohatera();

    void zdobadzDoswiadczenie(int ilosc);
};// po destruktorze konstruktorze i metodach musi być średnik bo to są zapowiedzi tych rzsczy które trzeba będzie zaimplementować w pliku .cpp