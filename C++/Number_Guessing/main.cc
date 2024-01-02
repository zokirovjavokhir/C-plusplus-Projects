#include <iostream>
#include "guess.h"

int main() {
    using namespace std;

    cout << "Welcome to the Number Guessing Game!" << endl;

    GuessGame game;
    game.play();

    return 0;
}
