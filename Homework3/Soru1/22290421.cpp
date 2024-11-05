// Ali Berkay Görgülü | 22290421

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Question1 {
private:
    int N;
    vector<int> cups;
    vector<int> cupNumbers;
public:
    void readFromFile();
    void writeToFile();
    void createCups();
    void doOperations();
};

int main() {
    Question1 question1;

    question1.readFromFile();
    question1.createCups();
    question1.doOperations();
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

    inputFile >> N;
}

void Question1::writeToFile()
{
    ofstream outputFile("output.txt");

    if (!outputFile) {
        cerr << "Unable to open output file." << endl;
        return;
    }

    string output;
    for (size_t i = 0; i < N; i++) { if (cups[i]) { output += to_string(cupNumbers[i]) + '\n'; } }

    if (!output.empty()) { output.pop_back(); }

    outputFile << output;
}

void Question1::createCups()
{
    vector<int> createdCups(N, 0);
    cups = createdCups;

    for (size_t i = 0; i < N; i++) { cupNumbers.push_back(i+1); }
}

void Question1::doOperations()
{
    for (size_t i = 0; i < N; i++) {
        for (size_t k = 0; k < N; k++) {
            if (cupNumbers[k] % (i + 1) == 0) { cups[k] = !cups[k]; }
        }
    }
}
