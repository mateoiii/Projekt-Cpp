//Przeciwnik.cpp

#include "Przeciwnik.h"

std::string Przeciwnik::wylosujImie(){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> rozklad(0, 12);

    std::vector<std::string> nazwyPrzeciwnikow = {"Ork","Goblin","Wiedzma","Czarnoksieznik","Troll","Wampir","Topielec","Strzyga","Demon","Chochlik","Upior","Zjawa","Zmora"};
    return nazwyPrzeciwnikow[rozklad(gen)];
}


Przeciwnik::Przeciwnik(): Postac(wylosujImie()){
    m_max_hp = losoweObrazenia(30,70); 
    m_hp = m_max_hp;
}

Przeciwnik::~Przeciwnik(){
}

void Przeciwnik::atakuj(Postac* cel){
    int obrazenia = losoweObrazenia(5, 15); 
    
    if(czyCiosKrytyczny(20)){
        obrazenia *= 2;
        std::cout << m_imie << " zadaje KRYTYCZNY CIOS!" << std::endl;
    } 
    else std::cout << m_imie << " atakuje!" << std::endl;

    cel->otrzymajObrazenia(obrazenia); 
}