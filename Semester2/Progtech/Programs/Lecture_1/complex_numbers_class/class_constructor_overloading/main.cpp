#include <iostream>

class complex {
public:
    // Parameterized constructor: initializes both real and imaginary parts
    // Uses member initializer list (preferred over assignment inside body)
    complex(double r, double i):
        re(r), im(i) {}
    
    // Default constructor: initializes to 0 + 0i
    complex() :
        re(0), im(0) {}

    // Copy constructor: creates a new object as a copy of another
    complex(const complex &c) :
        re(c.re), im(c.im) {}

    // Converting constructor: allows implicit conversion from double to complex
    // Example: complex c = 5.0;  ->  5.0 + 0i
    complex(double r) :
        re(r), im(0) {}

    // Copy assignment operator: assigns one complex to another
    const complex& operator=(const complex &c){
        re = c.re;
        im = c.im;
        return *this;  // Return reference to current object to allow chaining (e.g., a = b = c)
    }

    friend std::ostream& operator<<(std::ostream& out, const complex& c) {
        out << c.re << "+" << c.im << "i";
        return out;
    }
private:
    double re, im;
};

int main() {
    // Calls parameterized constructor
    complex c1(1,2);
    std::cout << c1 << std::endl;

    // Calls Default Constructor
    complex c2;
    std::cout << c2 << std::endl;

    // Calls Copy Constructor
    complex c3(c1);
    std::cout << c3 << std::endl;

    // Calls Converting Cosntructor
    complex c4(5);
    std::cout << c4 << std::endl;

    // Demonstrates chained assignment using copy assignment operator
    complex c5 = c3 = c2;
    std::cout << c5 << std::endl << c3 << std::endl << c2;
}