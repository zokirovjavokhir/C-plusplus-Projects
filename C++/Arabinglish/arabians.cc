#include <algorithm>
#include <cctype>
#include "arabians.h"


std::string cpe::reverseString(const std::string& target) {
    std::string reversed = target;
    std::reverse(reversed.begin(), reversed.end());
    return reversed;
}


void cpe::processDigits(std::string& reversedInput) {
    int n = reversedInput.length();
    int i = 0;
    while (i < n) {
        int temp = i;
        while (isdigit(reversedInput[i])) {
            i++;
        }
        if (temp != i) {
            int m = i - temp;
            for (int k = 0; k < m / 2; k++) {
                std::swap(reversedInput[temp + k], reversedInput[i - k - 1]);
            }
        }
        i++;
    }
}
