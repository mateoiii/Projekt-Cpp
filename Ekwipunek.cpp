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
        std::cout << "Plecak jest pusty." << std::endl;
        return;
    }

    std::sort(m_przedmioty.begin(), m_przedmioty.end());
    std::cout << "Przedmioty w plecaku zostaly posortowane." << std::endl;
}

void Ekwipunek::zapisz(std::ofstream& plik) const {
    plik << m_przedmioty.size() << std::endl; 
    for (const std::string& p : m_przedmioty) {
        plik << p << std::endl;
    }
}

void Ekwipunek::wczytaj(std::ifstream& plik) {
    m_przedmioty.clear();
    
    int iloscPrzedmiotow = 0;
    plik >> iloscPrzedmiotow; 
    plik.ignore(100, '\n');
    
    for (int i = 0; i < iloscPrzedmiotow; i++) {
        std::string przedmiot;
        std::getline(plik, przedmiot); 
        m_przedmioty.push_back(przedmiot);
    }
}