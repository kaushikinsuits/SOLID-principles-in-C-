#include <iostream>

// Interfaces representing document operations
class Openable {
public:
    virtual void open() = 0;
};

class Savable {
public:
    virtual void save() = 0;
};

class Printable {
public:
    virtual void print() = 0;
};

// Concrete classes implementing the interfaces
class TextDocument : public Openable, public Savable, public Printable {
public:
    void open() override { std::cout << "Text document opened.\n"; }
    void save() override { std::cout << "Text document saved.\n"; }
    void print() override { std::cout << "Text document printed.\n"; }
};

class Spreadsheet : public Openable, public Savable, public Printable {
public:
    void open() override { std::cout << "Spreadsheet opened.\n"; }
    void save() override { std::cout << "Spreadsheet saved.\n"; }
    void print() override { std::cout << "Spreadsheet printed.\n"; }
};

class Presentation : public Openable, public Savable, public Printable {
public:
    void open() override { std::cout << "Presentation opened.\n"; }
    void save() override { std::cout << "Presentation saved.\n"; }
    void print() override { std::cout << "Presentation printed.\n"; }
};

// Client code
void processDocument(Openable& doc) {
    doc.open();
}

void processDocument(Printable& doc) {
    doc.print();
}

void processDocument(Savable& doc) {
    doc.save();
}
int main() {
    TextDocument textDoc;
    Spreadsheet spreadsheet;
    Presentation presentation;

    processDocument(static_cast<Openable&>(textDoc));
    processDocument(static_cast<Openable&>(spreadsheet));
    processDocument(static_cast<Openable&>(presentation));

    processDocument(static_cast<Printable&>(textDoc));
    processDocument(static_cast<Printable&>(spreadsheet));
    processDocument(static_cast<Printable&>(presentation));

    processDocument(static_cast<Savable&>(textDoc));
    processDocument(static_cast<Savable&>(spreadsheet));
    processDocument(static_cast<Savable&>(presentation));

    return 0;
}
