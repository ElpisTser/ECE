#include <iostream>
#include <string>
using namespace std;

void generate_string(int max_digits, int digit_pos, string digits) {
    if (digit_pos == max_digits) {
        cout << digits << endl;
        return;
    }
    
    generate_string(max_digits, digit_pos + 1, digits + "0");
    generate_string(max_digits, digit_pos + 1, digits + "1");
}

int main () {
    int n;
    cout << "Give number of digits: ";
    cin >> n;
    generate_string(n, 0, "");
}