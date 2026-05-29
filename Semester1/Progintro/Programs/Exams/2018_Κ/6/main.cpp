#include <cstdio>
#include <iostream>
using namespace std;

int main() {
    FILE* input = fopen("files.txt", "rt");
    if (input == nullptr) {
        cout << "Error opening file";
        return 1;
    }

    bool inWord = false;
    char word[42];
    int pos;
    int c;

    while (true) {
        c = fgetc(input);

        if (c >= 'a' && c <= 'z') {
            if (!inWord) {
                inWord = true;
                pos = 0;
            }
            word[pos] = (char)c;
            ++pos;
        } else {
            if (inWord) {
                for (int i = pos-1; i >= 0; i--) {
                    cout << word[i];
                } 
            }

            if (c == EOF) 
                break;
            else
                cout << (char)c;
        }
    }

    fclose(input);
    return 0;
}