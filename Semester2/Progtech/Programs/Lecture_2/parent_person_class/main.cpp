#include <iostream>
#include <string>
#include <list>
using namespace std;

class Person {
public:
    Person(const string &name):
        myName(name) {}
    string getName() const {
        return myName;
    }
protected:  // allows Parent class to access myName, without having to call the public getName() method
    string myName;
};

class Parent: public Person {
public:
    Parent(const string& name):
        Person(name), children() {}
    
    void addChild(const Person &p) {
        children.push_back(p);
    }
    
    int countChildren() const {
        return children.size();
    }

    void reportChildren() const {
        cout << myName << " has " << countChildren() << " children " << endl;
    }
private:
    list<Person> children;
};

int main() {
    Person d1("Monica"), d2("Ross");
    Parent m("Judy");

    m.addChild(d1);
    m.addChild(d2);

    cout << d1.getName() << " is the child of " << m.getName() << " who has " << m.countChildren() << " children." << endl;

    m.reportChildren();

    Person *p = &m;

    cout << p->getName() << " is a person." << endl;

    /*
    cannot use p->countChildren
    p points to a Person
    doesn't have access to the Parent fields
    */
}