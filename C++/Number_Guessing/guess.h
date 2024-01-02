//DO NOTE MODIFY THIS FILE!!!!!!

#ifndef GUESS_H
#define GUESS_H

class GuessGame {
public:
    
    void play();

private:
    
    int generateRandomNumber();

    const int maxAttempts = 8;
};

#endif
