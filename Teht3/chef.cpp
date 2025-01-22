#include "chef.h"
#include <iostream>

Chef::Chef(string n):chefName(n)
{
    cout << "Chef " << chefName << " Konstructori" << endl;
}

Chef::~Chef()
{
    cout << "Chef " << chefName << " Destruktori" << endl;
}

string Chef::getName(){ return chefName;}

int Chef::makeSalad(int n)
{
    int p = n/5;
    cout << "Chef " << chefName << " with " << n << " items can make " << p << " salad portions" << endl;
    return p;
}

int Chef::makeSoup(int n)
{
    int p = n/3;
    cout << "Chef " << chefName << " with " << n << " items can make " << p << " soup portions" << endl;
    return p;
}
