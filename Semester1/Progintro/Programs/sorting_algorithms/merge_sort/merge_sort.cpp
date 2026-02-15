#include <iostream>
using namespace std;

void merge(int arrayToSort[], int first, int mid, int last); 

void mergesort(int arrayToSort[], int first, int last) {
    if (first >= last) return;

    int mid = (first + last) / 2;

    mergesort(arrayToSort, first, mid);
    mergesort(arrayToSort, mid+1, last);

    merge(arrayToSort, first, mid, last);
}

void merge(int arrayToSort[], int first, int mid, int last) {
    int firstHalfIndex = first;
    int secondHalfIndex = mid + 1;
    int tempArray[last - first + 1];
    int tempArrayIndex = 0;

    // Merge two already-sorted subarrays [first..mid] and [mid+1..last] into tempArray
    while ((firstHalfIndex <= mid) && (secondHalfIndex <= last)) {
        if (arrayToSort[firstHalfIndex] < arrayToSort[secondHalfIndex]) {
            tempArray[tempArrayIndex++] = arrayToSort[firstHalfIndex++];
        } else {
            tempArray[tempArrayIndex++] = arrayToSort[secondHalfIndex++];
        }
    }

    // Copy any remaining elements from the non-exhausted half
    // 0 or 1 of the loops will be executed
    while (firstHalfIndex <= mid) {
        tempArray[tempArrayIndex++] = arrayToSort[firstHalfIndex++];
    }
    while (secondHalfIndex <= last) {
        tempArray[tempArrayIndex++] = arrayToSort[secondHalfIndex++]; 
    }
    
    // Copy the merged, sorted elements back into the original array segment
    for (int i=0; i<tempArrayIndex; i++) {
        arrayToSort[first + i] = tempArray[i];
    }
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
    mergesort(arrayToSort, 0, arraySize - 1);

    // Print sorted array
    for (int i=0; i<arraySize; i++) {
        cout << arrayToSort[i] << " ";
    }
}