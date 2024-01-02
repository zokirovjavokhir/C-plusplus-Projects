#include <iostream>
#include <string>

class MyClass {
private:
    int roomNo;
    std::string name;
public:
      MyClass() : roomNo(0), name("Unknown") {
        
    }

    MyClass(int roomNumber, const std::string& className) : roomNo(roomNumber), name(className){} 

MyClass (int roomNumber):roomNo(roomNumber){
name = "None";
}
    MyClass(const MyClass& other) : roomNo(other.roomNo), name(other.name) {
		}

    ~MyClass() {
        std::cout << "Destructor called for object with name " << name << std::endl;
    }
 void display() {
        std::cout << "Room: " << roomNo << ", Class Name: " << name << std::endl;
    }
};
int main() {  
	MyClass obj1; 
  MyClass obj2(27316, "Security");
  MyClass obj3 = obj2; 
  MyClass obj4(obj2); 
	
	MyClass obj5;
	obj5 = MyClass(55330);
	
	MyClass obj6;
	
 
 obj6 = MyClass(77003, "CPE");  

    obj1.display();
    obj2.display();
    obj3.display();
    obj4.display();
    obj5.display();
    obj6.display();

    return 0;
}