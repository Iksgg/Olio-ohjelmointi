#include "pankkitili.h"
#include <iostream>

Pankkitili::Pankkitili(string n)
{
    omistaja = n;
    cout << "Pankkitili Luotu " << omistaja << ":lle" << endl;
}

double Pankkitili::getBalance()
{
    return saldo;
}

bool Pankkitili::deposit(double s)
{
    if (s <= 0){
        cout << "Talletusta ei voitu tehda. Summa negatiivinen." << endl;
        return false;
    }
    saldo += s;
    return true;
}

bool Pankkitili::withdraw(double s)
{
    if(s > 0){
        if (saldo - s < 0){
            cout <<  "Nosta ei tehty. Tililla ei tarpeeksi katetta." << endl;
            return false;
        }
        saldo -= s;
        return true;
    }
    cout << "Nostoa ei tehty. Summa negatiivinen" << endl;
    return false;
}
