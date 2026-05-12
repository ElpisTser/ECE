#include <cstdio>
using namespace std;

bool isLetter(char c) {
    return (c >= 'a' && c <= 'z');
}

int main() {
    FILE* file = fopen("file.txt", "rt");
    if (file == nullptr) {
        printf("Error opening file\n");
        return 1;
    }

    int ch;
    int lineCount = 0;
    char firstWord[100];
    int firstWordLength;
    char currentWord[100];
    int letterIndex;
    bool inWord = false;
    bool firstWordFilled = false;
    bool validLine = false; // tracks if the line has at least two words and is valid to compare 

    while ((ch = fgetc(file)) != EOF) {
        if (ch == '\n') {
            if (validLine) {
                if (firstWordLength == letterIndex) {
                    bool condition = true;
                    for (int i = 0; i < letterIndex; i++) {
                        if (firstWord[i] != currentWord[i]) {
                            condition = false;
                            break;
                        }
                    }
                    if (condition) lineCount++;
                }
                validLine = false;
            }
            firstWordFilled = false;
        }

        if (isLetter(ch)) {
            if (!inWord) {
                inWord = true;
                letterIndex = 0;
            }
            currentWord[letterIndex] = ch;
            letterIndex++;
        } else {
            if (inWord) {
                currentWord[letterIndex] = '\0';
                if (!firstWordFilled) {
                    for (int i = 0; i <= letterIndex; i++) 
                        firstWord[i] = currentWord[i];
                    firstWordFilled = true;
                    firstWordLength = letterIndex;
                } else {
                    validLine = true;
                }
                inWord = false;
            }
        }
    }
    if (inWord) {
        if (firstWordFilled) {
            currentWord[letterIndex] = '\0';
            if (firstWordLength == letterIndex) {
                bool condition = true;
                for (int i = 0; i < letterIndex; i++) {
                    if (firstWord[i] != currentWord[i]) {
                        condition = false;
                        break;
                    }
                }
                if (condition) lineCount++;
            }
        }
    } else if (validLine) {
        if (firstWordLength == letterIndex) {
            bool condition = true;
            for (int i = 0; i < letterIndex; i++) {
                if (firstWord[i] != currentWord[i]) {
                    condition = false;
                    break;
                }
            }
            if (condition) lineCount++;
        }
    }

    printf("%d", lineCount);
}