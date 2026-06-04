#include <iostream>
#include <math.h>
using namespace std;

class disk {
protected:
    double r, a;
    void upd() {a = 3 * r * r;}
public:
    disk(): r(0), a(0) {}
    disk (double rp): r(rp) { upd(); }
    void set(double newr) {r = newr; upd();}
    double R(){return r;}
    double A(){return a;}
};

class ring: public disk {
protected:
    double r2;
    void upd() {a = fabs(3*(r*r-r2*r2));}
public:
    ring(): r2(0) {} 
    ring(double pr1, double pr2): disk(pr1), r2(pr2) {upd();}
    void set(double pr1, double pr2) {
        r = pr1;
        r2 = pr2;
        upd();
    }
    double R2() {return r2;}
    double A() {return a;}
};

int main() {
    ring* myr1 = new ring(3,2);
    disk* myd1 = myr1;
    cout << myd1->R() << " " << myd1->A() << " ";
    myr1->set(4,1);
    cout << myr1->R2() << " " << myr1->A();
}