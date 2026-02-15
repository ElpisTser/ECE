#include <cstdio>
#include <cstring>
using namespace std; 

int main() {
    char a[10] = "abc";
    strcat(a, "def");
    printf("%s\n", a);
}