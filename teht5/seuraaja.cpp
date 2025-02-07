#include "seuraaja.h"
#include <iostream>

Seuraaja::Seuraaja(string n) : next(nullptr)
{
    cout << "Luodaan seuraaja " << n << endl;
    name = n;
}

string Seuraaja::getNimi()
{
    return name;
}

void Seuraaja::paivitys(string txt)
{
    cout << txt << endl;
}
