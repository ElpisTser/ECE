#include <map>
#include <stdexcept>
using namespace std;

class Restaurant {
public:
    Restaurant (int t) : total_tables(t), available_tables(t) {
        for (int i = 1; i <= t; i++)
            tables[i] = true;
    }

    int free_tables() const {   
        return available_tables;
    }

    int find_table() {
        for (auto& table : tables) {
            if (table.second == true) {
                table.second = false;
                available_tables--;
                return table.first;
            }
        }
        return 0;
    }

    void release_table(int t) {
        if (t > total_tables || t <= 0)
            throw logic_error("Invalid table number");
        if (tables[t] == true)
            throw logic_error("Table is already available");
        
        tables[t] = true;
        available_tables++;
    }
private:
    map<int, bool> tables;
    int available_tables;
    int total_tables;
};