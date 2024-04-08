#include <iostream>

// Base class representing a shape
class Shape {
public:
    virtual double area() const = 0; // Pure virtual function for calculating area
};

// Derived class representing a circle
class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() const override {
        return 3.14 * radius * radius; // Area of circle = π * r^2
    }
};

// Derived class representing a square
class Square : public Shape {
private:
    double side;
public:
    Square(double s) : side(s) {}
    double area() const override {
        return side * side; // Area of square = side^2
    }
};

// New requirement: Add a Triangle shape
class Triangle : public Shape { // Proper extension: Adding new class without modifying existing ones
private:
    double base;
    double height;
public:
    Triangle(double b, double h) : base(b), height(h) {}
    double area() const override {
        return 0.5 * base * height; // Area of triangle = (base * height) / 2
    }
};

int main() {
    Circle circle(5.0);
    Square square(4.0);
    Triangle triangle(3.0, 4.0); // New shape added

    std::cout << "Area of circle: " << circle.area() << std::endl;
    std::cout << "Area of square: " << square.area() << std::endl;
    std::cout << "Area of triangle: " << triangle.area() << std::endl; // New shape usage

    return 0;
}

/*
We properly extend the functionality by adding a new Triangle class derived from the Shape base class 
without modifying the existing Shape, Circle, or Square classes.
This adheres to the Open/Closed Principle because we are open for extension (adding new shapes) but 
closed for modification (existing classes remain unchanged).
*/