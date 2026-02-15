#include <cstdio>
#include <cstring>
using namespace std;

int main() {
    char name[30];
    printf("What's your name?\n");
    scanf("%s", name);

    printf("Hi %s\n", name);

    printf("Your name has %d letters\n", strlen(name)); //stlrlen() -> count string length

    if (strcmp(name, "Elpis") == 0) { //strcmp -> return 0 if both strings are equal
        printf("I knew you were Elpis\n");
    } else {
        printf("You are not Elpis\n");
    }
}
