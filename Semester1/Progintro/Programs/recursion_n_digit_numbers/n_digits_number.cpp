#include <iostream>
#include <cmath>
using namespace std;

void gen_num(int max_digit_poition, int current_digit_position, int num) {
    if (current_digit_position == 0) {
        cout << num << endl;
        return;
    }

    int starting_digit = (current_digit_position == max_digit_poition) ? 1 : 0;

    for (int digit=starting_digit; digit<=9; digit++) {
        int new_num = num * 10 + digit;

        gen_num(max_digit_poition, current_digit_position - 1, new_num);
    }
}

int main() {
    int n;
    cout << "Give number of digits: ";
    cin >> n;
    gen_num(n, n, 0);
}