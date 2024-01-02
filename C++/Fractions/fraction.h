#ifndef FRACTION_H
#define FRACTION_H

#include <string>
using namespace std;

class Fraction {
public:
    Fraction() : N(0), NU(0), D(0) {};
    Fraction(int n, int nu, int d) : N(n), NU(nu), D(d) {};
    Fraction sum(Fraction b);
    Fraction sum(double b);
    Fraction multiply(Fraction b);
    Fraction multiply(double b);
    void abbreviation();
    bool toMixedNum();
    void print();
    double toDouble();
    Fraction str2Fraction(string str);
    Fraction double2Fraction(double val);
    void setN(int n);
    int getN();
    void setNU(int nu);
    int getNU();
    void setD(int d);
    int getD();
    
private:
    int N;
    int NU;
    int D;
};

#endif
