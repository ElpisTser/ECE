#include <iostream>
#include <string>
using namespace std;

class Person {
public:
    Person(const string &name): myName(name) {}
    void freeTime() {
        cout << myName << " sleeps" << endl;
    }
protected:
    string myName;
};

class Student: public Person{
public:
    Student(const string &name): Person(name) {}
    void freeTime() {
        cout << myName << " reads a book" << endl;
    }
};

int main() {
    Student s("Babis");
    Person p("Bobos");
    
    s.freeTime(); //reads
    p.freeTime(); //sleeps

    Person *pp;
    pp = &p;
    pp -> freeTime(); //sleeps

    pp = &s;
    pp -> freeTime(); // sleeps, pp is a pointer to a person so it calls freeTime() from the Person class, not the Student Class

    // In the case that we wanted a pointer to a Person to call freeTime() from the student class when pointing to a Student
    // we would need to declare the Person freeTime() as a virtual function
    // see virtual.cpp
}