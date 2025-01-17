#include <iostream>
#include "game.h"

using namespace std;

int main()
{
    int max;
    cout << "Give maximum value: ";
    cin >> max;

    Game gameinstance(max);

    gameinstance.play();
    return 0;
}
