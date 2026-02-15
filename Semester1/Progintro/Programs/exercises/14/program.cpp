#include <cstdio>

void merge(int table[], int first, int mid, int last);

void mergesort(int table[], int first, int last) {
    if (first >= last) return;
    
    int mid = (first + last) / 2;

    mergesort(table, first, mid);
    mergesort(table, mid+1, last);

    merge(table, first, mid, last);
}

void merge(int table[], int first, int mid, int last) {
    int firstHalfIndex = first;
    int secondHalfIndex = mid + 1;
    int* tempArray = new int[last - first + 1];
    int tempArrayIndex = 0;

    while ((firstHalfIndex <= mid) && (secondHalfIndex <= last)) {
        if (table[firstHalfIndex] < table[secondHalfIndex])
            tempArray[tempArrayIndex++] = table[firstHalfIndex++];
        else
            tempArray[tempArrayIndex++] = table[secondHalfIndex++];
    }


    while (firstHalfIndex <= mid)
        tempArray[tempArrayIndex++] = table[firstHalfIndex++];
    while (secondHalfIndex <= last)
        tempArray[tempArrayIndex++] = table[secondHalfIndex++];

    for (int i=0; i<tempArrayIndex; i++) {
        table[first + i] = tempArray[i];
    }
}

void scanArray(int array[], int arraySize) {
    for (int i=0; i<arraySize; i++) 
        scanf("%d", &array[i]);
}

void printArray(int array[], int arraySize) {
    for (int i=0; i<arraySize; i++)
        printf("%d ", array[i]);
}

int main () {
    int arraySize;
    printf("Give the size if the arrays: ");
    scanf("%d", &arraySize);

    if (arraySize > 50000) {
        printf("Too big!\n");
        return 0;
    }

    int* array1 = new int[arraySize];
    int* array2 = new int[arraySize];

    printf("Give the elements of the first array: ");
    scanArray(array1, arraySize);
    
    printf("Give the elements of the second array: ");
    scanArray(array2, arraySize);

    mergesort(array1, 0, arraySize-1);
    mergesort(array2, 0, arraySize-1);

    bool equalArrays = true;
    int arrayIndex = 0;
    while (arrayIndex < arraySize) {
        if (array1[arrayIndex] != array2[arrayIndex]) {
            equalArrays = false;
            break;
        }
        arrayIndex++;
    }

    if (equalArrays) {
        printf("yes\n");
        return 0;
    }

    int min, max;
    int firtsDiffentElement = arrayIndex;

    //Find min element if arrays are not equal
    if (array1[firtsDiffentElement] < array2[firtsDiffentElement]) {
        min = array1[firtsDiffentElement];
        max = array2[firtsDiffentElement];
    }
    else {
        min = array2[firtsDiffentElement];
        max = array1[firtsDiffentElement];
    }

    // Find max element if arrays are not equal
    // If all elements after the first unequal element found are equal, keep the previous max
    arrayIndex = arraySize - 1;
    while (arrayIndex > firtsDiffentElement) {
        if (array1[arrayIndex] > array2[arrayIndex]) {
            max = array1[arrayIndex];
            break;
        } else if (array1[arrayIndex] < array2[arrayIndex]) {
            max = array2[arrayIndex];
            break;
        } else
            arrayIndex--;
    }

    printf("no %d %d", min, max);    
}

