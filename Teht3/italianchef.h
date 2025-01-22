#ifndef ITALIANCHEF_H
#define ITALIANCHEF_H
#include "chef.h"
#include <string>

using namespace std;

class ItalianChef : public Chef
{
public:
    ItalianChef(string);
    ~ItalianChef();
    bool askSecret(string, int, int);

private:
    string password = "pizza";
    int flour;
    int water;
    int makepizza(int, int);
};

#endif // ITALIANCHEF_H
