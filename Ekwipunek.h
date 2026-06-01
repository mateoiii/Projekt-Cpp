//Ekwipunek.h

#pragma once                                        //ekwipunek roobimy jako osobna klasa po to aby pokazać głęboką kopię, z tego że w pliku Postac.h damy wskażnik do tej klasy wyniknie taki problem że przy kopiowaniu postaci dwie takie same postacie będą miały wskażnik do jednego ekwipunku,
                                                    // więc decyzje jednego wpłyną na ekwipunek drugiego oraz może być tak że gdy jedna postać zginie to odpali się destruktor niszcząc ekwipunek a gdy druga postać zginie destruktor już nie będzie miał czego zniszzyć wiec wyskoczy błąd.
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


class Ekwipunek{

protected:

    std::vector <std::string> m_przedmioty;

public:
    Ekwipunek();                                    //konstruktor ekwipunku, jest pusty bo nie mamy żadnych przedmiotów i konstruktor zainicjalizuje poprostu pusty wektor
                                                    // nie potrzeba nam destruktora bo ta klasa korzysta tylko z wektora przyjmującego stringi więc wszystko inteligentnie samo się usunie
    void pokazZawartosc() const;
    
    void dodajPrzedmiot(std::string przedmiot);

    void posortujPlecak();
};