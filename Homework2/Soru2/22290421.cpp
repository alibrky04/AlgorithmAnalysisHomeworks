#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Question2 {
private:
    vector<int> numbers;
    int size, number;
    vector<vector<int>> subArrays;
public:
    void readFromFile();
    void writeToFile();
    void divideIntoSubArrays();
};

int main() {
    Question2 question2;
    
    question2.readFromFile();
    question2.divideIntoSubArrays();
    question2.writeToFile();

    return 0;
}

void Question2::readFromFile()
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

void Question2::writeToFile()
{
    ofstream outputFile("output.txt");

    if (!outputFile) {
        cerr << "Unable to open output file." << endl;
        return;
    }

    for (size_t i = 0; i < subArrays.size(); i++) {
        for (size_t j = 0; j < subArrays[i].size(); j++) {
            outputFile << subArrays[i][j];
            if (j < subArrays[i].size() - 1) { outputFile << " "; }
        }
        outputFile << " *";
        if (i < subArrays.size() - 1) { outputFile << endl; }
    }
}

void Question2::divideIntoSubArrays()
{
    int i, j;

    for (i = 0; i < size; i = j) {
        const int starterNumber = numbers[i];
        vector<int> subArray;

        subArray.push_back(starterNumber);

        for (j = i + 1; numbers[j] < numbers[j - 1]; j++) {
            if (j == size) {break;}
            
            subArray.push_back(numbers[j]);
        }

        subArrays.push_back(subArray);
    }
}