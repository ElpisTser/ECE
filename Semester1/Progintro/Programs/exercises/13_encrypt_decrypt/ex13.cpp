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
    char encryptLetter[200];
    char decryptLetter[200];

    bool letterIsUsed[200] = { false };
    
    cout << "Give the letters that you want a-z to be substituted with:" << endl;
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
        
        encryptLetter[charCode] = c;
        encryptLetter[charCode - upperToLower] = (char)(c - upperToLower);

        decryptLetter[c] = (char)charCode;
        decryptLetter[c - upperToLower] = (char)(charCode - upperToLower);
       
        charCode++;
    }
    
    cout << "Do you want to encrypt or decrypt?" << endl;
    char operation[50];
    cin >> operation;
    
    if (operation[0] == 'd' || operation[0] == 'D') {
        // Decrypt Text
        cout << "Give the text yout want to decrypt:" << endl;

        char c;
        char decryptedText[9999];
        int textIndex = 0;

        while (true) {
           if (textIndex >= 9998) {
                cout << "Text too long" << endl;
                return 0;
            }
            
            c = getchar();
            if (c == 26 || c == EOF) //23 = Ctrl - z
                break;               //EOF = Ctrl -z as the first character in a new line

            if (isLetter(c)) {
                decryptedText[textIndex] = decryptLetter[c];
            } else {
                decryptedText[textIndex] = c;
            }
            textIndex++;
        }
        decryptedText[textIndex] = '\0';

        cout << decryptedText;
    } else {
        // Encrypt Text
        cout << "Give the text you want to encrypt:" << endl;
        
        char c;
        char encryptedText[9999];
        int textIndex = 0;
        
        while (true) {
            if (textIndex >= 9998) {
                cout << "Text too long" << endl;
                return 0;
            }
            
            c = getchar();
            if (c == 26 || c == EOF) //23 = Ctrl - z
                break;               //EOF = Ctrl -z as the first character in a new line

            if (isLetter(c)) {
                encryptedText[textIndex] = encryptLetter[c];
            } else {
                encryptedText[textIndex] = c;
            }
            textIndex++;
        }
        encryptedText[textIndex] = '\0';

        cout << encryptedText;
    }
}