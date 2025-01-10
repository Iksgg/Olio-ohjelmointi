#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int game(int maxNum);

int main()
{
    // Ask for maximum value for number used to cap random number generator
    int max;
    cout << "Anna suurin raja arvo: ";
    cin >> max;

    int qCount = game(max);
    cout << "Arvakset: " << qCount << "\n";

    return 0;
}

int game(int maxNum)
{
    int state = 0;
    int userNum;
    int count = 0;

    //Random number generator
    srand(time(0));
    int rNum = rand() % maxNum + 1;

    do{
        //Ask user number
        cout << "Anna numero 1-20: ";
        cin >> userNum;

        //Compare numbers
        if (rNum > userNum){
            cout << "Luku on pienempi \n";
            count++;
        }else if (rNum < userNum){
            cout << "Luku on suurempi \n";
            count++;
        }else if (rNum == userNum){
            cout << "Oikea vastaus \n";
            count++;
            state = 1;
        }
    }
    while(state == 0);

    return count;
}
