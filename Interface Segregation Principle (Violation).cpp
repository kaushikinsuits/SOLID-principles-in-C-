#include <iostream>

// Interface representing a document
class Document {
public:
    virtual void open() = 0;
    virtual void close() = 0;
    virtual void save() = 0;
    virtual void print() = 0;
};

// Class representsing a text document
class TextDocument : public Document {
public:
    void open() override { std::cout << "Text document opened.\n"; }
    void close() override { std::cout << "Text document closed.\n"; }
    void save() override { std::cout << "Text document saved.\n"; }
    void print() override { std::cout << "Text document printed.\n"; }
};

// Class representing a spreadsheet
class Spreadsheet : public Document {
public:
    void open() override { std::cout << "Spreadsheet opened.\n"; }
    void close() override { std::cout << "Spreadsheet closed.\n"; }
    void save() override { std::cout << "Spreadsheet saved.\n"; }
    void print() override { std::cout << "Spreadsheet printed.\n"; }
};

// Class representing a presentation
class Presentation : public Document {
public:
    void open() override { std::cout << "Presentation opened.\n"; }
    void close() override { std::cout << "Presentation closed.\n"; }
    void save() override { std::cout << "Presentation saved.\n"; }
    void print() override { std::cout << "Presentation printed.\n"; }
};

// Client code
void processDocument(Document& doc) {
    doc.open();
    doc.print();
    doc.save();
    doc.close();
}

int main() {
    TextDocument textDoc;
    Spreadsheet spreadsheet;
    Presentation presentation;

    processDocument(textDoc);
    processDocument(spreadsheet);
    processDocument(presentation);

    return 0;
}

/*
We have a Document interface with methods open(), close(), save(), and print().
Concrete classes like TextDocument, Spreadsheet, and Presentation implement this interface.
The processDocument() function takes a Document reference and performs operations on it.
This design violates ISP because clients like processDocument() have to depend on the entire Document interface, even if they don't need all the methods.
*/