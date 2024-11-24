// Ali Berkay Görgülü | 22290421

#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

class Homework4 {
private:
    int algorithmNumber;    // Algorithm number (0: MergeSort, 1: QuickSort, 2: QuickSort_M)
    int n;                  // Number of elements to sort
    vector<int> myNumbers;  // Vector holding the numbers to be sorted
public:
    /**
     * Reads input for the algorithm number, number of elements (n) and the numbers from an input stream.
     * Validates the input to ensure n is a positive integer and the algorithm number is valid.
     * @param inputStream: The stream from which to read the input.
     */
    void readFromStream(istream& inputStream);

    /**
     * Writes the selected algorithm and the sorted numbers to an output stream.
     * @param outputStream: The stream to which to write the output.
     */
    void writeToStream(ostream& outputStream);

    /**
     * Performs MergeSort on the input vector.
     * @param dVector: The divided vector to sort.
     * @param dN: The number of elements in the divided vector.
     * @return A sorted vector.
     */
    vector<int> mergeSort(vector<int> dVector, int dN);

    /**
     * Performs QuickSort on the input vector.
     * @param dVector: The divided vector to sort.
     * @param dN: The number of elements in the divided vector.
     * @return A sorted vector.
     */
    vector<int> quickSort(vector<int> dVector, int dN);

    /**
     * Performs QuickSort_M (modified QuickSort) on the input vector using the median element.
     * @param dVector: The divided vector to sort.
     * @param dN: The number of elements in the divided vector.
     * @return A sorted vector.
     */
    vector<int> quickSortM(vector<int> dVector, int dN);

