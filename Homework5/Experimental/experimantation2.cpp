#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Homework5 {
private:
    int k = 0;                // Counter to keep track of the step number
    int n = 0;                // Size of the array
    vector<int> myVector;     // Vector to hold the input data

public:
    void readInput();
    void writeOutput();
    void calculateAlgorithm(vector<int>& dVector, const string& prefix = "");
    vector<int> getMyVector();
};

int main() {
    Homework5 homework5;
    homework5.readInput();
    homework5.calculateAlgorithm(homework5.getMyVector());
    homework5.writeOutput();
    return 0;
}

void Homework5::readInput() {
    cout << "Please enter the length of the array: ";
    cin >> n;
    myVector.assign(n, 0);
}

void Homework5::writeOutput() {
    cout << "Minimum k: " << k << endl;
}

void Homework5::calculateAlgorithm(vector<int>& dVector, const string& prefix) {
    int length = dVector.size();
    if (length <= 1) return;

    // Divide the vector into odd and even indexed elements
    vector<int> oddVector, evenVector;
    for (size_t i = 0; i < length; i++) {
        if (i % 2 == 0)
            oddVector.push_back(dVector[i]);
        else
            evenVector.push_back(dVector[i]);
    }

    // Increment odd indexed elements
    for (size_t i = 0; i < oddVector.size(); i++) {
        oddVector[i]++;
    }
    k++; // Increment step counter
    cout << "Step " << k << " (Odd indices incremented in " << prefix << "): ";
    for (int val : oddVector) cout << val << " ";
    cout << endl;

    // Increment even indexed elements
    for (size_t i = 0; i < evenVector.size(); i++) {
        evenVector[i]++;
    }
    k++; // Increment step counter
    cout << "Step " << k << " (Even indices incremented in " << prefix << "): ";
    for (int val : evenVector) cout << val << " ";
    cout << endl;

    // Recursively process the sub-vectors
    calculateAlgorithm(oddVector, prefix + "Odd->");
    calculateAlgorithm(evenVector, prefix + "Even->");

    // Combine the results back into the original vector
    for (size_t i = 0; i < length; i++) {
        if (i % 2 == 0)
            dVector[i] = oddVector[i / 2];
        else
            dVector[i] = evenVector[i / 2];
    }

    // Print the combined array at the current level
    cout << "After merging " << prefix << ": ";
    for (int val : dVector) cout << val << " ";
    cout << endl;
}

vector<int> Homework5::getMyVector() { return myVector; }