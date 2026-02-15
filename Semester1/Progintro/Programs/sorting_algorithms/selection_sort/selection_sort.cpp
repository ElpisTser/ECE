#include <iostream>
using namespace std;

void swap(int &a, int &b) {
    int save;
    save = a;
    a = b;
    b = save;
}

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
    for (int i=0; i<arraySize-1; i++) {
        int minPosition = i;
        for (int j=i+1; j<arraySize; j++) {
            if (arrayToSort[j] < arrayToSort[minPosition]) {
                minPosition = j;
            }
        }
        swap(arrayToSort[i], arrayToSort[minPosition]);
    }

    // Print sorted array
    for (int i=0; i<arraySize; i++) {
        cout << arrayToSort[i] << " ";
    }
}