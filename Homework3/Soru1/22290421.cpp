// Ali Berkay Görgülü | 22290421

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

class Question1 {
private:
    int N;                          // Number of cups
    vector<int> cups;               // Vector to hold the state of each cup (1 = open, 0 = closed)
    vector<int> cupNumbers;         // Vector to hold the cup numbers (1, 2, ..., N)
public:
    /**
     * Reads input for the number of cups (N) from an input stream.
     * @param inputStream: The stream from which to read the input.
     * Checks that N is a positive integer. If not, the program exits.
     */
    void readFromStream(istream& inputStream);

    /**
     * Writes the state of the cups to an output stream.
     * @param outputStream: The stream to which the result will be written.
     * This function will output the numbers of the cups that remain open.
     */
    void writeToStream(ostream& outputStream);

    /**
     * Initializes the cups vector with N elements, all set to 0 (closed).
     * Also initializes the cupNumbers vector with numbers 1 to N.
     */
    void createCups();

    /**
     * Performs the operations on the cups. The cups' states are toggled based on
     * the rules described: for each round, cups whose numbers are divisible by the round number are toggled.
     */
    void doOperations();                            
};

int main() {
    Question1 question1;

    question1.readFromStream(cin);
    question1.createCups();
    question1.doOperations();
    question1.writeToStream(cout);

    return 0;
}

void Question1::readFromStream(istream& inputStream)
{
    inputStream >> N;

    if (inputStream.fail() || N <= 0 || floor(N) != N) {
        cerr << "Invalid input: N must be a positive integer." << endl;
        exit(1);
    }
}

void Question1::writeToStream(ostream& outputStream)
{
    string output;
    for (size_t i = 0; i < N; i++) {
        if (cups[i]) {
            output += to_string(cupNumbers[i]) + '\n';
        }
    }

    if (!output.empty()) { output.pop_back(); }
    outputStream << output;
}

void Question1::createCups()
{
    cups.assign(N, 0);

    for (size_t i = 0; i < N; i++) { cupNumbers.push_back(i + 1); }
}

void Question1::doOperations()
{
    for (size_t i = 0; i < N; i++) {
        for (size_t k = 0; k < N; k++) {
            if (cupNumbers[k] % (i + 1) == 0) { cups[k] = !cups[k]; } // Operation on cup
        }
    }
}
