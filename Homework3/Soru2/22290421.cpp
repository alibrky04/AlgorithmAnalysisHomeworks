// Ali Berkay Görgülü | 22290421

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

class Question2 {
private:
    double n;            // Input number for which the log value will be calculated
    int intLogValue = 1; // Integer log value initialized to 1
public:
    /**
     * Reads the input value (n) from the input stream.
     * @param inputStream: The stream from which the input will be read.
     * This function validates that n is a positive integer.
     */
    void readFromStream(istream& inputStream);

    /**
     * Writes the integer log value to the output stream.
     * @param outputStream: The stream to which the result will be written.
     */
    void writeToStream(ostream& outputStream);

    /**
     * Calculates the integer logarithm of n (log base 2) and stores the result in intLogValue.
     * The function computes the log value iteratively, dividing n by 2 until it reaches 1.
     */
    void findIntLogValue();
};

int main() {
    Question2 question2;

    question2.readFromStream(cin);
    question2.findIntLogValue();
    question2.writeToStream(cout);   

    return 0;
}

void Question2::readFromStream(istream& inputStream)
{
    inputStream >> n;

    if (inputStream.fail() || n <= 0 || floor(n) != n) {
        cerr << "Invalid input: n must be a positive integer." << endl;
        exit(1);
    }
}

void Question2::writeToStream(ostream& outputStream)
{
    outputStream << intLogValue;
}

void Question2::findIntLogValue()
{
    // Special case when n is 1, the log value is 0
    if (n == 1) {
        intLogValue = 0;
        return;
    }
    
    // Perform the integer log calculation by dividing n by 2 until it reaches 1
    while (n > 2)
    {
        const int temp_n = n;
        n /= 2;
        intLogValue++;

        // Adjust the log value if n is a even number
        if (n == 1 && temp_n == 2) { intLogValue--; }
    }
}
