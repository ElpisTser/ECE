#include <cstdio>
using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Wrong number of argument passed: %d\n", argc);
        return 1;
    } 

    FILE *input = fopen(argv[1], "rb");
    if (input == nullptr) {
        printf("Could not open input file\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "wb");
    if (output == nullptr) {
        printf("Could not open output file\n");
        fclose(input);
        return 1;
    }

    while (!feof(input)) {
        unsigned char buffer[1000];
        unsigned int count;

        count = fread(buffer, 1, 1000, input); // read and copy 1000 bytes, 1 byte at a time, from the input file to the buffer
                                               // return the number of bytes read
        fwrite(buffer, 1, count, output);  // write until reaching count bytes, 1 byte at a time, from the buffer to the output file
    }                                      // for all the iterations except the last, count is 1000
}                                          // at the last iteration, count doesn't return the requested 1000, but the number of bytes actually read