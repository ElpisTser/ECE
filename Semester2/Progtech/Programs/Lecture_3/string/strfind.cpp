#include <iostream>
#include <string>

using namespace std; 

int main (int argc, char *argv[]) {
    string word(argv[1]);
    cout << "You're looking for the word: " << word << endl;

    string line;
    int lineno = 1;
    while (getline(cin, line)) {
        if (line.find(word) != string::npos)
            cout << lineno << ": " << line << endl;
        lineno++;
    }
    
}