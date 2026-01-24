#include <iostream>
using namespace std;
class Shape {
public:
    virtual double area() = 0; 
};
class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() override {
        return 3.14 * radius * radius;
    }
};
class Square : public Shape {
private:
    double side;
public:
    Square(double s) : side(s) {}
    double area() override {
        return side * side;
    }
};
int main() {
    Circle circle(7.0);
    Square square(2.0);
    cout<<"Area of Circle: "<<circle.area()<<endl;
    cout<<"Area of Square: "<<square.area()<<endl;
    return 0;
}
