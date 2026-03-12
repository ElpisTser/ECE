#include <iostream>
#include <string>
using namespace std;

class Person {
public:
    Person(const string &name): myName(name) {}
    string getName() const {
        return myName;
    }
private:    
    string myName;
};

class Origin {
public:
    Origin(const string &country): myCountry(country) {}
    string getOrigin() const {
        return myCountry;
    }
private:
    string myCountry;
};

class Citizen: public Person, public Origin {
public:
    Citizen(const string &name, const string &country) :
        Person(name), Origin(country) {}
};

int main() {
    Citizen c("David Lynch", "USA");

    cout << c.getName() << " comes from " << c.getOrigin() << endl;
    // c can access getName() and getOrigin(), but cannot access myName and myCountry directly,
    // because they are private and not protected fields  in the Person and Origin classes 

    Person &p = c;
    cout << "Who is " << p.getName() << "?" << endl;
    // p can access getName(), but not getOrigin

    Origin &o = c;
    cout << "Who comes from " << o.getOrigin() << "?" << endl;
    // o can acces getOrigin(), but not getName()
}