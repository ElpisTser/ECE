#include <cstdio>

int main(int argc, char *argv[]) {         // argc -the number of command-line arguments passed to the program(including the program itself)
    FILE *input = fopen(argv[1], "rt");    // argv[] - array of pointers, pointing to the first character of each command line argument
                                           // e.g. read_text input.txt - argc = 2, argv[0] = ./read_text, argv[1] = input.txt
    if (input == nullptr) {    
        printf("Error opening input file\n");
        return 1;
    }

    FILE *output = fopen("output.txt", "at"); // "at" - t means the output is a text file
    if (output == nullptr) {                  //      - a means append, create an output file if it doesn't exist
        printf("Error opening output file\n");//        and write data at the end of the file if it exists
        fclose(input);                        //      - we could use w instead of a
        return 1;                             //        this would rewrite the file instead of affing data at the end
    }

    int c;
    while ((c = fgetc(input)) != EOF) {
        fputc(c, output);
    }

    fputc('\n', output);

    fclose(input);
    fclose(output);
    return 0;
}