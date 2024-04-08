#include <iostream>
#include <vector>
#include <memory>

// Single Responsibility Principle (SRP)
class FileReader {
public:
    std::string readFile(const std::string& filename) {
        std::string content;
        // Read file content
        std::cout << "Reading file: " << filename << std::endl;
        // For demonstration, let's assume we read content from a file
        content = "File content of " + filename;
        return content;
    }
};

class DataProcessor {
public:
    void processData(const std::string& data) {
        // Process data
        std::cout << "Processing data: " << data << std::endl;
        // For demonstration, let's just print the data
    }
};

// Open/Closed Principle (OCP)
class DataAnalyzer {
public:
    void analyzeData(const std::string& data) {
        // Analyze data
        std::cout << "Analyzing data: " << data << std::endl;
        // For demonstration, let's just print the analysis
    }
};

// Liskov Substitution Principle (LSP)
class Shape {
public:
    virtual double area() const = 0;
    virtual ~Shape() = default;
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() const override {
        return 3.14 * radius * radius; // Area of circle = π * r^2
    }
};

class Square : public Shape {
private:
    double side;
public:
    Square(double s) : side(s) {}
    double area() const override {
        return side * side; // Area of square = side^2
    }
};

// Interface Segregation Principle (ISP)
class Printable {
public:
    virtual void print() const = 0;
    virtual ~Printable() = default;
};

class Savable {
public:
    virtual void save() const = 0;
    virtual ~Savable() = default;
};

class TextDocument : public Printable, public Savable {
public:
    void print() const override {
        std::cout << "Printing text document\n";
    }
    void save() const override {
        std::cout << "Saving text document\n";
    }
};

// Dependency Inversion Principle (DIP)
class Report {
private:
    std::shared_ptr<Printable> printable;
public:
    Report(std::shared_ptr<Printable> p) : printable(p) {}
    void generateReport() const {
        printable->print();
    }
};

int main() {
    // SRP
    FileReader fileReader;
    std::string data = fileReader.readFile("data.txt");

    DataProcessor dataProcessor;
    dataProcessor.processData(data);

    // OCP
    DataAnalyzer dataAnalyzer;
    dataAnalyzer.analyzeData(data);

    // LSP
    Circle circle(5.0);
    Square square(4.0);
    std::cout << "Area of circle: " << circle.area() << std::endl;
    std::cout << "Area of square: " << square.area() << std::endl;

    // ISP
    TextDocument textDoc;
    textDoc.print();
    textDoc.save();

    // DIP
    std::shared_ptr<Printable> printable = std::make_shared<TextDocument>();
    Report report(printable);
    report.generateReport();

    return 0;
}