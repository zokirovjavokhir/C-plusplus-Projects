#include <iostream>
using namespace std;

/* Description
   Build a class to compute
   1) GCD (Greatest Common Divisor) and
   2) LCM (Least Common Multiple)
    by taking two unsigned integers as an input
*/

class MyCalculator
{
private: int num1, num2;

public:
    void assign(int m, int n) {
        num1 = m;
        num2 = n;
    }

    int gcd() {
        int a = num1;
        int b = num2;
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    int lcm() {
        return (num1 * num2) / gcd();
    }
// Declare member variables and member functions
};

// Your code here: Mutator - assign()


// Your code here: Implementation for GCD - gcd()


// Your code here: Implementation for LCM - lcm()
int main() {

        // Take two integers as an input
        unsigned int m, n;

        cin >> m;
        cin >> n;

        // Create a MyCalculator instance
        MyCalculator cal;
        cal.assign(m, n);
        cout << cal.gcd() << " " << cal.lcm() << endl;
}