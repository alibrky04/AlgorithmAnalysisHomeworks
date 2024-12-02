// Ali Berkay Görgülü | 22290421

#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

class Homework5 {
private:
    int n = 0;
    int k = 0;
    vector<int> myVector;
public:
    void readInput();
    void writeOutput();
    void calculateAlgorithmn();
};

int main() {
    Homework5 homework5;

    homework5.readInput();
    homework5.writeOutput();

    return 0;
}

void Homework5::readInput()
{
    do
    {
        cout << "Please enter the the length of the array: ";
        cin >> n;

        if (n <= 0 || floor(n) != n)
            cout << "The length of the array must be a positive integer" << endl;
    } while (n <= 0 || floor(n) != n);

    myVector.insert(myVector.end(), n, 0);
}

void Homework5::writeOutput()
{
    cout << "k: " << k;
}

void Homework5::calculateAlgorithmn()
{
    /*
    0 0 0
    1 0 0
    1 1 0
    1 2 1
    1 2 2
    1 2 3
    */
}
