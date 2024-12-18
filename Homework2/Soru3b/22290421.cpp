// Ali Berkay Görgülü | 22290421

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Question3b {
private:
    vector<int> numbers;        // Stores numbers from input file
    int size, number;           // `size` is the number of elements; `number` is used to read each element
    vector<int> productArray;   // Stores the product of all elements except the current element
public:
    void readFromFile();        // Reads numbers from file into `numbers`
    void writeToFile();         // Writes `productArray` contents to output file
    void findProductArray();    // Fills `productArray` with products
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

    // Read each number and add to `numbers` vector
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

    // Write each element of `productArray` to the file
    for (int i = 0; i < productArray.size(); ++i) {
        outputFile << productArray[i];
        if (i < productArray.size() - 1) {
            outputFile << endl;
        }
    }
}

void Question3b::findProductArray()
{
    vector<int> prefix(size, 1);
    vector<int> suffix(size, 1);

    // Fill the prefix array where each element is the product of all elements to its left
    for (int i = 1; i < size; i++) { prefix[i] = prefix[i - 1] * numbers[i - 1]; }

    // Fill the suffix array where each element is the product of all elements to its right
    for (int i = size - 2; i >= 0; i--) { suffix[i] = suffix[i + 1] * numbers[i + 1]; }

    // Calculate the final product array by multiplying prefix and suffix products for each index
    for (int i = 0; i < size; i++) { productArray.push_back(prefix[i] * suffix[i]); }
}