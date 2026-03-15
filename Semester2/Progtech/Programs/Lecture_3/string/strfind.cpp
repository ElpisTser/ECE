#include <iostream>
#include <string>

using namespace std; 

int main (int argc, char *argv[]) {
    string word(argv[1]);
    cout << "You're looking for the word: " << word << endl;

    string line;
    int lineno = 1;
    while (getline(cin, line)) {
        if (line.find(word) != string::npos) // line.find returns the index of the first occurrence of 'word' in 'line'; returns string::npos if not found
            cout << lineno << ": " << line << endl;
        lineno++;
    }
}

// To run this program on different terminals for a specific file:
//
// 1. **Windows Command Prompt (cmd.exe)**:
//    strfind.exe <word> <filename>
//    Example:
//        strfind.exe int < strfind.cpp
//    Notes:
//      - Do NOT use './' in front of the executable.
//      - The '<' operator works for input redirection.
//
// 2. **Git Bash (or other Unix-like shells on Windows)**:
//    ./strfind.exe <word> <filename>
//    Example:
//        ./strfind.exe int < strfind.cpp
//    Notes:
//      - './' is required to indicate the current directory.
//      - '<' works for input redirection as in Linux/macOS.
//
// 3. **PowerShell**:
//    Get-Content <filename> | ./strfind.exe <word>
//    Example:
//        Get-Content strfind.cpp | ./strfind.exe int
//    Notes:
//      - PowerShell does NOT support '<' for input redirection.
//      - Use Get-Content and a pipe '|' to feed the file into the program.