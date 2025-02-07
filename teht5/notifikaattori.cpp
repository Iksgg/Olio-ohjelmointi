#include "notifikaattori.h"
#include <iostream>

using namespace std;

Notifikaattori::Notifikaattori() : seuraajat(nullptr)
{
    cout << "Luodaan Notifikaattori " << endl;
}

void Notifikaattori::lisaa(Seuraaja * seuraaja)
{
    if (seuraaja == nullptr){
        cout << "Virhe: seuraaja = nullptr" << endl;
        return;
    }

    seuraaja->next = seuraajat;
    seuraajat = seuraaja;
}

void Notifikaattori::poista(Seuraaja * seuraaja)
{
    if (seuraajat == nullptr){
        cout << "lista on tyhja" << endl;
        return;
    }

    if (seuraajat == seuraaja){
        seuraajat = seuraaja->next;
        cout << "Poistetaan Seuraaja: " << seuraaja->getNimi() << endl;  
        return;
    }

    Seuraaja* current = seuraajat;
    while (current->next != nullptr){
        if (current->next == seuraaja){
            current->next = seuraaja->next;
            cout << "Poistetaan Seuraaja: " << seuraaja->getNimi() << endl;
            return;
        }
        current = current->next;
    }

    cout << "Tapahtui virhe: Seuraaja ei listalla." << endl;
}

void Notifikaattori::tulosta()
{
    cout << "Seuraajat: " << endl;
    Seuraaja* current = seuraajat;

    while(current != nullptr){
        cout << current->getNimi() << endl;
        current = current->next;
    }
}

void Notifikaattori::postita(string txt)
{
    Seuraaja* current = seuraajat;

    while (current != nullptr){
        cout << "Seuraaja " << current->getNimi() << " sai vestin: ";
        current->paivitys(txt);
        current = current->next;
    }
}
