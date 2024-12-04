// Ali Berkay Görgülü | 22290421

#include <iostream>
#include <vector>
#include <cmath>
#include <functional>

using namespace std;

struct indexValue {
    vector<int> isBigger;
    vector<int> isSmaller;
    int value = 0;
};

class Homework5 {
private:
    int n = 0;
    int k = 0;
    int total_moves;
    
    vector<indexValue> myVector;
public:
    void readInput();
    void writeOutput();
    void initAttributes();
    void calculateAlgorithm();
    bool satisfiedCondition();
};

int main() {
    Homework5 homework5;

    homework5.readInput();
    homework5.initAttributes();
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

void Homework5::initAttributes()
{
    indexValue templateIndexValue;
    myVector.insert(myVector.end(), n, templateIndexValue);

    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            if (i == j) {
                myVector[i].isBigger.push_back(2);
                myVector[i].isSmaller.push_back(2);
            }
            else{
                myVector[i].isBigger.push_back(0);
                myVector[i].isSmaller.push_back(0);
            }
        }
    }

    total_moves = (1 << n) - 1;
}

void Homework5::calculateAlgorithm()
{
    while (!satisfiedCondition()) {
        for (size_t move = 1; move < total_moves; move++) {
            vector<indexValue> tempVector = myVector;

            for (size_t i = 0; i < n; i++) {
                if (move & (1 << i)) {
                    tempVector[i].value++;
                }
            }
        }
    }
    
}

bool Homework5::satisfiedCondition()
{
    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < n; j++)
            if (!i == j) 
                if (!myVector[i].isBigger[j] || !myVector[i].isSmaller[j]) {return false;}

    return true;
}
