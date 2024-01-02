#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
#include "guess.h"

using namespace std;


int GuessGame::generateRandomNumber() {
    return rand() % 100;
}


void GuessGame::play() {
    
    srand(static_cast<unsigned int>(time(NULL)));

    int targetNumber = generateRandomNumber();
    int guess;
    int attempts = 0;

    while (attempts < maxAttempts) {
        cout << "Enter your guess: ";
        cin >> guess;

        if (cin.fail()) {
            cout << "Enter a number between 0 and 99" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (guess < 0 || guess >= 100) {
            cout << "Enter a number between 0 and 99" << endl;
            continue;
        }

        if (guess == targetNumber) {
            cout << "You Won!" << endl;
            break;
        } else if (guess < targetNumber) {
            cout << "More Larger" << endl;
        } else {
            cout << "More Smaller" << endl;
        }

        attempts++;
        cout << "Chances left: " << maxAttempts - attempts << endl;
    }

    if (attempts >= maxAttempts) {
        cout << "You Lose. The correct number was " << targetNumber << endl;
    }
}
