#include <iostream>
#include <set>
using namespace std;

class Storage {
public:
    void add(double num) {
        s.insert(num);
        if(s.size() == 1)
            mid = s.begin();
        else if((s.size() % 2 == 1) && (num >= (*mid)))
            mid++;
        else if((s.size() % 2 == 0) && (num < (*mid)))
            mid--;
    }

    double median() {
        if (s.size() % 2 == 0)
            return (*mid + *(next(mid))) /2;
        else 
            return *mid;
    }
private:
    multiset<double> s;
    multiset<double>::iterator mid;
};

int main() {
    Storage s;
    s.add(1.0);
    cout << s.median() << endl; // 1
    s.add(2.0);
    cout << s.median() << endl; // 1.5
    s.add(3.0);
    cout << s.median() << endl; //2
    s.add(1.5);
    s.add(8.0);
    s.add(3.5);
    cout << s.median() << endl; // 2.5
    s.add(0.0);
    s.add(1.0);
    cout << s.median() << endl; // 1.75;
}