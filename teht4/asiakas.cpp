#include "asiakas.h"
#include <iostream>


Asiakas::Asiakas(string n, double s)
    : nimi(n), kayttotili(n), luottotili(n, s){
    cout << "Asiakuus luotu " << nimi <<endl;
}

string Asiakas::getNimi()
{
    return nimi;
}

void Asiakas::showSaldo()
{
    cout << "Kayttotili saldo: " << kayttotili.getBalance() << endl;
    cout << "Luottotili saldo: " << luottotili.getBalance() << endl;
}

bool Asiakas::talletus(double s)
{
    cout << "Kayttotili: ";
    if (kayttotili.deposit(s)){
        cout << "talletus " << s << " tehty" << endl;
        return true;
    }
    return false;
}

bool Asiakas::nosto(double s)
{
    cout << "Kayttotili: ";
    if (kayttotili.withdraw(s)){
        cout << "Nosto " << s << " tehty" << endl;
        return true;
    }
    return false;
;
}

bool Asiakas::luotonMaksu(double s)
{
    cout << "Luottotili: ";
    if (luottotili.deposit(s)){
        cout << "Luotton maksu " << s << " tehty" << endl;
        return true;
    }
    return false;
}

bool Asiakas::luotonNosto(double s)
{
    cout << "Luottotili: ";
    if (luottotili.withdraw(s)){
        cout << "Nosto " << s << " tehty, luottoa jaljella " << luottotili.getBalance() << endl;
        return true;
    }
    return false;
}

bool Asiakas::tiliSiirto(double s, Asiakas& a)
{
    if (kayttotili.getBalance() - s < 0 or s <= 0){
        cout << "Tili siirtoa ei toteutettu!" << endl;
        return false;
    }
    cout << nimi << " siirtaa " << s << " " << a.nimi << endl;
    cout << nimi << " ";
    nosto(s);
    cout << a.nimi << " ";
    a.talletus(s);
    cout << nimi << " Kayttotili saldo: " << kayttotili.getBalance() << endl;
    cout << a.nimi << " Kayttotili saldo: " << a.kayttotili.getBalance() << endl;

    return true;
}
