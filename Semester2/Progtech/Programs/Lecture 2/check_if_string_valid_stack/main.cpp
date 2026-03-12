#include <iostream>
#include <exception>
using namespace std;

// Custom assertion exception
class assert_error: public exception {};

// Simple assert function that throws on false
void assert(bool b) {
    if (!b) throw assert_error();
}

// Returns the corresponding opening bracket for a closing one
char open (char c) {
    return (c == ')') ? '(' : '[';
}

// Simple stack implementation with custom exceptions
template <typename T>
class Stack {
public:
    class full_stack_push: public exception{
    public:
        full_stack_push(T e): element(e) {}
        T element;
        const char* what() const noexcept override { return "Stack full";}
    };

    class empty_stack_pop: public exception {
    public:
        const char* what() const noexcept override { return "Stack empty on pop";}
    };

    class empty_stack_get: public exception {
    public:
        const char* what() const noexcept override { return "Stack empty on getLast";}
    };

    Stack(int size): mySize(size), top(0) { data = new T[size]; }
    ~Stack() { delete [] data; }

    void push(const T &x) {
        if (top < mySize) data[top++] = x;
        else throw full_stack_push(x);
    }

    T pop() {
        if (top > 0) return data[--top];
        else throw empty_stack_pop();
    }

    T getLast() const {
        if (top > 0) return data[top-1];
        else throw empty_stack_get();
    }

    bool empty() const {
        return top == 0;
    }

private:
    int mySize;
    int top;
    T *data;
};

// Checks if parentheses and brackets in the input are balanced
bool balanced (const char *t, int size) {
    try {
        Stack<char> s(size); // Use a stack to track opening brackets
        for (const char *p = t; *p != '\0'; p++) {
            switch (*p) {
                case '(': case '[':
                    s.push(*p); break; // Push opening brackets
                case ')': case ']':
                assert(s.pop() == open(*p)); break; // Pop and check match
            }
        }
        return s.empty(); // True if all brackets matched
    } catch (const exception& e) {
        return false; // Any stack error = unbalanced
    }
}

int main() {
    const int stringLength = 100;
    char *c = new char[stringLength];
    cin.getline(c, stringLength); // Read a full line of input (including spaces) into the array `c`, up to `stringLength - 1` characters

    if (balanced (c, stringLength)) cout << "balanced" << endl;
    else cout << "not balanced" << endl;

    delete [] c;
}