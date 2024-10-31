// Ali Berkay Görgülü | 22290421

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Question2 {
private:
    vector<int> numbers;              // Vector to hold the numbers read from the input file
    int size, number;                 // `size` is the number of elements; `number` is used to read each element
    vector<vector<int>> subArrays;    // 2D vector to hold subarrays created from `numbers`
public:
    void readFromFile();              // Method to read numbers from a file
    void writeToFile();               // Method to write subarrays to a file
    void divideIntoSubArrays();       // Method to divide the numbers into subarrays
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

    // Read each number and add it to the `numbers` vector
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
        outputFile << " *"; // Marker indicating the end of the subarray
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

        // Create subarrays by including numbers in descending order
        for (j = i + 1; numbers[j] < numbers[j - 1]; j++) {
            if (j == size) {break;}
            
            subArray.push_back(numbers[j]);
        }

        subArrays.push_back(subArray);
    }
}