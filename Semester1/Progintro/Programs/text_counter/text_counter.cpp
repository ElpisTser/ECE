#include <cstdio>
using namespace std;

bool is_letter(char c) {
    return (
        (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
    );
}

int main() {
    char c; 
    int word_count = 0, char_count = 0, line_count = 1;
    bool in_word = false;
    while (true) {
        c = getchar();
        if (c == 26 || c == EOF) //23 = Ctrl - z
            break;               //EOF = Ctrl -z as the first character in a new line
        
        if (c == '\n') { 
            in_word = false;     //newline breaks a word
            line_count++;
            continue;            //do not count newline as character
        }

        if (is_letter(c)) {
            if (!in_word) {
                word_count++;
                in_word = true;
            }
        } else {
            in_word = false;
        }

        char_count++;
    }
    
    printf("%d characters, %d words, %d lines", char_count, word_count, line_count);

    return 0;
}