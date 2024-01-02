#include <iostream>
#include <vector>
#include "arrayModify.h"

int main() {
    std::vector<int> numbers;

    receiveNumbers(numbers); 

    arrayModify(numbers); 

    printArray(numbers);

    return 0;
}
