#include <iostream>
#include <string>
using namespace std;

class Person {
public:
    Person(const string& name): myName(name) {}

    // pure virtual function -> makes Person an abstract class
    virtual void freeTime() const = 0;
protected:
    string myName;
};

// Student inherits Person virtually.
// This means that if another class also inherits Person,
// they will share ONE common Person base instead of creating two.
class Student: virtual public Person {
public:
    Student(const string& name): Person(name) {}

    void freeTime() const override {
        cout << myName << " studies" << endl;
    }
};

// Employee also inherits Person virtually.
// Virtual inheritance prevents the "diamond problem"
// where a derived class could end up with two Person objects.
class Employee: virtual public Person {
public: 
    Employee(const string& name): Person(name) {}

    void freeTime() const override {
        cout << myName << " relaxes after work" << endl;
    }
};

// WorkingStudent inherits from BOTH Student and Employee.
// Because Student and Employee virtually inherit Person,
// WorkingStudent will contain only ONE shared Person object.
class WorkingStudent: public Student, public Employee {
public:
    WorkingStudent(const string& name):
        Person(name), Student(name), Employee(name) {}
    
    void freeTime() const override {
        cout << myName << " barely has freetime" << endl;
    }
};

int main() {
    Student s("Babis");
    Employee e("Bobos");
    WorkingStudent ws("Bibus");

    Person *p;

    p = &s;
    p->freeTime();

    p = &e;
    p->freeTime();

    p = &ws;
    p->freeTime();
}