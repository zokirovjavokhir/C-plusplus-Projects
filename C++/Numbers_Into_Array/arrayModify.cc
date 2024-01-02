#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isValidNumber(int num) {
    return (num >= 0 && num <= 9);
}

void receiveNumbers(vector<int>& numbers) {
    numbers.clear();
    int num;
    int validCount = 0;
    bool invalidInput = false;

    cout << "Enter 10 numbers(0-9): ";
    bool errorPrinted = false;

    for (int i = 0; i < 10; ) { 
        if (cin >> num) {
            if (isValidNumber(num)) {
                numbers.push_back(num);
                validCount++;
                i++;
            } else {
                invalidInput = true;
                if (!errorPrinted) {
                    cout << "Invalid input. Please enter numbers between 0 to 9" << endl;
                    errorPrinted = true;
                }
            }
        } else {
            cin.clear(); // Clear the error state
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (!errorPrinted) {
                cout << "Invalid input. Please enter numbers between 0 to 9." << endl;
                errorPrinted = true;
            }
        }
    }

    if (validCount != 10 || invalidInput) {
        cout << "Invalid input. Please enter exactly 10 numbers." << endl;
    }
}





void arrayModify(vector<int>& numbers) {
    for (int& num : numbers) {
        if (num % 2 == 1) {
            num *= 2; 
        } else {
            num += 1;
        }
    }

 
    sort(numbers.begin(), numbers.end());
}


void printArray(const vector<int>& numbers) {
    for (const int& num : numbers) {
        cout << num << " ";
    }
    cout << endl;
}