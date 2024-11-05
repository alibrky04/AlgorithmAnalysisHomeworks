// Ali Berkay Görgülü | 22290421

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Question3a {
private:
    vector<int> numbers;      // Stores numbers read from the input file
    int size, number;         // `size` is the number of elements; `number` is used for reading each element
    vector<int> productArray; // Stores the product of all elements except the current element
public:
    void readFromFile();      // Reads numbers from the file and populates `numbers`
    void writeToFile();       // Writes the contents of `productArray` to an output file
    void findProductArray();  // Calculates the product array based on `numbers`
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

    // Read each number and add to `numbers` vector
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

    // Write each element of `productArray` to the file
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

        for (int k = 0; k < size; k++) {
            if (k != i) { product *= numbers[k]; } // Skip the current element
        }

        productArray.push_back(product);
    }
}