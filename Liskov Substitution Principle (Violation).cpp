#include <iostream>

class Rectangle {
protected:
    int width;
    int height;
public:
    Rectangle(int w, int h) : width(w), height(h) {}
    void setWidth(int w) { width = w; }
    void setHeight(int h) { height = h; }
    int getWidth() const { return width; }
    int getHeight() const { return height; }
    int area() const { return width * height; }
};

class Square : public Rectangle {
public:
    Square(int size) : Rectangle(size, size) {}
    void setWidth(int w) override {
        width = height = w;
    }
    void setHeight(int h) override {
        width = height = h;
    }
};

void processRectangle(Rectangle& rect) {
    int width = rect.getWidth();
    rect.setHeight(10);
    std::cout << "Area: " << rect.area() << std::endl;
}

int main() {
    Rectangle rectangle(5, 4);
    Square square(5);
    processRectangle(rectangle);
    processRectangle(square); // This will print incorrect area for square
    return 0;
}

/*
We have a Rectangle class with setWidth(), setHeight(), and area() methods.
Square inherits from Rectangle, and when setting the width or height, it sets both to the same value.
We have a processRectangle() function that accepts a reference to a Rectangle object and modifies its height.
*/