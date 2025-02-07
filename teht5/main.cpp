#include "notifikaattori.h"
#include <iostream>

using namespace std;

int main()
{
    Notifikaattori n;

    Seuraaja a("Aarne");
    Seuraaja b("Bertta");
    Seuraaja c("Celsius");
    Seuraaja d("Daavid");

    n.lisaa(&a);
    n.lisaa(&b);
    n.lisaa(&c);
    n.lisaa(&d);

    n.tulosta();
    n.postita("Tama on testi viesti 1.");
    n.poista(&c);
    n.postita("Tama on testi viesti 2.");

    return 0;
}
