#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Question3a {
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
    Question3a question3a;

    question3a.readFromFile();
    question3a.findProductArray();
    question3a.writeToFile();

    return 0;
}

void Question3a::readFromFile()
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

void Question3a::writeToFile()
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

void Question3a::findProductArray()
{
    for (int i = 0; i < size; i++)
    {
        int product = 1;

        for (int k = 0; k < size; k++)
        {
            product *= numbers[k];
        }

        productArray.push_back(product/numbers[i]);
    }
}