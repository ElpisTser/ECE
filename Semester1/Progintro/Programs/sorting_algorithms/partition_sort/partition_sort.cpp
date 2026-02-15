#include <iostream>
using namespace std;

void swap(int &a, int &b) {
    int save = a;
    a = b;
    b = save;
}

int partition(int arrayToSort[], int first, int last);

void quicksort(int arrayToSort[], int first, int last) {
    if (first >= last) return;

    int partitionBoundry = partition(arrayToSort, first, last);

    quicksort(arrayToSort, first, partitionBoundry);
    quicksort(arrayToSort, partitionBoundry+1, last);
}

int partition(int arrayToSort[], int first, int last) {
    int leftIndex = first; // index to the part of the array that is <= pivot
    int rightIndex = last; // index to the part of the array that is >= pivot
    int pivot = arrayToSort[(first+last)/2];

    while (true) {
        while (arrayToSort[leftIndex] < pivot) leftIndex++;
        while (arrayToSort[rightIndex] > pivot) rightIndex--;
        
        if (leftIndex >= rightIndex) break;
        
        swap(arrayToSort[leftIndex], arrayToSort[rightIndex]);
        leftIndex++;
        rightIndex--;
    }
    return rightIndex;
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
    quicksort(arrayToSort, 0, arraySize-1);

    // Print sorted array
    for (int i=0; i<arraySize; i++) {
        cout << arrayToSort[i] << " ";
    }
}

/*
Why return rightIndex inside partition() and then inside quicksort run
    quicksort(arrayToSort, first, rightIndex);
    quicksort(arrayToSort, rightIndex+1, last);
instead of returning leftIndex with
    quicksort(arrayToSort, first, lastIndex-1);
    quicksort(arrayToSort, leftIndex, last)

In the case of a two element, already sorted array, the leftIndex is never is increased,
leftIndex = first would get returned and would create an infinite recursion.
The same problem would occur if we returned rightIndex=last, but this scenario never happens.
    In the scenario above, arrayToSort[righIndex] would start at a value > pivot = arrayToSort[(first+last)/2] = arrayToSort[first],
    so it would be decreased by 1 before being returned.
    In the scenario of a two element, unsorted array, arrayToSort[leftIndex] and arrayToSort[rightIndex] would get swapped,
    so the rightIndex would again be decrased by 1 before being returned
*/