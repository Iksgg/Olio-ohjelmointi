#include "game.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


Game::Game(int n){
    maxNumber = n;
    numOfGuesses = 0;
    cout << "GAME CONSTRUCTOR: object initialized with " << maxNumber << " as a maximum value" << endl;
    srand(time(0));
    randomNumber = rand() % maxNumber + 1;
}

Game::~Game()
{
    printGameResult();
    cout << "GAME DESTRUCTOR: object cleared" << endl;
}

void Game::play()
{
    int state = 0;

    do{
        cout << "Give a number between 1 and " << maxNumber << ": \n";
        cin >> playerGuess;

        if(randomNumber > playerGuess){
            cout << "Number is larger \n";
            numOfGuesses++;
        }else if(randomNumber < playerGuess){
            cout << "Number is smaller \n";
            numOfGuesses++;
        }else if(randomNumber == playerGuess){
            cout << "Correct! \n";
            numOfGuesses++;
            state = 1;
        }
    }
    while(state == 0);
}

void Game::printGameResult()
{
    cout <<"Answer: "<< randomNumber << " Guesses: " << numOfGuesses << endl;
}
