#include "luottotili.h"
#include <iostream>

Luottotili::Luottotili(string n, double s):Pankkitili(n)
{
    luottoRaja = s;
    saldo = s;
    cout << "Luottotili Luotu " << omistaja << ":lle, LUOTTORAJA: " << luottoRaja << endl;
}

bool Luottotili::deposit(double s)
{
    if(s < 0){
        return false;
    } else if (saldo + s > luottoRaja){
        return false;
    }

    saldo += s;

    return true;
}

bool Luottotili::withdraw(double s)
{
    if (s > 0){
        if (saldo - s < 0){
            cout << "Luottoraja Ylitetty!" << endl;
            return false;
        }
        saldo -= s;

        return true;
    }
    return false;
}
