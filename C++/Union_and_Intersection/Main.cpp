#include <iostream>
#include <string>
#include <sstream>
#include<cctype>
#include <algorithm>
using namespace std;

class MySet
{
	private:
	 int* m_set; //Storing elements
	 int m_size; //Storing number of elements in the set
	 int m_maxSize; //Storing the maximum size of the set.

	public:
	 MySet(){
		 m_size=0;
		 m_maxSize=100;
		 m_set = new int[m_maxSize];
	 }
	
	 MySet(int size){
		 m_size = 0;
		 m_maxSize = size;
		 m_set = new int[m_maxSize];
	 }
	
	 MySet(int* setArg, int sizeArg){
		 int i = 0;
		 m_size = 0;
		 m_maxSize = 100;
		 m_set = new int[m_maxSize];
		 
		 for(i=0; i<sizeArg; i++)
			 m_set[i] = setArg[i];
		 
		 m_size = sizeArg;
	 }
	
	 ~MySet(){
	  if (!m_set){
			delete[] m_set;
			m_set = nullptr;
		}
	}
	
   //return the size of the elements stored in the array
	 int getSize() const;
	
   //returns the element of the given index in the array
	 int getItem(int index) const;

   //add new element into the array
	 void addItem(int val);

  //print the array elements
	 void print() const;
	
	MySet operator^(MySet right);
	MySet operator*(MySet right);
};
int MySet::getSize() const {
    return m_size;
}
int MySet::getItem(int index) const {
    if (index < 0 || index >= m_size) {
        return -1;
    }
    return m_set[index];
}
void MySet::addItem(int val) {
    if (m_size < m_maxSize) {
        m_set[m_size++] = val;
    }
}
void MySet::print() const {
    if (m_size == 0) {
        cout << "{0}" << endl;
    } else {
        cout << "{";
        for (int i = 0; i < m_size; ++i) {
            cout << m_set[i];
            if (i < m_size - 1) {
                cout << ", ";
            }
        }
    cout << "}" << endl;
}
}
MySet MySet::operator^(MySet right) {
    MySet result;
    for (int i = 0; i < m_size; ++i) {
        for (int j = 0; j < right.m_size; ++j) {
            if (m_set[i] == right.m_set[j]) {
                result.addItem(m_set[i]);
                break;
            }
        }
    }
    return result;
}
MySet MySet::operator*(MySet right) {
    MySet result = *this; 

    for (int i = 0; i < right.m_size; ++i) {
        bool existsInResult = false;
        for (int j = 0; j < m_size; ++j) {
            if (right.m_set[i] == m_set[j]) {
                existsInResult = true;
                break;
            }
        }
        if (!existsInResult) {
            result.addItem(right.m_set[i]);
        }
    }
    return result;
}
bool isNumber(const string& str){
//implement isNumber function. 
//This function check whether the input is integer
try {
        stoi(str);
        return true;
    } catch (const invalid_argument&) {
        return false;
    } catch (const out_of_range&) {
        return false;
    }
}
int main() {

  MySet set1, set2;
  string s1,s2;

  cout << "Enter the elements of the first set" << endl;
  getline(cin, s1);
  cout << "Enter the elements of the second set" << endl;
  getline(cin, s2);
 
	istringstream ss1(s1), ss2(s2);
    string token;

//write your code here.
//validate the input and add elements to the set1 and set2
while (getline(ss1, token, ',')) {
        if (isNumber(token)) {
            set1.addItem(stoi(token));
        } else {
               cout  << "Input must be integer!" << endl;  

            return 0;
        }
    }

    while (getline(ss2, token, ',')) {
        if (isNumber(token)) {
            set2.addItem(stoi(token));
        } else {
                
               cout  << "Input must be integer!" << endl;  

            return 0;
        }
    }
	cout << "Set1: ";
    set1.print();
cout << "Set2: ";
  set2.print();

  MySet inter;
	
  inter = set1^set2;
  cout << "Set1 ^ Set2 =";
  inter.print();

  MySet uni;
  uni = set1*set2;
  cout << "Set1 * Set2 =";
  uni.print();

	return 0;
}