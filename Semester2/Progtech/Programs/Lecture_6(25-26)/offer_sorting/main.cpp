#include <iostream>
#include <string>
#include <map>
#include <set>
#include <fstream>

using namespace std;

struct Offer {
    Offer(const string& s, const double& p) : supplier(s), price(p) {}
    string supplier;
    double price;
};

bool operator < (const Offer& o1, const Offer& o2) {
    if (o1.price != o2.price) return o1.price < o2.price;
    return o1.supplier < o2.supplier;
}

typedef map<string, set<Offer>> bids;

int main() {
    // set<Offer> sampleSet;
    // sampleSet.insert(Offer("baba", 22));
    // sampleSet.insert(Offer("Akis", 2.34));
    // sampleSet.insert(Offer("zaza", 2.34));

    // bids receivedOffers;

    // receivedOffers["pencil"] = sampleSet;

    // set<Offer> sampleSet2;
    // sampleSet2.insert(Offer("lele", 345.21));
    // sampleSet2.insert(Offer("bibis", 6.32));

    // receivedOffers["aaaaaa"] = sampleSet2;

    // for (map<string, set<Offer>>::iterator bid = receivedOffers.begin(); bid != receivedOffers.end(); bid++) {
    //     cout << bid->first << endl;
    //     for (set<Offer>::iterator offer = bid->second.begin(); offer != bid->second.end(); offer++) {
    //         cout << offer->supplier << " " << offer->price << endl;
    //     }
    // }

    // for (const auto& bid : receivedOffers ) {
    //     cout << bid.first << ":" << endl;
    //     for (const auto& offer : bid.second)
    //         cout << "   " << offer.supplier << " " << offer.price << endl;
    // }

    ifstream input("file.txt");

    if (!input) {
        cout << "Could not open file!" << endl;
        return 1;
    }

    string sup, item;
    double prc;

    bids receivedOffers;

    while (input >> sup >> item >> prc) {       
        receivedOffers[item].insert(Offer(sup, prc));
    }

    for (const auto& item : receivedOffers) {
        cout << item.first << endl;
        for (const auto& offer : item.second)
            cout << "   " << offer.supplier << " " << offer.price << endl;
    }


    input.close();
}