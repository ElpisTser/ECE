#include <iostream>
#include <string>
#include <cstdlib>
#include "secret.hpp"
using namespace std;

secret::secret(const string &pwd, int d):
    password(pwd), data(d) {}

int secret::get(const string &pwd) {
    if (pwd == password) return data;
    cout << "Wrong Password!" << endl;
    exit(0);
}