    /**
     * Selects and applies the algorithm based on the input algorithm number.
     * 0: MergeSort, 1: QuickSort, 2: QuickSort_M.
     */
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
    }

    // Checks if n is a positive integer
    else if(n <= 0 || floor(n) != n) {
        cerr << "Invalid input: N must be a positive integer." << endl;
        exit(1);
    }

    // Checks if the algorithm number is valid (0, 1, or 2)
    else if (algorithmNumber != 0 && algorithmNumber != 1 && algorithmNumber != 2) {
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
    // Base case: If there is one or no element, return the vector
    if (dN <= 1) {return dVector;}
    
    vector<int> lVector, rVector;
    const int mid = floor(dN/2);

    // Splits the vector around the middle point
    for (size_t i = 0; i < mid; i++) {lVector.push_back(dVector[i]);}
    for (size_t i = mid; i < dN; i++) {rVector.push_back(dVector[i]);}

    const int lVectorN = lVector.size(), rVectorN = rVector.size();

    // Recursively applies merge sort to both halves
    vector<int> mLeftVector = mergeSort(lVector, lVectorN);
    vector<int> mRightVector = mergeSort(rVector, rVectorN);

    vector<int> mVector;

    int i = 0, j = 0;

    while(i < lVectorN || j < rVectorN) {
        // If one sub-vector is finished, add all remaining elements from the other sub-vector
        if (i == lVectorN) {
            mVector.push_back(mRightVector[j]);
            j++;
            continue;
        } 
        else if (j == rVectorN) {
            mVector.push_back(mLeftVector[i]);
            i++;
            continue;
        }

        // Compare the current elements from both sub-vectors
        // Add the smaller element to the result vector (mVector)
        // Only increment the index of the sub-vector from which the element was added
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
    // Base case: If there is one or no element, return the vector
    if (dN <= 1) {return dVector;}

    // Pivot is last element of dVector
    int pvtIndex = dN - 1, pvt = dVector[pvtIndex];

    // Left pointer starts from the first element
    // Right pointer starts from the last element before the pivot
    int left = 0, right = pvtIndex - 1;
    
    while (left <= right) {
        // Increases left pointer until dVector[left] is greater or equal to pvt
        if (dVector[left] < pvt) {
            left++;
            continue;
        }

        // Increases right pointer until dVector[right] is smaller or equal to pvt
        if (dVector[right] > pvt) {
            right--;
            continue;
        }

        // Swaps dVector[left] with dVector[right] when the above if statements are passed
        swap(dVector[left], dVector[right]);
        left++;
        right--;
    }

    // Swaps the pivot with dVector[left] to place pivot in the right spot
    if (dVector[left] > pvt) {swap(dVector[left], dVector[pvtIndex]);}
    pvtIndex = left;
    
    vector<int> lVector, rVector;

    // Splits the vector around the pivot
    for (size_t i = 0; i < pvtIndex; i++) {lVector.push_back(dVector[i]);}
    for (size_t i = pvtIndex + 1 ; i < dN; i++) {rVector.push_back(dVector[i]);}

    const int lVectorN = lVector.size(), rVectorN = rVector.size();

    // Recursively applies quick sort to both halves
    vector<int> mLeftVector = quickSort(lVector, lVectorN);
    vector<int> mRightVector = quickSort(rVector, rVectorN);

    // Merges two halves
    vector<int> mVector;
    mVector.insert(mVector.end(), mLeftVector.begin(), mLeftVector.end());
    mVector.push_back(pvt);
    mVector.insert(mVector.end(), mRightVector.begin(), mRightVector.end());
    
    return mVector;
}

vector<int> Homework4::quickSortM(vector<int> dVector, int dN)
{
    // Base case: If there is one or no element, return the vector
    if (dN <= 1) {return dVector;}

    double sum = 0;

    for (size_t i = 0; i < dN; i++) {sum += dVector[i];}

    // Finds the aritmetic average of the divided vector    
    const double avg = sum/dN;

    int pvtIndex = 0, pvt = dVector[pvtIndex];

    // Selects the index that is closest to the aritmetic average of the divided vector as the pivot
    for (size_t i = 0; i < dN; i++) {
        if (abs(avg - dVector[i]) < abs(avg - pvt)) {
            pvt = dVector[i];
            pvtIndex = i;
        }
    }

    swap(dVector[pvtIndex], dVector[dN - 1]);
    pvtIndex = dN - 1;
    pvt = dVector[pvtIndex];

    // Left pointer starts from the first element
    // Right pointer starts from the last element before the pivot
    int left = 0, right = pvtIndex - 1;
    
    while (left <= right) {
        // Increases left pointer until dVector[left] is greater or equal to pvt
        if (dVector[left] < pvt) {
            left++;
            continue;
        }

        // Increases right pointer until dVector[right] is smaller or equal to pvt
        if (dVector[right] > pvt) {
            right--;
            continue;
        }

        // Swaps dVector[left] with dVector[right] when the above if statements are passed
        swap(dVector[left], dVector[right]);
        left++;
        right--;
    }

    // Swaps the pivot with dVector[left] to place pivot in the right spot
    if (dVector[left] > pvt) {swap(dVector[left], dVector[pvtIndex]);}
    pvtIndex = left;
    
    vector<int> lVector, rVector;

    // Splits the vector around the pivot
    for (size_t i = 0; i < pvtIndex; i++) {lVector.push_back(dVector[i]);}
    for (size_t i = pvtIndex + 1 ; i < dN; i++) {rVector.push_back(dVector[i]);}

    const int lVectorN = lVector.size(), rVectorN = rVector.size();

    // Recursively applies quick sort to both halves
    vector<int> mLeftVector = quickSortM(lVector, lVectorN);
    vector<int> mRightVector = quickSortM(rVector, rVectorN);

    // Merges two halves
    vector<int> mVector;
    mVector.insert(mVector.end(), mLeftVector.begin(), mLeftVector.end());
    mVector.push_back(pvt);
    mVector.insert(mVector.end(), mRightVector.begin(), mRightVector.end());
    
    return mVector;
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
        myNumbers = quickSortM(myNumbers, n);
        break;

    default:
        cerr << "Invalid algorithm number." << endl;
        break;
    }
}
