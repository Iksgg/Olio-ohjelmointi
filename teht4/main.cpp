#include <iostream>
#include "asiakas.h"

using namespace std;

int main()
{
    Asiakas asiakas1("Luigi Mario", 1000);
    asiakas1.showSaldo();
    cout << endl;

    asiakas1.talletus(200);
    asiakas1.luotonNosto(300);
    asiakas1.showSaldo();
    cout << endl;

    Asiakas asiakas2("Mario Mario", 1000);
    asiakas2.showSaldo();
    cout << endl;

    asiakas1.tiliSiirto(50, asiakas2);
    return 0;
}
