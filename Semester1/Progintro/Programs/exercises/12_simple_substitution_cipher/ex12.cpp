#include <iostream>
#include <cstdio>
using namespace std;

bool isLetter(char c) {
    if ((c >= 'a') && (c <= 'z') || (c >= 'A' && c <= 'Z')) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int charCode = 'a';
    const int upperToLower = 'a' - 'A';
    char swapLetter[200];

    bool letterIsUsed[200] = { false };
    
    // Read cipher
    for (int i=0; i<26; i++) {
        char c;
        cin >> c;

        if (!((c >= 'a') && (c <= 'z'))) {
            cout << "error, used non-letter character";
            return 0;
        }

        if (letterIsUsed[c]) {
            cout << "error, letter used more than once";
            return 0;
        }

        letterIsUsed[c] = true;
        
        swapLetter[charCode] = c;
        swapLetter[charCode - upperToLower] = (char)(c - upperToLower);
       
        charCode++;
    }
    
    // Fill encrypted text
    char c;
    char encryptedText[9999];
    int index = 0;
    while (true) {
        c = getchar();
        if (c == 26 || c == EOF) //23 = Ctrl - z
            break;               //EOF = Ctrl -z as the first character in a new line

        if (isLetter(c)) {
            encryptedText[index] = swapLetter[c];
        } else {
            encryptedText[index] = c;
        }
        index++;
    }
    encryptedText[index] = '\0';

    cout << encryptedText;
}