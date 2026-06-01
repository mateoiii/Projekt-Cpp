//Postac.cpp

#include "Postac.h"


int Postac::losoweObrazenia(int min, int max){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> rozklad(min, max);
    return rozklad(gen);

}
bool Postac::czyCiosKrytyczny(int szansaWProcentach){
    if (losoweObrazenia(1,100) <= szansaWProcentach) return 1;
    else return 0;
}

Postac::Postac(std::string imie): m_imie(imie), m_poziom(1), m_exp(0), m_hp(100), m_ekwipunek(new Ekwipunek()){  // definicja konstruktora, : znaczy lista inicjalizacyjna "zanim", new to po prostu narzędzie do tworzenia rzeczy na stałe w pamięci i zwracania adresu, tworzymy pusty ekwipunek
}

Postac::~Postac(){                                                                                               // definicja destruktora, nie ma virtual bo on nie mówi jaka jest funckja tylko jak sie ma zachować w stosunku do innych klas
    delete m_ekwipunek;                                                                                          // zanim usunie się bohater to usuwamy ekwipunek żeby nie było wycieków pamięci
}

void Postac::otrzymajObrazenia(int otrzymaneObrazenia){
    int nowe_hp = m_hp - otrzymaneObrazenia;
    std:: cout << "Zostało mi " << nowe_hp << " punktow zycia." << std::endl;
    m_hp = nowe_hp;
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

void Postac::uzyjMikstury() {
    if (m_iloscMikstur > 0) {
        int leczenie = losoweObrazenia(20, 40); 
        m_hp += leczenie;
        m_iloscMikstur--;
        
        std::cout << m_imie << " wypija miksture i odzyskuje " << leczenie << " HP! (Zostalo mikstur: " << m_iloscMikstur << ")" << std::endl;
        std::cout << "Aktualne HP: " << m_hp << std::endl;
    } 
    else std::cout << "Brakuje mikstur!" << std::endl;
}

void Postac::zapiszBohatera() {
    std::ofstream plik("zapis.txt");
    
    if (plik.is_open()) {
        plik << m_imie << std::endl;
        plik << m_poziom << std::endl;
        plik << m_hp << std::endl;
        plik << m_exp << std::endl; 
        
        plik.close();
        std::cout << "Stan gry zostal pomyslnie zapisany." << std::endl;
    } else std::cout << "Nie udalo sie otworzyc pliku do zapisu!" << std::endl;
}

bool Postac::wczytajBohatera() {
    std::ifstream plik("zapis.txt");
    
    if (plik.is_open()) {
        plik >> m_imie;
        plik >> m_poziom;
        plik >> m_hp;
        plik >> m_exp;
        
        plik.close();
        std::cout << "Stan gry zostal pomyslnie wczytany." << std::endl;
        return true;
    } else {
        throw std::runtime_error("Plik z zapisem nie istnieje na dysku!");
    }
}

void Postac::zdobadzDoswiadczenie(int ilosc) {
    m_exp += ilosc;
    std::cout << "\nZdobyles " << ilosc << " punktow doswiadczenia! (Lacznie: " << m_exp << "/100)" << std::endl;

    if (m_exp >= 100) {
        m_poziom++;
        m_exp -= 100; 
        m_hp += 30; 
        
        std::cout << "*** AWANS! ***" << std::endl;
        std::cout << m_imie << " osiaga " << m_poziom << " poziom!" << std::endl;
        std::cout << "Twoje zdrowie rosnie! (Aktualne HP: " << m_hp << ")" << std::endl;
    }
}

std::ostream& operator<<(std::ostream& os, const Postac& p) {
    os << "[" << p.m_imie << " | Lvl: " << p.m_poziom << " | HP: " << p.m_hp << "]";
    return os; // zwracamy strumień
}