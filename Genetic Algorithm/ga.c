#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

#define CODE_LENGTH 4
#define COLORS 6

#define POP_SIZE 150

#define CROSSOVER 50
#define MUTATION 3
#define INVERSION 2

typedef struct {
    int code[CODE_LENGTH];
    int fitness;
    int black, white;
} Individual;

void randCode(Individual *code) {
    for (int i = 0; i < CODE_LENGTH; i++) {
        code->code[i] = rand() % COLORS;
    }
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void createPopulation(Individual population[]) {
    for (int i = 0; i < POP_SIZE; i++) {
        randCode(&population[i]);
    }
}

void crossover(Individual *parent1, Individual *parent2) {
    int chance = rand() % 100;
    if (chance < CROSSOVER) {
        int point = rand() % CODE_LENGTH;
        for (int i = point; i < CODE_LENGTH; i++) {
            swap(&parent1->code[i], &parent2->code[i]);
        }
    }
}

void mutation(Individual *individual) {
    int chance = rand() % 100;
    if (chance < MUTATION) {
        int index = rand() % CODE_LENGTH;
        individual->code[index] = rand() % COLORS;
    }
}

void inversion(Individual *individual) {
    int chance = rand() % 100;
    if (chance < INVERSION) {
        int start = rand() % CODE_LENGTH;
        int end = rand() % CODE_LENGTH;

        if (start > end) swap(&start, &end);
        else if (start == end) return;

        while (start < end) {
            swap(&individual->code[start], &individual->code[end]);
            start++;
            end--;
        }
    }
}

void check_BW(Individual *guess, Individual *previous) {
    for (int i = 0; i < CODE_LENGTH; i++) {
        if (guess->code[i] == previous->code[i]) guess->black++;
        else {
            for (int j = 0; j < CODE_LENGTH; j++)
                if (guess->code[i] == previous->code[j]) guess->white++;
        }
    }
}

void fitnessCal(Individual code[], Individual previous[], int prev_size) {
    for (int i = 0; i < POP_SIZE; i++) {
        code[i].fitness = 0;
        for (int j = 0; j < prev_size; j++) {
            check_BW(&code[i], &previous[j]);
            code[i].fitness += abs(previous[j].black - code[i].black) + abs(previous[j].black - code[i].black);
        }
    }
}

void printCode(const Individual *code) {
    for (int i = 0; i < CODE_LENGTH; i++) {
        printf("%d ", code->code[i]);
    }
    printf("\n");
}

int compareSolution(const Individual *solution, const Individual *population, int pop_size) {
    for (int i = 0; i < pop_size; i++) {
        if (memcmp(solution->code, population[i].code, CODE_LENGTH * sizeof(int)) == 0) {
            return 1; // Match found
        }
    }
    return 0; // No match found
}

int main() {
    srand(time(NULL));

    Individual population[POP_SIZE];
    createPopulation(population);

    // User input for the solution
    Individual userSolution;
    printf("Enter your solution (4 numbers between 0 and 5): ");
    scanf("%d %d %d %d", &userSolution.code[0], &userSolution.code[1], &userSolution.code[2], &userSolution.code[3]);

    // Evaluate fitness of the initial population
    int prev_size = 0;

    fitnessCal(population, &userSolution, prev_size);
    for(int i = 0; i < POP_SIZE; i++)
    {
        printf("population #%d: ", i+1);
        printCode(&population[i]);
    }
    // Check for a match with the user solution
    if (compareSolution(&userSolution, population, POP_SIZE)) {
        printf("Solution found in the initial population!\n");
    } else {
        printf("Solution not found in the initial population.\n");
    }

    return 0;
}
