#include <iostream>
using namespace std;

template <typename T>
class stack {
public:
    stack(int size):
        mySize(size), top(0) { myData = new T[size]; }
    
    stack (const stack &s): mySize(s.mySize), top(s.top) {
        myData = new T[mySize];
        for (int i=0; i<top; i++) {
            myData[i] = s.myData[i];
        }
    }

    ~stack() {
        delete [] myData;
    }

    const stack & operator = (const stack &s) {
        if (this == &s) return *this; // avoid deleting data in case of self-assignment
        delete [] myData;

        mySize = s.mySize;
        top = s.top;
        myData = new T[mySize];
        for (int i=0; i<top; i++) {
            myData[i] = s.myData[i];
        }

        return *this;
    }

    bool empty() {
        return (top == 0);
    }

    void push (const T &x) {
        myData[top++] = x;
    }

    T pop() {
        return myData[--top];
    }

    int size() {
        return top;
    }

    friend ostream & operator << (ostream& out, const stack &s) {
        out << '[';
        if (s.top > 0) {
            for (int i=0; i<s.top-1; i++) out << s.myData[i] << ", ";
            out << s.myData[s.top-1];
        }   
        out << ']';
        return out;
    }


private:
    int mySize;
    T *myData;
    int top; // index to the next position to be filled in myData
};

int main() {
    // let's play with integers...
    stack<int> s(10);
    cout << "s is empty: " << s << endl;
    s.push(42);
    cout << "s has one element: " << s << endl;
    s.push(17);
    s.push(34);
    cout << "s has more elements: " << s << endl;
    cout << "How many? " << s.size() << endl;
    stack<int> t(5);
    t.push(7);
    cout << "t: " << t << endl;
    t = s;
    cout << "Popping from s: " << s.pop() << endl;
    s.push(8);
    stack<int> a(s);
    t.push(99);
    a.push(77);
    cout << "s: " << s << endl;
    cout << "t: " << t << endl;
    cout << "a: " << a << endl;
    // now with doubles...
    stack<double> c(4);
    c.push(3.14);
    c.push(1.414); 
    cout << "c contains doubles " << c << endl;
    // and with characters
    stack<char> k(4);
    k.push('$');
    cout << "k contains a character " << k << endl;
}