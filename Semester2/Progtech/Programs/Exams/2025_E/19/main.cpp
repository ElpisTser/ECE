#include <iostream>
#include <string>
#include <map>
#include <fstream>
using namespace std;

string findPerson(const map<string, string>& m, string num) {
    auto it = m.find(num);
    if (it != m.end())
        return it->second;
    return "unknown";
}

struct Calls {
    int totalCalls;
    map <string, int> distCalls;
};

int main() {
    map<string, string> numToPerson;
    map<string, Calls> callsPerPerson;
    string num, person, num2, person2;

    ifstream phonebook("phonebook.txt");
    if (!phonebook) {
        cout << "Error opening file";
        return 1;
    }

    while (phonebook >> num >> person) 
        numToPerson[num] = person;
    phonebook.close();

    while (cin >> num >> num2) {
        person = findPerson(numToPerson, num);
        person2 = findPerson(numToPerson, num2);

        callsPerPerson[person].totalCalls++;
        callsPerPerson[person].distCalls[person2]++;
    }

    for (const auto& caller : callsPerPerson) {
        cout << caller.first << " " << caller.second.totalCalls;
        for (const auto& recipient : caller.second.distCalls) 
            cout << " " << recipient.first << " " << recipient.second;
        cout << endl;
    }
}