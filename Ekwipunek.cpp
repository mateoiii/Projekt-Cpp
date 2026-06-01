//Ekwipunek.cpp

#include "Ekwipunek.h"

Ekwipunek::Ekwipunek(){
}

void Ekwipunek::pokazZawartosc() const{
    if (m_przedmioty.empty()) {
        std::cout << "Plecak jest pusty." << std::endl;
        return; // przerywamy funkcję jeśli nic nie ma
    }
    
    std::cout << "W plecaku: ";

    for(const std::string& p : m_przedmioty){                           //pętla zakresowa, & żeby nie robić kopii stringa tylko odwoływać się do tego co jest w wektorze, const bo nie zmieniamy tego co jest w wektorze
    std::cout << p << ", ";
    }
    std::cout << std::endl;
}

void Ekwipunek::dodajPrzedmiot(std::string przedmiot){
    m_przedmioty.push_back(przedmiot);
}

void Ekwipunek::posortujPlecak() {
    if (m_przedmioty.empty()) {
        std::cout << "Plecak jest pusty, nie ma co sortowac." << std::endl;
        return;
    }
    // Używamy algorytmu sort oraz iteratorów begin() i end()
    std::sort(m_przedmioty.begin(), m_przedmioty.end());
    std::cout << "Przedmioty w plecaku zostaly posortowane alfabetycznie!" << std::endl;
}