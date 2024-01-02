#include <iostream>
using namespace std;
template <typename T>
class Calculator {
public:
    T add(T a, T b) {
        return a + b;
    }
    T subtract(T a, T b) {
        return a - b;
    }
    T multiply(T a, T b) {
        return a * b;
    }
    T divide(T a, T b) {
        if (b != 0) {
            return a / b;
        } else {
            cerr << "Error: Division by zero!" << endl;
            return static_cast<T>(0);
        }
    }
    T sum_arr(T arr[], int n) {
        T sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += arr[i];
        }
        return sum;
    }
     void seq_mul(T& sum, T x, int n) {
        sum = 1;
        for (int i = 1; i <= n; ++i) {
            sum += i * x;
        }
    }
};
int main(){
  Calculator<int> intCalc;
  Calculator<double> doubleCalc;
        
  cout << "#1: 5+7=" << intCalc.add(5,7) << endl;
  cout << "#2: 2.3+5.6=" << doubleCalc.add(2.3,5.6) << endl;
        
  cout << "#3: 10-3=" << intCalc.subtract(10,3)  << endl;
  cout << "#4: 50.3-5.5=" << doubleCalc.subtract(50.3,5.5)  << endl;

  cout << "#5: 4*8=" << intCalc.multiply(4,8)  << endl;
  cout << "#6: 2.3*8.8=" << doubleCalc.multiply(2.3,8.8)  << endl;

  cout << "#7: 10/2=" << intCalc.divide(10,2)  << endl;
  cout << "#8 6.2/2.0=" << doubleCalc.divide(6.2,2.0)  << endl;

  int int_arr[5] = {1,2,3,4,5};
  double double_arr[5] = {1.1, 2.2, 3.3, 4.4, 5.5};

  cout << "#9: Sum of int array: " << intCalc.sum_arr(int_arr, 5) << endl;
  cout << "#10: Sum of double array: " << doubleCalc.sum_arr(double_arr, 5) << endl;

  int int_sum=0;
  double double_sum=0.0;

  intCalc.seq_mul(int_sum, 5, 5);
  doubleCalc.seq_mul(double_sum, 7.0, 10);

  cout << "#11: Sum of sequence int vals: " << int_sum << endl;
  cout << "#12: Sum of sequence double vals: " << double_sum << endl;


  return 0;
}
