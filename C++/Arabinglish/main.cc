#include <iostream>
#include <string>
#include "arabians.h"
#include "display.h"

int main() {
    using namespace std;

    string input;

    cout << "English sentence: ";
    getline(cin, input);

    string reversedInput = cpe::reverseString(input);
    cpe::processDigits(reversedInput);

    cpe::customPrint(reversedInput);
    cout << endl;

    return 0;
}
