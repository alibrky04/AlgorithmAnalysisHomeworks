#include <iostream>
#include <vector>
#include <cmath>
#include <functional>

using namespace std;

class Homework5 {
private:
    int k = 0;                // Counter to keep track of the step number
    int n = 0;                // Size of the array
    vector<int> myVector;     // Vector to hold the input data

public:
    /**
     * Reads the length of the array and initializes the vector with zeros.
     * Ensures the length is a positive integer.
     */
    void readInput();

    /**
     * Writes the value of k to the output.
     */
    void writeOutput();

    /**
     * Recursively calculates the algorithm based on the input vector.
     * Modifies the vector based on the specified conditions and calls itself on sub-vectors.
     * @param dVector: The vector to process.
     * @param length: The number of elements in the vector.
     * @param canIncrease: A boolean indicating whether k can be incremented.
     */
    void calculateAlgorithm(vector<int> dVector, const int length, const bool canIncrease);

    /**
     * Gets the size of the vector (n).
     * @return The value of n.
     */
    int getN();

    /**
     * Gets the current vector holding input data.
     * @return The vector of integers.
     */
    vector<int> getMyVector();
};

int main() {
    Homework5 homework5;

    homework5.readInput();
    homework5.calculateAlgorithm(homework5.getMyVector(), homework5.getN(), true);
    homework5.writeOutput();

    return 0;
}

void Homework5::readInput()
{
    do {
        cout << "Please enter the length of the array: ";
        cin >> n;

        // Validate that the length is a positive integer.
        if (n <= 0 || floor(n) != n)
            cout << "The length of the array must be a positive integer" << endl;
    } while (n <= 0 || floor(n) != n);

    // Initialize the vector with n zeros.
    myVector.insert(myVector.end(), n, 0);
}

void Homework5::writeOutput() {
    // Print the value of k.
    cout << "k: " << k;
}

void Homework5::calculateAlgorithm(vector<int> dVector, const int length, const bool canIncrease)
{
    // Base case: if the length is 1 or less, return without processing.
    if (length <= 1) { return; }

    // Iterate three times to modify the vector based on even and odd indexed elements.
    for (size_t i = 0; i < 3; i++) {
        if (i == 0) {
            // Increment all even-indexed elements.
            for (size_t j = 0; j < length; j += 2) {
                dVector[j]++;
            }
        } else {
            // Increment all odd-indexed elements.
            for (size_t j = 1; j < length; j += 2) {
                dVector[j]++;
            }
        }

        // Increment k if the current step is unique.
        if (canIncrease) { k++; }
    }

    // Create sub-vectors for odd and even indexed elements.
    vector<int> oddVector, evenVector;

    for (size_t i = 0; i < length; i++) {
        if (i % 2 == 0) {
            oddVector.push_back(dVector[i]);
        } else {
            evenVector.push_back(dVector[i]);
        }
    }

    // Recursively process the sub-vectors.
    calculateAlgorithm(oddVector, oddVector.size(), canIncrease);
    calculateAlgorithm(evenVector, evenVector.size(), false);
}

int Homework5::getN() { return n; }

vector<int> Homework5::getMyVector() { return myVector; }