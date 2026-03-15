#include <iostream>
#include "Complex.hpp"
using namespace std;

template <typename T>
void bubble_sort(int n, T a[]) {
    for (int i=0; i<n-1; i++) {
        for (int j=n-2; j>=i; j--) {
            if (a[j] > a[j+1]) {
                T t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
            }
        }
    }
}

int main() {
    int a[] = {42, 17, 4, 3, 8, 2};

    // sizeof(a) gives the total size of the array in bytes
    // sizeof(a[0]) gives the size of one element in bytes
    // Dividing them gives the number of elements in the array
    int na = sizeof(a) / sizeof(a[0]);

    bubble_sort(na, a); // T = int

    cout << "Assorted int array: "; 
    for (int i=0; i<na; i++) {
        cout << a[i] << ' ';
    }
    cout << endl;

    Complex c[] = {
        Complex(3,4),
        Complex(1,2),
        Complex(7,8),
        Complex(5,6)
    };
    
    int nc = sizeof(c) / sizeof(c[0]);

    bubble_sort(nc, c); // T = complex;

    cout << "Assorted complex array:" << endl;
    for (int i=0; i<nc; i++) cout << c[i] << endl;
}
