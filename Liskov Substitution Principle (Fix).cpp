#include <iostream>

class Shape {
public:
    virtual int area() const = 0;
};

class Rectangle : public Shape {
protected:
    int width;
    int height;
public:
    Rectangle(int w, int h) : width(w), height(h) {}
    void setWidth(int w) { width = w; }
    void setHeight(int h) { height = h; }
    int getWidth() const { return width; }
    int getHeight() const { return height; }
    int area() const override { return width * height; }
};

class Square : public Shape {
private:
    int side;
public:
    Square(int s) : side(s) {}
    int area() const override { return side * side; }
};

void processShape(const Shape& shape) {
    std::cout << "Area: " << shape.area() << std::endl;
}

int main() {
    Rectangle rectangle(5, 4);
    Square square(5);
    processShape(rectangle);
    processShape(square);
    return 0;
}
