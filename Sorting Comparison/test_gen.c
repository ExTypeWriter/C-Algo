#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void writeRandNum(FILE *file, int lower, int upper, int number_of_element, int number_of_arr) {
    fprintf(file,"%d\n", number_of_element);
    int j = 0;
    while (j < number_of_element) {
        int num = (rand() % (upper - lower + 1)) + lower;
        fprintf(file, "%d\n", num);
        j++;
    }
}

void writeRandChar(FILE *file, int number_of_element, int number_of_arr) {
    int i = 0;
    while (i < number_of_arr) {
        int j = 0;
        while (j < number_of_element) {
            char c = 'A' + rand() % 26; // Generates a random uppercase letter
            fprintf(file, "%c ", c);
            j++;
        }
        fprintf(file, "\n");
        i++;
    }
}

void writeRandString(FILE *file, int string_length, int number_of_arr) {
    int i = 0;
    while (i < number_of_arr) {
        fprintf(file, "\"");
        for (int j = 0; j < string_length; ++j) {
            char c = 'A' + rand() % 26; // Generates a random uppercase letter
            fprintf(file, "%c", c);
        }
        fprintf(file, "\" ");
        fprintf(file, "\n");
        i++;
    }
}

void writeRandFloat(FILE *file, float lower, float upper, int number_of_element, int number_of_arr ,int precision) {
    int i = 0;
    while (i < number_of_arr) {
        int j = 0;
        while (j < number_of_element) {
            float num = ((float)rand() / RAND_MAX) * (upper - lower) + lower;
            fprintf(file, "%.*f ", precision , num);
            j++;
        }
        fprintf(file, "\n");
        i++;
    }
}

void writeRandDouble(FILE *file, double lower, double upper, int number_of_element, int number_of_arr) {
    int i = 0;
    while (i < number_of_arr) {
        int j = 0;
        while (j < number_of_element) {
            double num = ((double)rand() / RAND_MAX) * (upper - lower) + lower;
            fprintf(file, "%.2lf ", num);
            j++;
        }
        fprintf(file, "\n");
        i++;
    }
}

int main() {
    srand(time(0));
    
    FILE *num_test = fopen("test_int.txt", "w");
    FILE *char_test = fopen("test_char.txt", "w");
    FILE *str_test = fopen("test_str.txt", "w");
    FILE *float_test = fopen("test_float.txt", "w");
    FILE *double_test = fopen("test_double.txt", "w");
    int decimal_place = 4;
    int length_of_string = 8;
    int number_of_elements = 1000;
    int number_of_test_cases = 10;
    int lower_bound_int = -100;
    int upper_bound_int = 1000;
    float lower_bound_float = 0.0;
    float upper_bound_float = 4.0;
    // Example usage of functions
    writeRandNum(num_test, lower_bound_int, upper_bound_int, number_of_elements , number_of_test_cases);
    writeRandChar(char_test, number_of_elements, number_of_test_cases);
    writeRandString(str_test, length_of_string, number_of_test_cases);
    writeRandFloat(float_test, lower_bound_float, upper_bound_float, number_of_elements, number_of_test_cases , decimal_place);
    writeRandDouble(double_test, 0.0, 1.0, number_of_elements, number_of_test_cases);
    
    fclose(num_test);
    fclose(str_test);
    fclose(char_test);
    fclose(float_test);
    fclose(double_test);
    return 0;
}
