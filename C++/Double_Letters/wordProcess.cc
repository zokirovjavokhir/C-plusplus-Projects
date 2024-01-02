#include <string>
#include <algorithm>
#include "wordProcess.h"


int countConsecutiveDoubleLetters(const std::string& word) {
    int count = 0;
    char prevChar = '\0'; 

    for (char c : word) {
        if (isalpha(c)) {
            if (c == prevChar) {
                count++;
            }
            prevChar = c;
        }
    }

    return count;
}
