#include <iostream>
#include <vector>
#include <fstream>
#include "wordProcess.h"

int main() {
    std::ifstream inputFile("words.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Error: Could not open the file 'words.txt'" << std::endl;
        return 1;
    }

    std::vector<std::string> wordsWithMostDoubleLetters;
    int maxDoubleLetterCount = 0;

    std::string word;
    while (inputFile >> word) {
        transform(word.begin(), word.end(), word.begin(), ::tolower);

        int doubleLetterCount = countConsecutiveDoubleLetters(word);

        if (doubleLetterCount > maxDoubleLetterCount) {
            maxDoubleLetterCount = doubleLetterCount;
            wordsWithMostDoubleLetters.clear();
            wordsWithMostDoubleLetters.push_back(word);
        } else if (doubleLetterCount == maxDoubleLetterCount) {
            wordsWithMostDoubleLetters.push_back(word);
        }
    }

    inputFile.close();

    std::cout << "Words with the most consecutive double letters (" << maxDoubleLetterCount << " pairs):" << std::endl;
    for (const std::string& word : wordsWithMostDoubleLetters) {
        std::cout << word << std::endl;
    }

    return 0;
}
