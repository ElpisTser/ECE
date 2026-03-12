#include <iostream>

class Person {
public:
    Person(double w): weight(w) {}

    // This function does not modify the object,
    // so we mark it as const.
    double getWeight() const {
        return weight;
    }

    // This function modifies the object,
    // so it cannot be const.
    void setWeight(double w) {
        weight = w;
    }
private:
    double weight;
};

int main() {
    Person me(70);
    std::cout << me.getWeight() << std::endl;
    me.setWeight(71);
    std::cout <<me.getWeight() << std::endl;

    const Person constantlyFatPanda(630);
    
    // ❌ ERROR: Cannot call setWeight() on a const object
    // constantlyFatPanda.setWeight(720);

    // ✅ OK: getWeight() is const, so it can be called on a const object
    std::cout << constantlyFatPanda.getWeight() << std::endl;

    // ❌ If getWeight() were NOT marked as const in the class definition,
    // the following line would produce a compiler error:
    // std::cout << constantlyFatPanda.getWeight() << std::endl;
}