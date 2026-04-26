#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <sstream>

using namespace std;

string char2Phonetic (const char& c) {
    static const  vector<string> phoneticWords {
        "alpha", "bravo", "charlie", "delta", "echo", "foxtrot",
        "golf", "hotel", "india", "juliett", "kilo", "lima",
        "mike", "november", "oscar", "papa", "quebec", "romeo",
        "sierra", "tango", "uniform", "victor", "whiskey", "x-ray",
        "yankee", "zulu", " ", "@", "."
    };

    static map<char, string> phonetic;

    if (phonetic.empty()) {
        for (const string& word : phoneticWords) {
            phonetic[word.front()] = word;
        }
    }

    if (phonetic.find(c) == phonetic.end()) return "?*?*?";
    else return phonetic[c];
}

string string2Phonetic(const string& s) {
    static map<string, string> cachedWords;
    if (cachedWords.find(s) != cachedWords.end()) {
        cout << "Found cached word" << endl;
        return cachedWords[s];
    }

    string result = "";

    if (s.empty()) return "";

    for (char c : s) {
        result += char2Phonetic(c) + " ";
    }

    string trimmed = result.substr(0, result.length() - 1);
    cachedWords[s] = trimmed;
    return trimmed;
}

char phonetic2Char (const string& s) {
    static const vector<string> phoneticWords {
        "alpha", "bravo", "charlie", "delta", "echo", "foxtrot",
        "golf", "hotel", "india", "juliett", "kilo", "lima",
        "mike", "november", "oscar", "papa", "quebec", "romeo",
        "sierra", "tango", "uniform", "victor", "whiskey", "x-ray",
        "yankee", "zulu", " ", "@", "."
    };

    static map<string, char> invPhonetic;

    if (invPhonetic.empty()) {
        for (const string& word : phoneticWords) {
            invPhonetic[word] = word.front();
        }
    }

    if (invPhonetic.find(s) == invPhonetic.end()) return '?';
    return invPhonetic[s];
}

string phonetic2Word(const string& src) {
    istringstream stream(src);
    string word;
    string result ="";

    while (stream >> word) {
        result += phonetic2Char(word);
    }

    return result;
}

int main() {
    // Test char2Phonetic
    cout << char2Phonetic('a') << endl; // expect: alpha
    cout << char2Phonetic('b') << endl; // expect: bravo
    cout << char2Phonetic('z') << endl; // expect: zulu
    cout << char2Phonetic('!') << endl; // epxct: ?*?*?

    // Test string2Phonetic
    cout << string2Phonetic("babis") << endl;
    cout << string2Phonetic("") << endl;
    cout << string2Phonetic("a") << string2Phonetic("b") << endl;
    cout << string2Phonetic("babis") << endl;

    // Test phonetic2Char
    cout << phonetic2Char("alpha") << endl; 
    cout << phonetic2Char("babis") << endl;
    cout << phonetic2Char("sierra") << endl;

    // Test phoneti2Word
    cout << phonetic2Word("alpha sierra alpha") << endl;

    // Test Round trip
    string original = "babis";
    string phonetic  = string2Phonetic(original);
    string recovered = phonetic2Word(phonetic);

    cout << original  << endl;
    cout << phonetic  << endl;
    cout << recovered << endl;

    if (original == recovered)
        cout << "Round trip: OK" << endl;
    else
        cout << "Round trip: FAILED" << endl;
    }