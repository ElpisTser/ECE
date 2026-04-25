#include "Array.hpp"
#include <iostream>
using namespace std;

void printArrayElement(const Array<int>& arr, int i) {
    std::cout << arr[i];
}

int main() {
    try {
        // 1. Test Constructor (Length 5, Base Index 10)
        // Indices will be 10, 11, 12, 13, 14
        Array<int> arr(5, 10);

        // 2. Test Non-const operator[]
        for (int i=0; i<5; i++) {
            arr[10 + i] = (i + 1);
        }

        // 3. Test const operator[], this is called because printArrayElement
        // takes a const array reference as an argument
        cout << "Array contents: ";
        for (int i=0; i<5; i++) {
            printArrayElement(arr, 10 + i);
        }
        cout << endl;

        // 4. Test Copy Constructor
        Array<int> copyArr = arr;
        cout << "Copy check (index 10): " << copyArr[10] << endl;

        // 5. Test Exception Handling
        cout << "Testing out-of-range (index 9)..." << endl;
        cout << arr[9] << endl; // This should throw 
    } catch (const std::out_of_range& e) {
        cerr << "Caught expected exception: " << e.what() << endl;
    }

    return 0;
}