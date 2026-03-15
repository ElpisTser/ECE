#include <iostream>
#include <utility>
#include <string>

using namespace std;

void f(const tuple<string, int, bool> &t) {
    if (get<2>(t)) cout << get<0>(t) << endl;
    else cout << get<1>(t) << endl;
}

int main() {
    tuple<string, int, bool> t("Hi", 1, true);

    f(t);
    f(make_tuple("No", 42, false));
}