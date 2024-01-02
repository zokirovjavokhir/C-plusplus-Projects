#include <iostream>
#include <cmath>
#include <string>

using namespace std;

// Use M_PI for the pi constant in math
// For example, the formula to get the circumference
// of a circle with a radius "r" would be "2 * M_PI * r"

// RoundShape base class
class RoundShape {
  public:
    // pure virtual functions (interfaces)
    virtual void shape_circumference() = 0;
    virtual void shape_area() = 0;

    // Member functions for RoundShape
    // All RoundShape instances can
    //   have the feature of areas and circumferences
    float get_area() const;
    void  set_area(float area);
    float get_circumference() const;
    void  set_circumference(float circumference);

  private:
    float circumference = 0.0;
    float area = 0.0;
};
float RoundShape::get_area() const {
    return area;
}

void RoundShape::set_area(float _area) {
    area = _area;
}

float RoundShape::get_circumference() const {
    return circumference;
}

void RoundShape::set_circumference(float _circumference) {
    circumference = _circumference;
}
/*
Circle class derived from the Shape class
	Circle circumference = 2 * PI * r
	Circle area = PI * r * r
*/ 
class Circle : public RoundShape {
public:
    Circle(float _radius) : radius(_radius) {}

    // Implementing pure virtual functions
    void shape_circumference() override;

    void shape_area() override;

private:
    float radius;
};

// Implementations of Circle member functions
void Circle::shape_circumference() {
    cout << "Circle Circumference: " << 2.0 * M_PI * radius << endl;
}

void Circle::shape_area() {
    cout << "Circle Area " << M_PI * pow(radius, 2) << endl;
}
/* 
Ellipse class derived from the Shape class
	Ellipse area = a * b * PI
	Ellipse circumference = 2 * PI * sqrt(1/2 * (a^2 + b^2))
*/
class Ellipse : public RoundShape {
	public:
    Ellipse(float _radius_a, float _radius_b) : radius_a(_radius_a), radius_b(_radius_b) {}

    // Implementing pure virtual functions
    void shape_circumference() override;

    void shape_area() override;

private:
    float radius_a;
    float radius_b;
};

// Implementations of Ellipse member functions
void Ellipse::shape_circumference() {
    cout << "Ellipse Circumference: " << (2.0 * M_PI * sqrt((pow(radius_a, 2) + pow(radius_b, 2)) / 2)) << endl;
}

void Ellipse::shape_area() {
    cout <<  "Ellipse Area " << M_PI * radius_a * radius_b << endl;
}


// Main function
int main() {

  int r;    // circle radius
  int a, b; // ellipse radiuses

  cout << "<< Enter a circle radius: ";
  cin >> r;

  Circle c(r);
  c.shape_circumference();
  c.shape_area();

  cout << "<< Enter two ellipse radiuses: ";
  cin >> a;
  cin >> b;

  Ellipse e(a,b);
  e.shape_circumference();
  e.shape_area();

  return 0;
}