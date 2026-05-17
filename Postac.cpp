//Postac.cpp

#include "Postac.h"

Postac::Postac(std::string imie): m_imie(imie), m_poziom(1), m_exp(0), m_hp(100), m_ekwipunek(new Ekwipunek()){  // definicja konstruktora, : znaczy lista inicjalizacyjna "zanim", new to po prostu narzędzie do tworzenia rzeczy na stałe w pamięci i zwracania adresu, tworzymy pusty ekwipunek
}

Postac::~Postac(){                                                                                               // definicja destruktora, nie ma virtual bo on nie mówi jaka jest funckja tylko jak sie ma zachować w stosunku do innych klas
    delete m_ekwipunek;                                                                                          // zanim usunie się bohater to usuwamy ekwipunek żeby nie było wycieków pamięci
}

void Postac::przedstawSie() const{                                                                               // definicja metody przedstawSie, const zostawiamy
    std::cout << "Moje imię to: " << m_imie << std::endl;
    std::cout << "Moj poziom to: " << m_poziom << std::endl;
}

Postac::Postac(const Postac& innaPostac)
    : m_imie(innaPostac.m_imie), m_poziom(innaPostac.m_poziom), m_exp(innaPostac.m_exp), 
    m_hp(innaPostac.m_hp), m_ekwipunek(new Ekwipunek(*(innaPostac.m_ekwipunek))){                                // definicja konstruktora kopiującego, tworzymy nowy ekwipunek który jest kopią ekwipunku innej postaci, * przed innaPostac.m_ekwipunek bo chcemy przekazać to co jest pod adresem a nie sam adres
}

Postac& Postac::operator=(const Postac& innaPostac){
    if(this == &innaPostac){
        return *this;                                                                                            // sprawdzamy czy przypisujemy do samego siebie, jeśli tak to nic nie robimy i zwracamy siebie
    }
    m_imie = innaPostac.m_imie;
    m_poziom = innaPostac.m_poziom;
    m_exp = innaPostac.m_exp;
    m_hp = innaPostac.m_hp;
    delete m_ekwipunek;                                                                                          // usuwamy stary ekwipunek żeby nie było wycieków pamięci
    m_ekwipunek = new Ekwipunek(*(innaPostac.m_ekwipunek));                                                      // tworzymy nowy ekwipunek który jest kopią ekwipunku innej postaci, * przed innaPostac.m_ekwipunek bo chcemy przekazać to co jest pod adresem, wyłuskanie
    return *this;                                                                                                // zwracamy siebie żeby można było robić kaskadowe przypisania
}

void Postac::podniesPrzedmiot(std::string przedmiot) {
    m_ekwipunek->dodajPrzedmiot(przedmiot);
}
void Postac::pokazPlecak() const{
    m_ekwipunek->pokazZawartosc();
}