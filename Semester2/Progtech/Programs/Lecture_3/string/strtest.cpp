#include <iostream>
#include <string>

using namespace std;

int main() {
    string name;
    cout << "What's your name? ";
    cin >> name;
    string msg = "Hello " + name + ", hope all is good.";
    cout << msg << endl;
    cout << "The message I printed had " << msg.length() << " characters" << endl;
}