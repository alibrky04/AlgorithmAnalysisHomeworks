#include <iostream>
#include <fstream>
#include <string>
#include <array>

using namespace std;

class Question1 {
private:
    array<int, 2> numbers;;
public:
    void readFromFile();
    void writeToFile();
    int calculateGCD(int number1, int number2);
};

int main() {
    Question1 question1;

    question1.readFromFile();
    question1.writeToFile();

    return 0;
}

void Question1::readFromFile()
{
    ifstream inputFile("input.txt");
    
    if (!inputFile) {
        cerr << "Unable to open input file." << endl;
        return;
    }

    for (int &number : numbers) {
        if (!(inputFile >> number)) {
            cerr << "Error reading number." << endl;
            return;
        }
    }
}

void Question1::writeToFile()
{
    ofstream outputFile("output.txt");

    if (!outputFile) {
        cerr << "Unable to open output file." << endl;
        return;
    }

    outputFile << calculateGCD(numbers[0], numbers[1]);
}

int Question1::calculateGCD(int number1, int number2) {
    if (number1 == 0) return number2;
    if (number2 == 0) return number1;
    
    int gcd = 1;

    while (number1 % 2 == 0 && number2 % 2 == 0) {
        number1 /= 2;
        number2 /= 2;
        gcd *= 2;
    }

    while (number1 != 0 && number2 != 0) {
        if (number1 % 2 == 0) {
            number1 /= 2;
        } else if (number2 % 2 == 0) {
            number2 /= 2;
        } else {
            if (number1 > number2) {
                number1 = (number1 - number2) / 2;
            } else {
                number2 = (number2 - number1) / 2;
            }
        }
    }

    return gcd * (number1 == 0 ? number2 : number1);
}