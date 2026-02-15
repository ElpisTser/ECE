#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main() {
   struct Person {
      string name;
      int age;
   };

   Person user1;
   user1.name = "Babis";
   user1.age = 32;

   cout << "Name: " << user1.name << endl;
   cout << "Age: " << user1.age << endl;
   cout << "Last character of name: " << user1.name.at(user1.name.length() - 1) << endl;

   cout << "Change the last character of name to g" << endl;

   user1.name.at(user1.name.length() - 1) = 'g';

   cout << "Current name: " << user1.name;
}