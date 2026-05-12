#include <cstdio>
using namespace std;

bool isLetter(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

bool wordsEqual(const char* a, int lenA, const char* b, int lenB) {
    if (lenA != lenB) return false;
    for (int i = 0; i < lenA; i++) {
        if (a[i] != b[i]) return false;
    }
    return true;
}

int main() {
    FILE* file = fopen("file.txt", "rt");
    if (file == nullptr) {
        printf("Error opening file\n");
        return 1;
    }

    char firstWord[100];
    int firstLen = 0;
    char lastWord[100];
    int lastLen = 0;
    char currentWord[100];
    int currentLen = 0;

    int wordsOnLine = 0;
    int matchCount = 0;
    bool inWord = false;

    int ch;
    while (true) {
        ch = fgetc(file);

        if (isLetter(ch)) {
            if (!inWord) {
                inWord = true;
                currentLen = 0;
            }
            if (currentLen < 99) {
                currentWord[currentLen++] = ch;
            }
        } else {
            // Non-letter: if we were in a word, the word just ended
            if (inWord) {
                wordsOnLine++;
                if (wordsOnLine == 1) {
                    firstLen = currentLen;
                    for (int i = 0; i < currentLen; i++) firstWord[i] = currentWord[i];
                }
                lastLen = currentLen;
                for (int i = 0; i < currentLen; i++) lastWord[i] = currentWord[i];
                inWord = false;
            }

            // End of line OR end of file: check the line
            if (ch == '\n' || ch == EOF) {
                if (wordsOnLine >= 2 && wordsEqual(firstWord, firstLen, lastWord, lastLen)) {
                    matchCount++;
                }
                wordsOnLine = 0;
            }

            if (ch == EOF) break;
        }
    }

    fclose(file);
    printf("%d\n", matchCount);
    return 0;
}