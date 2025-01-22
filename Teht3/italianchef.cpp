#include "italianchef.h"
#include <iostream>

ItalianChef::ItalianChef(string n):Chef(n)
{
    cout << "Italian chef " << chefName << " Konstruktori" << endl;
}

ItalianChef::~ItalianChef()
{
    cout << "Italian chef " << chefName << " Destruktori" << endl;
}

bool ItalianChef::askSecret(string pass, int water, int flour)
{
    if (pass == password){
        cout << "Password ok!" << endl;
        makepizza(water,flour);
        return true;
    }
    cout << "Password false!" << endl;
    return false;
}

int ItalianChef::makepizza(int water, int flour)
{
    int n = min(water, flour)/5;
    cout << "ItalianChef " << chefName << " with " << flour << " flour and " << water << " water can make " << n << " pizzas" << endl;
    return n;
}
