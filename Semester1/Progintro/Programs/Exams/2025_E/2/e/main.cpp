#include <cstdio>
using namespace std;

bool isLucky (int n) {
    while ( (n > 0 && (n % 10 ==4 || n % 10 == 2))) 
        n /= 10;
    return n ==0;
}

int main () {
    int n1 = 24242442;
    int n2 = 211235;
    if (isLucky(n1)) 
        printf("Lucky\n");
    if (!isLucky(n2))
        printf("Not Lucky\n");
}