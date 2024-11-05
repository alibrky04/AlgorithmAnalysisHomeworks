// Ali Berkay Görgülü | 22290421

#include <iostream>
#include <fstream>
#include <string>
#include <array>

using namespace std;

class Question1 {
private:
    array<int, 2> numbers; // Array to hold two integers
public:
    void readFromFile();   // Method to read numbers from a file
    void writeToFile();    // Method to write GCD to a file
    int calculateGCD(int number1, int number2); // Method to calculate the GCD of two numbers
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

    // Read the numbers from the input file
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

    // Calculate the GCD and write it to the output file
    outputFile << calculateGCD(numbers[0], numbers[1]);
}

int Question1::calculateGCD(int number1, int number2) {
    if (number1 == 0) return number2; // If number1 is zero, GCD is number2
    if (number2 == 0) return number1; // If number2 is zero, GCD is number1
    
    int gcd = 1;

    while (number1 % 2 == 0 && number2 % 2 == 0) {
        number1 /= 2;
        number2 /= 2;
        gcd *= 2; // Multiply GCD by 2 for each factor removed
    }

    while (number1 != 0 && number2 != 0) {
        if (number1 % 2 == 0) {
            number1 /= 2; // If number1 is even, divide by 2
        } else if (number2 % 2 == 0) {
            number2 /= 2; // If number2 is even, divide by 2
        } else {
            // If both numbers are odd, subtract the smaller from the larger
            if (number1 > number2) {
                number1 = (number1 - number2) / 2;
            } else {
                number2 = (number2 - number1) / 2;
            }
        }
    }

    // Return the GCD, which is the last non-zero number multiplied by the power of 2 that was factored out.
    return gcd * (number1 == 0 ? number2 : number1);
}