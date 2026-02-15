#include <iostream>
#include <limits>
#include <cstdio>
#include <cstring>
using namespace std; 

int main() {
    int input_num;
    scanf("%d", &input_num);
    
    int input_count = 1; 
    int char_count = 0;
    char input_char[21];
    int pal_count = 0;

    getchar();

    while (true) {
        if (input_count > input_num) break;        

        input_char[char_count] = getchar();

        if (input_char[0] == '\n') {
            printf("empty\n");
            input_count++;
            continue;
        }

        if (char_count == 20 && input_char[20]!= '\n') {
            while (getchar() != '\n');
            printf("error\n");
            char_count = 0;
            input_count++;
            continue;
        }    

        if (input_char[char_count] == '\n') {
            bool is_palindrome=true;
            for (int i=0; i<=(char_count-1)/2; i++) {
                if (input_char[i] != input_char[char_count - 1 - i]) {
                    is_palindrome = false;
                    break;
                }
            }
            if (is_palindrome) {
                printf("yes\n");
                pal_count++;
            }
            else printf("no\n");
            char_count = 0;
            input_count++;
            continue;
        }

        char_count++;
    }
    printf("%.3f", 100 * ((double)pal_count / input_num));
}