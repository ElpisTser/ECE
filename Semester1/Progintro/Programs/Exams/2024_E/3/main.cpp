#include <cstdio>
using namespace std;

bool isLetter(char ch) {
    return (ch >= 'a' && ch <= 'z');
}

int main() {
    FILE* file = fopen("file.txt", "rt");
    if (file == nullptr) {
        printf("Error opening file\n");
        return 1;
    }

    int ch;
    char word[100];
    int wordLen;
    bool inWord = false;
    bool convertToCaps;

    while (true) {
        ch = fgetc(file);

        if (isLetter(ch)) {
            if (!inWord) {
                wordLen = 0;
                convertToCaps = false;
                inWord = true;
            }

            if(wordLen >= 100) {
                printf("Word too large\n");
                return 1;
            }

            if (ch == 'e')
                convertToCaps = true;

            word[wordLen] = ch;
            wordLen++;
        } else {
            if(inWord) {
                for (int i = 0; i < wordLen; i++) {
                    if (convertToCaps)
                        word[i] += 'A' - 'a';
                    printf("%c", word[i]);
                }
                inWord = false;
            }

            if (ch != EOF) 
                printf("%c", ch);
            else
                break;
        }
    }

    fclose(file);
    return 0;
}