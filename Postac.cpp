//Postac.cpp

#include "Postac.h"

Postac::Postac(std::string imie): m_imie(imie), m_poziom(1), m_exp(0), m_hp(100){  // definicja konstruktora, : znaczy lista inicjalizacyjna, "zanim"
}

Postac::~Postac(){                                                       // definicja destruktora, nie ma virtual bo on nie mówi jaka jest funckja tylko jak sie ma zachować w stosunku do innych klas
}

void Postac::przedstawSie() const{                                       // definicja metody przedstawSie, const zostawiamy
    std::cout << "Moje imię to: " << m_imie << std::endl;
    std::cout << "Moj poziom to: " << m_poziom << std::endl;
}