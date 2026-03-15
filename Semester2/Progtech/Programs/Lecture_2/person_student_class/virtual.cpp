#include <iostream>
#include <string>
using namespace std;

class Person {
public:
    Person(const string &name): myName(name) {}
    virtual void freeTime() const {
        cout << myName << " sleeps" << endl;
    }
protected:
    string myName;
};

class Student: public Person {
public:
    Student(const string &name): Person(name) {}
    void freeTime() const override {
        cout << myName << " reads a book" << endl;
    }
};

int main() {
    Student s("Babis");
    Person p ("Bobos");

    s.freeTime(); // reads
    p.freeTime(); // sleeps

    Person *pp;
    pp = &p;
    pp -> freeTime(); // sleeps

    pp = &s;
    pp -> freeTime(); //reads
}

// -------------------- NOTES ABOUT VIRTUAL FUNCTIONS --------------------
//
// A virtual function enables *runtime polymorphism*.
//
// If a function is NOT virtual:
// - The function that gets called depends on the POINTER TYPE.
// - The decision is made at compile time (static binding).
//
// Example (from main.cpp):
// Person* pp = &s;
// pp->freeTime();  // calls Person::freeTime()
//
// If a function IS virtual:
// - The function that gets called depends on the ACTUAL OBJECT TYPE.
// - The decision is made at runtime (dynamic binding).
//
// Example (in this file):
// Person* pp = &s;
// pp->freeTime();  // calls Student::freeTime()
//
// Summary:
// pointer type  -> Person*
// object type   -> Student
//
// Without virtual → Person version runs
// With virtual   → Student version runs
//
// The keyword "override" is optional but recommended because
// it lets the compiler check that we are correctly overriding
// a virtual function from the base class.