#include <iostream>
using namespace std;

int main() {
    int arrayToSort[50];
    int arraySize;
    cout << "Give the size of the array you want to sort in ascending order: ";
    cin >> arraySize;

    cout << "Give the elements of the array:" << endl;
    
    // Fill array
    for (int i=0; i<arraySize; i++) {
        int currentElement;
        cin >> currentElement;
        arrayToSort[i] = currentElement;
    }

    // Sort array
    for (int i=1; i<arraySize; i++) {
        int j = i;
        int currentNum = arrayToSort[j];
        while ((j>0) && arrayToSort[j-1] > currentNum) {
            arrayToSort[j] = arrayToSort[j-1];
            j--;
        }
        arrayToSort[j] = currentNum;
    }

    // Print sorted array
    for (int i=0; i<arraySize; i++) {
        cout << arrayToSort[i] << " ";
    }
}