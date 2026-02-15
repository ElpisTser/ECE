#include <cstdio>
using namespace std;

int main() {
    int size;
    int *arr;
    
    // Take array size as input from user
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Dynamically allocate an array
    arr = new int[size];

    // Assign values to the array elements
    for (int i=0; i<size; i++) {
        arr[i] = i + 1;
    }

    // Print the array elements
    printf("The elements of the array are: ");
    for (int i=0; i<size; i++) {
        printf("%d ", arr[i]);
    }

    // Deallocate the memory
    delete[] arr;

    return 0;
}