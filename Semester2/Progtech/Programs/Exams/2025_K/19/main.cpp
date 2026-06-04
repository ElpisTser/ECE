#include <iostream>
#include <map>
#include <fstream>
#include <string>
using namespace std;
    

struct Connections {
    int total_connections = 0;
    map<string, int> connections_per_servie;
};



int main() {
    map<string, string> ip_to_country;
    map<string, Connections> connections_per_country;
    string ip, country, service;
    
    ifstream geoip("geoip.txt");
    if (!geoip) {
        cout << "Error opening geoip.txt";
        return 1;
    }

    
    while (geoip >> ip >> country) {
        ip_to_country[ip] = country;
    }

    geoip.close();

    while (cin >> ip >> service) {
        if (ip_to_country.find(ip) != ip_to_country.end()) {
            country = ip_to_country[ip];
            connections_per_country[country].total_connections++;
            connections_per_country[country].connections_per_servie[service]++;
        } else {
            connections_per_country["Unknown"].total_connections++;
            connections_per_country["Unknown"].connections_per_servie[service]++;
        }
    }

    for (const auto& x : connections_per_country) {
        cout << x.first << " " << x.second.total_connections;
        for (const auto& y : x.second.connections_per_servie) {
            cout << " " << y.first << " " << y.second;
        }
        cout << endl;
    }
}

