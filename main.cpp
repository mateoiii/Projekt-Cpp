#include <iostream>
#include <string>

using namespace std;

class Bohater{

private:
    string imie;
    int poziom;
    int hp;
    int mana;
public:
    Bohater(string startoweImie){
        imie = startoweImie;
        poziom = 1;
        hp = 100;
        mana = 10;
    }

    void przedstawSie(){
        cout << "Moje imię to:" << imie << endl;
        cout << "Mój poziom to:" << poziom << endl;
    }

};


int main(){

    Bohater pierwszy("Mag");
    pierwszy.przedstawSie();




    return 0;
}