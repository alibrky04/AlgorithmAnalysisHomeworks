// Ali Berkay Görgülü | 22290421

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Question2 {
private:
public:
    void readFromFile();
    void writeToFile();
};

int main() {
    Question2 question2;

    question2.readFromFile();
    question2.writeToFile();

    return 0;
}

void Question2::readFromFile()
{
    ifstream inputFile("input.txt");
    
    if (!inputFile) {
        cerr << "Unable to open input file." << endl;
        return;
    }
}

void Question2::writeToFile()
{
    ofstream outputFile("output.txt");

    if (!outputFile) {
        cerr << "Unable to open output file." << endl;
        return;
    }
}
