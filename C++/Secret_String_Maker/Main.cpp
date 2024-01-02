#include <iostream>
#include <string>
using namespace std;

//This function convert input to secret string and prints it.
//string target : Original input string
//int num : indicates number of secret characters
void printSecretStr(string target, int num){
if (num > target.length()) {
	cout << "String is too short" << endl;
}
	else{
		for (size_t i = 0; i < target.length(); ++i){
			if (i < num || target[i] == ' '){
				cout << target[i];
}
			else{
				cout << '*';
	}
}
	cout << endl;
	}
}
bool customInput(string& str, int& num){
    cout << "";
    getline(cin, str);

    size_t dollarPos = str.find('$');
    if (dollarPos != string::npos) {
        string numStr = str.substr(0, dollarPos);

	bool isValidNumber = true;
	for (char c : numStr) {
	if (!isdigit(c) && c != '-'){
		isValidNumber = false;
	break;
	}
}

	if (isValidNumber){
	num = stoi(numStr);
		str = str.substr(dollarPos + 1);

	if (num < 0){
	cout << "Incorrect Number!" << endl;
	return false;
}

if (num > str.length()){
	cout << "String is too short" << endl;
	return false;
}

	return true;
	}
}

	cout << "Incorrect Number!" << endl; //couldn't find a way to use one incorrect number outpus that's why i used two. if there's any easier way to do this i'd like to get an opinion.
	return false;
}
int main()
{
	//stores user input
	string str; 
	
	//stores number of secrete characters
	int num; 

	if(customInput(str,num)){
		printSecretStr(str,num);
	}
	return 0;
}