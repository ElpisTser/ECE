#include <iostream>

int main() {
    int arr[] = {7, 0, 33};
    int* p = arr + 1;
    int* q = arr;
    ++*p;
    q += 2;
    std::cout << *(q-1) << " " << arr[1] << " " << *p << " " << *q;
}