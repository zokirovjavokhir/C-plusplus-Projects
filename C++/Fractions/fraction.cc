#include "fraction.h"
#include <iostream>
#include <string>

using namespace std;

void Fraction::setN(int n) {N = n;}
void Fraction::setNU(int nu) {NU = nu;}
void Fraction::setD(int d) {D = d;}
int Fraction::getN() {return N;}
int Fraction::getNU() {return NU;}
int Fraction::getD() {return D;}

Fraction Fraction::str2Fraction(string str){
    int posNU;
    int posD;
    int i;
    string stringNU;
    string stringD;

    int strLen = str.length();
    for(i = 0; i < strLen; i++){
        if(str[i] < '/' || str[i] > '9'){
            cout << "Incorrect Input" << endl;
            exit(0);
        }
    }
    Fraction::setN(stoi(str));
    posNU = str.find('/');
	posD=str.find('/',(posNU+1));

    if(posD == (posNU + 1)){
        cout << "Incorrect Input" << endl;
        exit(0);
    }
    else if((posNU == -1) || (posD == -1)){
        cout << "Incorrect Input" << endl;
        exit(0);
    }
    stringD = str.substr((posD + 1), strLen);
    stringNU = str.substr((posNU + 1), posD);

    if(stoi(stringD) == 0){
        cout << "Incorrect Input" << endl;
        exit(0);
    }
    Fraction::setNU(stoi(stringNU));
    Fraction::setD(stoi(stringD));

    if(Fraction::getD() == 1){
        Fraction::setN(Fraction::getN() + Fraction::getNU());
        Fraction::setNU(0);
        Fraction::setD(0);
    }
    Fraction::print();
    return Fraction(stoi(str), stoi(stringNU), stoi(stringD));  
}
double Fraction::toDouble() {
    double res = 0.0;
    long valOfNU;

    if (Fraction::getD() != 0) {
        valOfNU = (Fraction::getN() * Fraction::getD()) + Fraction::getNU();
        res = static_cast<double>(valOfNU) / Fraction::getD();
    }
    else if(Fraction::getD() == 0 && Fraction::getNU() == 0){
        res = Fraction::getN();
    }
    cout.precision(6);
    cout << fixed << res << endl;
    return res;
}   
void Fraction::print(){
    cout<<Fraction::getN()<<" and "<<Fraction::getNU()<<"/"<<Fraction::getD()<<endl;
}
Fraction Fraction::double2Fraction(double val){
    int pos;
    double valueOne;
    double valueTwo;
    string stringValue;
    string stringFraction;    
	stringValue = to_string(val);

	if((val / (int)val) != 1.0){
    	valueOne = val * 10e6;
	    valueTwo = val * 10e5;

	    if(stod(stringValue) == 0){
    	    cout << "Incorrect Input" << endl;
        	exit(0);
	    }
    	if(((int)valueOne % (int)valueTwo) == 0){
	      Fraction::setN((int) val);
    	  pos = stringValue.find('.');
	      stringFraction = stringValue.substr(pos + 1);

    	  Fraction::setNU(stoi(stringFraction));
	      Fraction::setD(1000000);
    	  Fraction::abbreviation();
	    }
	    else{
    	  cout << "Incorrect Input" << endl;
	      exit(0);
	    }
    	return Fraction(((int)val), stoi(stringFraction), 1000000);
	}
	else{
		if(stod(stringValue) == 0){
    	    cout << "Incorrect Input" << endl;
        	exit(0);
		}	
		Fraction::setN((int)val);
		Fraction::setNU(0);
		Fraction::setD(0);

		return Fraction((int)val, 0, 0);
	}
}
Fraction Fraction::sum(Fraction b){
    Fraction res;   
    int temp1;
    int temp2;
    bool status;

    res.setN(Fraction::getN() + b.getN());
    if(Fraction::getD() == b.getD()){
        res.setNU(Fraction::getNU() + b.getNU());
        res.setD(Fraction::getD());
    }
    else{
        temp1 = Fraction::getNU() * b.getD();
        temp2 = Fraction::getD() * b.getNU();

        res.setNU(temp1 + temp2);
        res.setD(temp1 * temp2);
    }
    status = res.toMixedNum();
    
    if(status == true){
      res.abbreviation();
    }
    res.print();

    return res;
}
Fraction Fraction::sum(double b){
    Fraction res;
    Fraction fromDouble;

    int valNU1;
    int valNU2;
    bool status;

    fromDouble.double2Fraction(b);
    res.setN(Fraction::getN() + fromDouble.getN());

    if(Fraction::getD() == fromDouble.getD()){
        res.setNU(Fraction::getNU() + fromDouble.getNU());
        res.setD(Fraction::getD());
    }
    else{
        valNU1 = (Fraction::getN() * Fraction::getD()) + Fraction::getNU();
        valNU1 *= fromDouble.getD();
        valNU2 = (fromDouble.getN() * fromDouble.getD()) + fromDouble.getNU();
        valNU2 *= Fraction::getD();

        res.setNU(valNU1 + valNU2);
        res.setD(Fraction::getD() * fromDouble.getD());
    }
    status = res.toMixedNum();
    
    if(status == true){
      res.abbreviation();
    }
    res.print();

    return res;
}
Fraction Fraction::multiply(Fraction b){
    Fraction res;

    int tempNU_frac;
    int tempNU_double;
    bool status;

    if(Fraction::getN() != 0){
        tempNU_frac = (Fraction::getN() * Fraction::getD()) + Fraction::getNU();
    }
    else{
        tempNU_frac = Fraction::getNU();
    }

    if(b.getN() != 0){
        tempNU_double = (b.getN() * b.getD()) + b.getNU();
    }
    else{
        tempNU_double = b.getNU();
    }
    res.setNU(tempNU_frac * tempNU_double);
    res.setD(Fraction::getD() * b.getD());
 
    status = res.toMixedNum();

    if(status == true){
      res.abbreviation();
    }
    res.print();

    return res;
}
void Fraction::abbreviation(){
    int i;
    bool stat;

    if(Fraction::getD() % Fraction::getNU() == 0){
      Fraction::setD(Fraction::getD() / Fraction::getNU());
      Fraction::setNU(Fraction::getNU() / Fraction::getNU());
    }
    else if((Fraction::getD() != 0) || (Fraction::getNU() != 0)){
        while(true){
            if(Fraction::getNU() < 2){
              break;
            }     
            for(i = 2; i <= Fraction::getNU(); i++){
                if((Fraction::getNU() % i == 0) && (Fraction::getD() % i == 0)){
                    Fraction::setD(Fraction::getD() / i);
                    Fraction::setNU(Fraction::getNU() / i);
                    stat = true;
                    break;
                }
                else
                    stat = false;
            }   
            if(stat == false)
              break;
        }
    }
}
bool Fraction::toMixedNum(){
    int valN = 0;
    int valNU;
    bool status;

    while(Fraction::getNU() >= Fraction::getD()){
        Fraction::setN(Fraction::getN() + 1);
        valNU = Fraction::getNU() - Fraction::getD();

        if(valNU == 0){
            Fraction::setNU(valNU);
            Fraction::setD(0);
            break;
        }
        else
            Fraction::setNU(valNU);
    }
    if(valN == 0){
        status = false;
    }
    else{
      status = true;
    }
    if(status == false && Fraction::getNU() != 0 && Fraction::getD() != 0){
        Fraction::abbreviation();
    }
    return status;
}
Fraction Fraction::multiply(double b){

    Fraction res;
    Fraction fromDouble;

    int valNUFrac;
    int valNUDouble;
    bool status;

    fromDouble.double2Fraction(b);

    if(Fraction::getN() != 0){
        valNUFrac = (Fraction::getN() * Fraction::getD()) + Fraction::getNU();
    }
    else{
        valNUFrac = Fraction::getNU();
    }
    if(fromDouble.getN() != 0){
        valNUDouble = (fromDouble.getN() * fromDouble.getD()) + fromDouble.getNU();
    }
    else{
        valNUDouble = fromDouble.getNU();
    }

    res.setNU(valNUFrac * valNUDouble);
    res.setD(Fraction::getD() * fromDouble.getD());
    
    status = res.toMixedNum();

    if(status == true){
      res.abbreviation();
    }
    res.print();

    return res;
}