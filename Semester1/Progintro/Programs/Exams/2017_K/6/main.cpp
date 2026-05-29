#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    FILE* input = fopen("file.txt", "rt");
    if (input == nullptr) {
        cout << "Error opening file";
        return 1;
    }

    bool inNum = false;
    int c;
    
    while (true) {
        c = fgetc(input);

        if (c >= '0' && c <= '9') {
            inNum = true;
            cout << char(c);      
        } else {
            if (inNum) {
                cout << endl;
                inNum = false;
            }

            if (c == EOF)
                break;
        }
    }
    
    fclose(input);
    return 0 ;
}