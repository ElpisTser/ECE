#include "readable.hpp"
#include <iostream>

using namespace std;

// Helper that prints PASS or FAIL based on a condition
void check(const string& testName, bool condition) {
    cout << (condition ? "PASS" : "FAIL") << " : " << testName << endl;
}

int main() {
    // --- Default constructor ---
    readable a;
    check("Default constructor: text is empty",    a.text().empty());
    check("Default constructor: phonetic is empty", a.phonetic().empty());

    // --- Constructor with string argument ---
    readable b("example");
    check("Constructor: text stored correctly",
          b.text() == "example");
    check("Constructor: phonetic conversion correct",
          b.phonetic() == "echo x-ray alpha mike papa lima echo");

    // --- Edge cases ---
    readable empty("");
    check("Empty string: text is empty",    empty.text().empty());
    check("Empty string: phonetic is empty", empty.phonetic().empty());

    readable single("a");
    check("Single char: phonetic is correct", single.phonetic() == "alpha");

    // --- Round trip (single word only) ---
    string original = "example";
    readable r;
    r.setText(original);
    r.setPhonetic(r.phonetic());
    check("Round trip: text survives full conversion", r.text() == original);  
}