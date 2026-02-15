#include <iostream>
#include <cmath>
using namespace std;

void gen_num(int max_digit_poition, int current_digit_position, int num, int sum, int digit_powers[]) {
    if (current_digit_position == 0) {
        if (num == sum) {
            cout << num << endl;
        }
        return;
    }

    int starting_digit = (current_digit_position == max_digit_poition) ? 1 : 0;

    for (int digit=starting_digit; digit<=9; digit++) {
        int new_num = num * 10 + digit;
        int new_sum = sum + digit_powers[digit];

        gen_num(max_digit_poition, current_digit_position - 1, new_num, new_sum, digit_powers);
    }
}

int main() {
    int n;
    cout << "Give power number(0-9): ";
    cin >> n;

    int digit_powers[10];
    for (int digit=0; digit<=9; digit++) {
        digit_powers[digit] = 1;
        for (int i = 0; i<n; i++) {
            digit_powers[digit] *= digit;
        }
    }

    if (n != 0 ) {
        cout << 0 << endl;
    }

    for (int i=1; i<=8; i++) {
        gen_num(i, i, 0, 0, digit_powers);
    }
}