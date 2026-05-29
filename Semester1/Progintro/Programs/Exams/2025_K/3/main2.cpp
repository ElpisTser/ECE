#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    FILE* input = fopen("file.txt", "rt");
    if (input == nullptr) {
        cout << "Error opening file";
        return 1;
    }

    bool inWord = false;
    int fWord[50];
    int fPos = 0;
    int lWord[50];
    int lPos = 0;
    int wordsInLine = 0;
    int validLines = 0;
    int ch;

    while (true) {
        ch = fgetc(input);

        if (ch <= 'z' && ch >= 'a') {
            if (!inWord) {
                inWord = true;
                lPos = 0;
            }

            if (wordsInLine == 0) {
                fWord[fPos] = ch;
                fPos++;
            } else {
                lWord[lPos] = ch;
                lPos++;
            }
        } else {
            if (inWord) {
                inWord = false;
                wordsInLine++;
            }

            if (ch == EOF || ch == '\n') {
                if (wordsInLine >= 2 && fPos == lPos) {
                    bool condition = true;
                    for (int i = 0; i < fPos; i++)
                        if (fWord[i] != lWord[i]) {
                            condition = false;
                            break;
                        }
                    if (condition) validLines++;
                }

                fPos = lPos = wordsInLine = 0;

                if (ch == EOF) break;
            }
        }
    }
    cout << validLines;
    fclose(input);
    return 0;
}