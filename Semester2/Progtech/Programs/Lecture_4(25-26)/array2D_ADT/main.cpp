#include <iostream>
#include <stdexcept>
#include "Array2D.hpp"

using std::cout;
using std::endl;

// Helper function to print a section header, just for readability
void printHeader(const std::string& title) {
    cout << "\n=== " << title << " ===" << endl;
}

int main() {

    // -----------------------------------------------------------------------
    // TEST 1: Basic construction and element access with default base indices
    // Creates a 3x3 array of ints with base indices starting at 0 (default).
    // -----------------------------------------------------------------------
    printHeader("Basic construction and element access (base 0)");

    Array2D<int> arr(3, 3);

    // Populate using select()
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            arr.select(i, j) = i * 3 + j;

    // Read back using select()
    cout << "Populated via select(), read back via select():" << endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j)
            cout << arr.select(i, j) << " ";
        cout << endl;
    }

    // -----------------------------------------------------------------------
    // TEST 2: Two-step indexing with operator[][]
    // arr[i][j] should behave identically to arr.select(i, j).
    // arr[i]    returns a Row object capturing the row index.
    // arr[i][j] then calls Row::operator[](j) which calls select(row, j).
    // -----------------------------------------------------------------------
    printHeader("Two-step indexing arr[i][j]");

    // Populate using operator[][]
    Array2D<int> arr2(3, 3);
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            arr2[i][j] = i * 3 + j;

    cout << "Populated via arr[i][j], read back via arr[i][j]:" << endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j)
            cout << arr2[i][j] << " ";
        cout << endl;
    }

    // -----------------------------------------------------------------------
    // TEST 3: Non-zero base indices
    // Creates a 3x3 array whose valid indices start at 1 instead of 0.
    // So valid row indices are 1, 2, 3 and valid col indices are 1, 2, 3.
    // -----------------------------------------------------------------------
    printHeader("Non-zero base indices (base 1,1)");

    Array2D<int> arr3(3, 3, 1, 1);
    for (int i = 1; i <= 3; ++i)
        for (int j = 1; j <= 3; ++j)
            arr3[i][j] = i * 3 + j;

    cout << "Populated and read with base indices (1,1):" << endl;
    for (int i = 1; i <= 3; ++i) {
        for (int j = 1; j <= 3; ++j)
            cout << arr3[i][j] << " ";
        cout << endl;
    }

    // -----------------------------------------------------------------------
    // TEST 4: out_of_range exception from loc()
    // Accessing an index outside the valid range should throw std::out_of_range.
    // -----------------------------------------------------------------------
    printHeader("out_of_range exception");

    try {
        // arr has base 0, so index (5, 5) is out of range for a 3x3 array
        int val = arr[5][5];
        (void)val; // suppress unused variable warning
        cout << "ERROR: no exception thrown!" << endl;
    } catch (const std::out_of_range& e) {
        cout << "Caught expected exception: " << e.what() << endl;
    }

    try {
        // arr3 has base 1, so index (0, 0) is below the valid range
        int val = arr3[0][0];
        (void)val;
        cout << "ERROR: no exception thrown!" << endl;
    } catch (const std::out_of_range& e) {
        cout << "Caught expected exception: " << e.what() << endl;
    }

    // -----------------------------------------------------------------------
    // TEST 5: Copy constructor
    // The copy should be a deep copy — modifying the copy should not affect
    // the original.
    // -----------------------------------------------------------------------
    printHeader("Copy constructor");

    Array2D<int> arrCopy(arr2);
    arrCopy[0][0] = 99;

    cout << "Original arr2[0][0] (should be 0): " << arr2[0][0] << endl;
    cout << "Copied arrCopy[0][0] (should be 99): " << arrCopy[0][0] << endl;

    // -----------------------------------------------------------------------
    // TEST 6: Assignment operator
    // Same deep copy guarantee as the copy constructor.
    // -----------------------------------------------------------------------
    printHeader("Assignment operator");

    Array2D<int> arrAssigned(3, 3);
    arrAssigned = arr2;
    arrAssigned[1][1] = 42;

    cout << "Original arr2[1][1] (should be 4): " << arr2[1][1] << endl;
    cout << "Assigned arrAssigned[1][1] (should be 42): " << arrAssigned[1][1] << endl;

    // -----------------------------------------------------------------------
    // TEST 7: Self-assignment
    // Should be handled gracefully without corrupting data.
    // -----------------------------------------------------------------------
    printHeader("Self-assignment");

    arr2 = arr2;
    cout << "arr2[0][0] after self-assignment (should be 0): " << arr2[0][0] << endl;
    cout << "arr2[2][2] after self-assignment (should be 8): " << arr2[2][2] << endl;

    // -----------------------------------------------------------------------
    // TEST 8: Const correctness via ConstRow
    // When operator[] is called on a const Array2D, it returns a ConstRow,
    // whose operator[] returns a const T& — preventing modification.
    // -----------------------------------------------------------------------
    printHeader("Const correctness (ConstRow)");

    const Array2D<int> arrConst(arr2);
    cout << "Reading const array via arrConst[1][2] (should be 5): "
         << arrConst[1][2] << endl;

    // The line below would cause a compile-time error if uncommented,
    // because ConstRow::operator[] returns a const reference:
    // arrConst[1][2] = 99;

    // -----------------------------------------------------------------------
    // TEST 9: Different element type (double)
    // Templates should work for any type, not just int.
    // -----------------------------------------------------------------------
    printHeader("Different element type (double)");

    Array2D<double> arrDouble(2, 2);
    arrDouble[0][0] = 1.1;
    arrDouble[0][1] = 2.2;
    arrDouble[1][0] = 3.3;
    arrDouble[1][1] = 4.4;

    cout << "Double array contents:" << endl;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j)
            cout << arrDouble[i][j] << " ";
        cout << endl;
    }

    // -----------------------------------------------------------------------
    // TEST 10: Default constructor (empty array)
    // Array2D(0, 0) should construct without crashing.
    // -----------------------------------------------------------------------
    printHeader("Default construction (empty array)");

    Array2D<int> arrEmpty;
    cout << "Empty array constructed successfully." << endl;

    try {
        int val = arrEmpty[0][0];
        (void)val;
        cout << "ERROR: no exception thrown!" << endl;
    } catch (const std::out_of_range& e) {
        cout << "Caught expected exception on empty array: " << e.what() << endl;
    }

    cout << "\nAll tests completed." << endl;
    return 0;
}