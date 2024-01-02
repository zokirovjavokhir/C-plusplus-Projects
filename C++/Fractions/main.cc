#include <iostream>
#include <string>
#include "fraction.h"

using namespace std;

int main() {
    double d2;
    string strFraction;
    Fraction frac1;
    Fraction frac2;

    cin >> strFraction;
    cin >> d2;

    frac1.str2Fraction(strFraction);
    frac2.double2Fraction(d2);
    frac2.print();
    frac1.sum(frac2);
    frac1.sum(d2);
    frac2.multiply(frac1);
    frac2.multiply(d2);
    frac1.toDouble();
    frac2.toDouble();

    return 0;
}
