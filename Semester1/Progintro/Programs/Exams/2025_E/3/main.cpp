#include <cstdio>
 
int main() {
    FILE *file = fopen("file.txt", "r");
    
    // Check if file opened successfully
    if (file == NULL) {
        printf("Error: Could not open file.txt\n");
        return 1;
    }
    
    int word_count = 0;  // Count of words with max 3 different letters
    int letter_freq[26]; // Frequency array for letters a-z
    int distinct_count;  // Number of distinct letters in current word
    int ch;              // Current character
    int in_word = 0;     // Flag: are we currently inside a word?
    
    while ((ch = fgetc(file)) != EOF) {
        // Check if character is a lowercase letter
        if (ch >= 'a' && ch <= 'z') {
            // If we're starting a new word, reset the frequency array
            if (!in_word) {
                for (int i = 0; i < 26; i++) {
                    letter_freq[i] = 0;
                }
                distinct_count = 0;
                in_word = 1;
            }
            
            // Update frequency for this letter
            int letter_index = ch - 'a';
            if (letter_freq[letter_index] == 0) {
                // First time seeing this letter in the word
                distinct_count++;
            }
            letter_freq[letter_index]++;
        }
        else {
            // Character is space or newline (end of word)
            if (in_word) {
                // Check if word has at most 3 different letters
                if (distinct_count <= 3) {
                    word_count++;
                }
                in_word = 0;
            }
        }
    }
    
    // Handle the last word if file doesn't end with space/newline
    if (in_word) {
        if (distinct_count <= 3) {
            word_count++;
        }
    }
    
    fclose(file);
    
    printf("Number of words with at most 3 different letters: %d\n", word_count);
    
    return 0;
}