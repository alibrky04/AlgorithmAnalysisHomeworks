// Ali Berkay Görgülü | 22290421

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Homework4 {
private:
    int algorithmNumber;
    int n;
    vector<int> myNumbers;
public:
    void readFromStream(istream& inputStream);
    void writeToStream(ostream& outputStream);
    vector<int> mergeSort(vector<int> dVector, int dN);
    vector<int> quickSort(vector<int> dVector, int dN);
    vector<int> quickSortM();
    void pickAlgorithm();
};

int main() {
    Homework4 homework4;

    homework4.readFromStream(cin);
    homework4.pickAlgorithm();
    homework4.writeToStream(cout);

    return 0;
}

void Homework4::readFromStream(istream& inputStream)
{
    inputStream >> algorithmNumber;
    inputStream >> n;

    for (size_t i = 0; i < n; i++) {
        int k;
        inputStream >> k;
        myNumbers.push_back(k);
    }

    if (inputStream.fail()) {
        cerr << "Input stream failed." << endl;
        exit(1);
    }else if(n <= 0 || floor(n) != n) {
        cerr << "Invalid input: N must be a positive integer." << endl;
        exit(1);
    }else if (algorithmNumber != 0 && algorithmNumber != 1 && algorithmNumber != 2) {
        cerr << "Invalid input: Algorithm number can be: 0 (MergeSort), 1 (QuickSort) or 2 (QuickSort_M)." << endl;
        exit(1);
    }
}

void Homework4::writeToStream(ostream& outputStream)
{
    switch (algorithmNumber) {
    case 0:
        outputStream << "MergeSort" << endl;
        break;
    
    case 1:
        outputStream << "QuickSort" << endl;
        break;
    
    case 2:
        outputStream << "QuickSort_M" << endl;
        break;

    default:
        cerr << "Invalid algorithm number." << endl;
        break;
    }

    for (size_t i = 0; i < n; i++) {
        outputStream << myNumbers[i];
        if (i < n - 1) {
            outputStream << endl;
        }
    }
}

vector<int> Homework4::mergeSort(vector<int> dVector, int dN)
{
    if (dN == 1) {return dVector;}
    
    vector<int> lVector, rVector;
    const int mid = floor(dN/2);

    for (size_t i = 0; i < mid; i++) {lVector.push_back(dVector[i]);}
    for (size_t i = mid; i < dN; i++) {rVector.push_back(dVector[i]);}

    const int lVectorN = lVector.size(), rVectorN = rVector.size();

    vector<int> mLeftVector = mergeSort(lVector, lVectorN);
    vector<int> mRightVector = mergeSort(rVector, rVectorN);

    vector<int> mVector;

    int i = 0, j = 0;

    while(i < lVectorN || j < rVectorN) {
        if (i == lVectorN){
            mVector.push_back(mRightVector[j]);
            j++;
            continue;
        }else if (j == rVectorN) {
            mVector.push_back(mLeftVector[i]);
            i++;
            continue;
        }

        if (mLeftVector[i] < mRightVector[j]) {
            mVector.push_back(mLeftVector[i]);
            i++;
        }else {
            mVector.push_back(mRightVector[j]);
            j++;
        }
    }
    
    return mVector;
}

vector<int> Homework4::quickSort(vector<int> dVector, int dN)
{
    if (dN == 1) {return dVector;}

    const int pvtIndex = dN - 1, pvt = dVector[pvtIndex];

    for (int i = 0, int j = 1; j != pvtIndex; j++)
    {
        if (dVector[j] < dVector[i]) {
            dVector[j] += dVector[i];
            dVector[i] = dVector[j] - dVector[i];
            dVector[j] = dVector[j] - dVector[i];
            
            i++;
        }
    }
    
}

vector<int> Homework4::quickSortM()
{

}

void Homework4::pickAlgorithm()
{
    switch (algorithmNumber) {
    case 0:
        myNumbers = mergeSort(myNumbers, n);
        break;
    
    case 1:
        myNumbers = quickSort(myNumbers, n);
        break;
    
    case 2:
        myNumbers = quickSortM();
        break;

    default:
        cerr << "Invalid algorithm number." << endl;
        break;
    }
}
