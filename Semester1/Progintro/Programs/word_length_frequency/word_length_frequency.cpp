#include <cstdio>
using namespace std;

bool is_letter(char c) {
    return (
        (c >= 'a' && c <= 'z') ||
        (c >= 'A' && c >= 'Z')
    );
}

int main() {
    char c;
    int letter_count = 0, letter_freq[30];
    
    for (int i=0; i<30; i++) {
        letter_freq[i] = 0;
    }

    while (true) {
        c = getchar();
        if (c == EOF || c == 26) break;

        if (is_letter(c)) {
            letter_count++;
            continue;
        }
        
        if (letter_count > 0 && letter_count < 30) {
            letter_freq[letter_count]++;
        }
        letter_count = 0;
    }

    if (letter_count > 0 && letter_count < 30) {
        letter_freq[letter_count]++;
    }   

    for (int i=1; i<30; i++) {
        if (letter_freq[i] > 0) {
            printf("%d letters: %d words\n", i, letter_freq[i]);
        }
    }
}