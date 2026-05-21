#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    vector<string> items, suppliers;
    vector<double> prices;

    ifstream input("file.txt");

    string supplier, item;
    double price;

    while (input >> supplier >> item >> price) {
        items.push_back(item);
        suppliers.push_back(supplier);
        prices.push_back(price);
    }

    for (int i = 0; i < suppliers.size(); i++) {
        cout << suppliers.at(i) << " " << items.at(i) << " " << prices.at(i) << endl;
    }
}