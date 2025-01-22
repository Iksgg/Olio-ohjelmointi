#include <iostream>
#include "italianchef.h"

using namespace std;

int main()
{
    string name;
    string pass = "";
    int n;
    int ing;
    int water;
    int flour;

    cout << "Select chef type 1 for chef, 2 for italian chef: ";
    cin >> n;

    cout << "Enter chef name: ";
    cin >> name;

    if (n == 1){
        n = 0;
        Chef chef(name);
        cout << "Select recepie by typing 1 Salad or 2 Soup: ";
        cin >> n;

        if (n == 1){
            cout << "Salad recepie selected." << endl;
            cout << "give ingrediount amount: ";
            cin >> ing;

            chef.makeSalad(ing);

        } else if (n == 2){
            cout << "Soup recepie selected." << endl;
            cout << "give ingrediount amount: ";
            cin >> ing;

            chef.makeSoup(ing);

        }


    } else if (n == 2){
        n = 0;
        ItalianChef italian(name);
        cout << "Select recepie by typing 1 Salad, 2 Soup or 3 Pizza: ";
        cin >> n;

        if (n == 1){
            cout << "Salad recepie selected." << endl;
            cout << "give Ingredient amount: ";
            cin >> ing;

            italian.makeSalad(ing);

        } else if(n == 2){
            cout << "Soup recepie selected." << endl;
            cout << "give Ingredient amount: ";
            cin >> ing;

            italian.makeSoup(ing);

        } else if(n == 3){
            cout << "pizza recepie selected give password: " << endl;
            cin >> pass;
            cout << "give flour amount: ";
            cin >> flour;
            cout << "give water amount: ";
            cin >> water;

            italian.askSecret(pass, water, flour);
        }
    }

    return 0;
}
