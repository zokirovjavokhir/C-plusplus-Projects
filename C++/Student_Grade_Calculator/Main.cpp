#include <iostream>
#include <string>
using namespace std;
class Person{
	public:
	  int age;
//complete Person class definition
  Person(){
this->name = "";
		this->age = 0;
}

Person(string name, int age){
	this->name = name;
	if(age < 0){
      cout << "age must be positive!" << endl;
		  cout << "setting age is 0" << endl;
		this->age = 0;
	}else{
		this->age = age;
}
}

    void getName() const{
        cout << "person name is: " << name << endl;
    }

    void getAge() const{
            cout << "person age is: " << age << endl;
        }
private:
	  string name;
};
class Student
: public Person
{
 public:
	 Student()
	 {
		 number = 0;
		 grade = 0;
	 }
	
	 Student(int num, int grd, string str, int age): Person(str, age), number(num), grade(grd)
	 {}
	
	 ~Student(){};
	
	 int getNumber(){ return number; }
	 int getGrade(){ return grade; }
	 void getAge();
	
	private:
	 int number;
	 int grade;
};
//Implement getAge member function
 void Student::getAge(){
    cout << "student age is: " << age << endl;
}

class Grader
{
	public:
	  Grader(){
			studentNum = 0;
		};
	  void addStudent(Student stu);
	  int sum();
	  int min();
	  int max();
	  int studentNum;
	
	private:
	  Student student[50];
};
//Implement member functions in Grader class

void Grader::addStudent(Student stu){
	student[studentNum] = stu;
	studentNum++;
}

    int Grader::sum() {
        int total = 0;
        for (int i = 0; i < studentNum; i++) {
            total += student[i].getGrade();
        }
        return total;
    }

    int Grader::min() {
        int minValue = 9999999;
        for (int i = 0; i < studentNum; i++) {
            if (student[i].getGrade() < minValue) {
                minValue = student[i].getGrade();
            }
        }
        return minValue;
    }

    int Grader::max() {
        int maxValue = -1;
        for (int i = 0; i < studentNum; i++) {
            if (student[i].getGrade() > maxValue) {
                maxValue = student[i].getGrade();
            }
        }
        return maxValue;
    }

class StudentGrader : public Grader
{
public:
  StudentGrader(){}
  //Complete class definition	
	int aveg(){
      return sum() / studentNum;
}
};
int main() {
	Person person1("Jason", 30);
	person1.getName();
	person1.getAge();
	
	Student student1(1,30, "Alice", 10);
	student1.getName();
	student1.getAge();
	
	Student student2(2,90,"Bob", 30);
	student2.getName();
	student2.getAge();
	
	Student student3(3,100, "Jack", 20);
	student3.getName();
	student3.getAge();
	
	Student student4(4,50, "Jane", 15);
	student4.getName();
	student4.getAge();
	
	Student student5(5,100, "Jenny", -10);
	student5.getName();
	student5.getAge();
	
	StudentGrader cal;
	cal.addStudent(student1);
	cal.addStudent(student2);
	cal.addStudent(student3);
	cal.addStudent(student4);
	cal.addStudent(student5);
	
	cout << endl;
	cout << "Min of scores: " << cal.min() << endl;
	cout << "Max of scores: " << cal.max() << endl;
	cout << "Sum of scores: " << cal.sum() << endl;
	cout << "Average of scores: " << cal.aveg() << endl;
	return 0;
}