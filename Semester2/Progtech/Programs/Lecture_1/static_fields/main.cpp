#include <iostream>
using namespace std;

class Person {
public:
    Person(double w);    
    ~Person();
    double getWeight();

    // Static member function:
    // Belongs to the class itself, not to a specific object.
    // Can only access static members.
    static double getTotalWeight();
private:
    double weight;  // Each object has its own copy of weight
    static double totalWeight;  // Shared by ALL Person objects
};

/*
    Static data members must be DEFINED outside the class.

    This allocates memory for totalWeight exactly once.
    Without this definition, you would get a linker error.

    It is initialized here to 0.0 before main() starts.
*/
double Person::totalWeight = 0.0;

Person::Person(double w): weight(w) {
    totalWeight += weight;
}

Person::~Person() {
    totalWeight -= weight;
}

double Person::getWeight() {
    return weight;
}

double Person::getTotalWeight() {
    return totalWeight;
}

int main() {
    Person a(100), b(50);
    // Even though called through object 'a',
    // getTotalWeight() is a static function.
    // It is shared across the entire class.
    cout << a.getTotalWeight() << endl;

    Person *c = new Person(75);
    // Recommended way to call static functions:
    // use the class name instead of an object
    cout << Person::getTotalWeight() << endl;

    delete c;
    // Now totalWeight reflects only a and b again
    cout << b.getTotalWeight() << endl; 
}