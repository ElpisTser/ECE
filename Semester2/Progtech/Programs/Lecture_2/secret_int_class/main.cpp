#include <iostream>
#include <string>
#include "secret.hpp"
using namespace std;

int main() {
    secret a("bababubu", 1999);

    cout << "Give Password: ";
    string pwd;
    cin >> pwd;

    cout << a.get(pwd) << endl;

    cout << "Program didn't terminate";
}