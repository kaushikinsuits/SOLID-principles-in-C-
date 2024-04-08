#include <iostream>
#include <fstream>
#include <string>

class FileReader {
public:
    void readFile(const std::string& filename) {
        std::ifstream file(filename);
        std::string line;
        while (std::getline(file, line)) {
            std::cout << "Read line: " << line << std::endl;
        }
    }
};

class FileWriter {
public:
    void writeFile(const std::string& filename, const std::string& data) {
        std::ofstream file(filename);
        file << data;
        std::cout << "Data written to file: " << filename << std::endl;
    }
};

int main() {
    FileReader fileReader;
    fileReader.readFile("input.txt");

    FileWriter fileWriter;
    fileWriter.writeFile("output.txt", "Hello, World!");

    return 0;
}


/*In this  code, the FileReader class is responsible for reading from a file, while the FileWriter
class is responsible for writing to a file. Each class now adheres to SRP by having only one reason
to change - either reading from or writing to a file.
*/





