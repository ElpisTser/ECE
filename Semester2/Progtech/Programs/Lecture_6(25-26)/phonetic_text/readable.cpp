#include "readable.hpp"
#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

map<char, string> readable::phoneticMap;

map<string, char> readable::invPhoneticMap;

const vector<string> readable::phoneticWords {
    "alpha", "bravo", "charlie", "delta", "echo", "foxtrot",
    "golf", "hotel", "india", "juliett", "kilo", "lima",
    "mike", "november", "oscar", "papa", "quebec", "romeo",
    "sierra", "tango", "uniform", "victor", "whiskey", "x-ray",
    "yankee", "zulu", " ", "@", "."
};

void readable::initializeMappings() {
    if (!phoneticMap.empty()) return;
    for (const string& word : phoneticWords) {
        phoneticMap[word.front()] = word;
        invPhoneticMap[word] = word.front();
    }
}

readable::readable() :  normalText(""), phoneticText("") { initializeMappings(); }

readable::readable(const string& someText) : normalText(someText) {
    initializeMappings();
    phoneticText = text2Phonetic(someText);
}

string readable::char2Phonetic (const char& c) {
    if (phoneticMap.find(c) == phoneticMap.end()) return "?*?*?";
    return phoneticMap[c];
}

string readable::text2Phonetic (const string& txt) {
    if (txt.empty()) return "";
    
    string result;
    for (const char& c : txt) {
        result += char2Phonetic(c) + " ";
    }
    return result.substr(0, result.length() - 1);
}

char readable::phonetic2Char(const string& s) {
    if (invPhoneticMap.find(s) == invPhoneticMap.end()) return '?';
    return (invPhoneticMap[s]);
}

string readable::phonetic2Text(const string& t) {
    istringstream stream(t);
    string result, word;

    while (stream >> word) {
        result += phonetic2Char(word);
    }

    return result;
}

string readable::phonetic() const { return phoneticText; }

string readable::text() const { return normalText; }

void readable::setPhonetic(const string& pText) {
    phoneticText = pText;
    normalText = phonetic2Text(pText);
}

void readable::setText(const string& nText) {
    normalText = nText;
    phoneticText = text2Phonetic(nText);
}
