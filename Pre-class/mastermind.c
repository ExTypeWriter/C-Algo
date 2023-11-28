#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define COLORS "ABCDEF"
#define CODE_LENGTH 4
#define MAX_ATTEMPTS 8

int is_valid_guess(const char *guess) {
    if (strlen(guess) != CODE_LENGTH) {
        return 0;
    }

    for (int i = 0; i < CODE_LENGTH; i++) {
        if (strchr(COLORS, guess[i]) == NULL) {
            return 0;
        }
    }

    return 1;
}

int compare_codes(const char *code1, const char *code2) {
    int correct_positions = 0;
    int correct_colors = 0;
    
    for (int i = 0; i < CODE_LENGTH; i++) {
        if (code1[i] == code2[i]) {
            correct_positions++;
        } else if (strchr(code1, code2[i]) != NULL) {
            correct_colors++;
        }
    }
    
    return correct_positions * 10 + correct_colors;
}

void generate_all_possible_codes(char *colors, int code_length, const char *secret_code) {
    char guess[CODE_LENGTH + 1];
    
    for (int i = 0; i < strlen(colors); i++) {
        guess[0] = colors[i];
        
        for (int j = 0; j < strlen(colors); j++) {
            guess[1] = colors[j];
            
            for (int k = 0; k < strlen(colors); k++) {
                guess[2] = colors[k];
                
                for (int l = 0; l < strlen(colors); l++) {
                    guess[3] = colors[l];
                    guess[CODE_LENGTH] = '\0';

                    if (compare_codes(guess, secret_code) == CODE_LENGTH * 10) {
                        printf("Found the secret code: %s\n", guess);
                        return;
                    }
                }
            }
        }
    }
}

int main() {
    char SECRET_CODE[CODE_LENGTH + 1];
    char colors[] = COLORS;
    
    printf("Welcome to Mastermind!\n");
    printf("Please enter the secret code (e.g., %s): ", COLORS);
    scanf("%s", SECRET_CODE);

    bool found = false;
    int attempts = 0;

    printf("Attempting to find the secret code...\n");
    while (attempts < MAX_ATTEMPTS && !found) {
        char guess[CODE_LENGTH + 1];
        generate_all_possible_codes(colors, CODE_LENGTH, SECRET_CODE);

        if (is_valid_guess(guess) && compare_codes(guess, SECRET_CODE) == CODE_LENGTH * 10) {
            found = true;
            printf("Found the secret code: %s\n", guess);
        }

        attempts++;
    }

    if (found) {
        printf("Congratulations! You've cracked the code.\n");
    } else {
        printf("Sorry, you couldn't find the secret code within %d attempts. You lose.\n", MAX_ATTEMPTS);
    }

    return 0;
}
