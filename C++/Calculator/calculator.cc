#include "calculator.h"
#include <iostream>

using namespace std;

float Calculator::add(float a, float b){
	return a+b;
}

float Calculator::sub(float a, float b){
	return a-b;
}

float Calculator::mul(float a, float b){
	return a*b;
}
float Calculator::div(float a, float b){
	return a/b;
}
int Calculator::mod(int a, int b){
	return a%b;

}
float Calculator::poly(float a, int b){
	return pow(a,b);
}



