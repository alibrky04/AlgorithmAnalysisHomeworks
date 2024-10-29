#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Question3b {
private:
    vector<int> numbers;
    int size, number;
    vector<int> productArray;
public:
    void readFromFile();
    void writeToFile();
    void findProductArray();
};

int main() {
    Question3b question3b;

    question3b.readFromFile();
    question3b.findProductArray();
    question3b.writeToFile();

    return 0;
}

void Question3b::readFromFile()
{
    ifstream inputFile("input.txt");

    if (!inputFile) {
        cerr << "Unable to open file" << endl;
        return;
    }

    inputFile >> size;

    while (inputFile >> number) {
        numbers.push_back(number);
    }
}

void Question3b::writeToFile()
{
    ofstream outputFile("output.txt");

    if (!outputFile) {
        cerr << "Unable to open output file." << endl;
        return;
    }

    for (int i = 0; i < productArray.size(); ++i) {
        outputFile << productArray[i];
        if (i < productArray.size() - 1) {
            outputFile << endl;
        }
    }
}

void Question3b::findProductArray()
{
    int product = 1;

    for (int k = 0; k < size; k++)
    {
        product *= numbers[k];
    }

    for (int i = 0; i < size; i++)
    {
        productArray.push_back(product/numbers[i]);
    }
}