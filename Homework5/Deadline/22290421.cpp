// Ali Berkay Görgülü | 22290421

#include <iostream>
#include <vector>
#include <cmath>
#include <functional>

using namespace std;

class Homework5 {
private:
    int n = 0;
    int k = 0;
    
    vector<int> myVector;
public:
    void readInput();
    void writeOutput();
    void calculateAlgorithm();
    bool satisfiedCondition();
};

int main() {
    Homework5 homework5;

    homework5.readInput();
    homework5.calculateAlgorithm();
    homework5.writeOutput();

    return 0;
}

void Homework5::readInput()
{
    do {
        cout << "Please enter the length of the array: ";
        cin >> n;

        if (n <= 0 || floor(n) != n)
            cout << "The length of the array must be a positive integer" << endl;
    } while (n <= 0 || floor(n) != n);
}

void Homework5::writeOutput()
{
    cout << "k: " << k;
}

void Homework5::calculateAlgorithm()
{
    
}

bool Homework5::satisfiedCondition()
{
    
}