#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CODE_LENGTH 4
#define POPULATION_SIZE 100
#define MAX_GENERATIONS 1000

// Function to generate a random code
void generateCode(char code[CODE_LENGTH]) {
    static const char colors[] = {'R', 'G', 'B', 'Y'};
    for (int i = 0; i < CODE_LENGTH; ++i) {
        code[i] = colors[rand() % 4];
    }
}

// Function to calculate the fitness of a code (number of correct characters in correct positions)
int calculateFitness(char code[CODE_LENGTH], char guess[CODE_LENGTH]) {
    int fitness = 0;
    for (int i = 0; i < CODE_LENGTH; ++i) {
        if (code[i] == guess[i]) {
            ++fitness;
        }
    }
    return fitness;
}

// Function to perform crossover between two codes
void crossover(char parent1[CODE_LENGTH], char parent2[CODE_LENGTH], char child[CODE_LENGTH]) {
    int crossoverPoint = rand() % CODE_LENGTH;
    for (int i = 0; i < crossoverPoint; ++i) {
        child[i] = parent1[i];
    }
    for (int i = crossoverPoint; i < CODE_LENGTH; ++i) {
        child[i] = parent2[i];
    }
}

// Function to perform mutation on a code
void mutate(char code[CODE_LENGTH]) {
    int mutationPoint = rand() % CODE_LENGTH;
    static const char colors[] = {'R', 'G', 'B', 'Y'};
    code[mutationPoint] = colors[rand() % 4];
}

// Function to find the index of the code with the highest fitness in the population
int findBestCode(char population[POPULATION_SIZE][CODE_LENGTH], char secretCode[CODE_LENGTH]) {
    int bestIndex = 0;
    int bestFitness = calculateFitness(population[0], secretCode);
    for (int i = 1; i < POPULATION_SIZE; ++i) {
        int fitness = calculateFitness(population[i], secretCode);
        if (fitness > bestFitness) {
            bestFitness = fitness;
            bestIndex = i;
        }
    }
    return bestIndex;
}

int main() {
    srand(time(NULL));

    char secretCode[CODE_LENGTH];
    generateCode(secretCode);

    char population[POPULATION_SIZE][CODE_LENGTH];

    // Initialize population with random codes
    for (int i = 0; i < POPULATION_SIZE; ++i) {
        generateCode(population[i]);
    }

    for (int generation = 0; generation < MAX_GENERATIONS; ++generation) {
        // Evaluate fitness of each code in the population
        int fitnessScores[POPULATION_SIZE];
        for (int i = 0; i < POPULATION_SIZE; ++i) {
            fitnessScores[i] = calculateFitness(population[i], secretCode);
        }

        // Check if any code has the correct guess
        int bestIndex = findBestCode(population, secretCode);
        if (fitnessScores[bestIndex] == CODE_LENGTH) {
            printf("Solution found in generation %d\n", generation);
            printf("Secret Code: ");
            for (int i = 0; i < CODE_LENGTH; ++i) {
                printf("%c ", secretCode[i]);
            }
            printf("\nGuess: ");
            for (int i = 0; i < CODE_LENGTH; ++i) {
                printf("%c ", population[bestIndex][i]);
            }
            printf("\n");
            break;
        }

        // Print the current generation and the best guess
        printf("Generation %d - Best Guess: ", generation);
        for (int i = 0; i < CODE_LENGTH; ++i) {
            printf("%c ", population[bestIndex][i]);
        }
        printf("  Fitness: %d\n", fitnessScores[bestIndex]);

        // Select parents for crossover using tournament selection
        int parent1 = rand() % POPULATION_SIZE;
        int parent2 = rand() % POPULATION_SIZE;
        if (fitnessScores[parent1] > fitnessScores[parent2]) {
            parent1 = parent2;
        }

        // Create a new population through crossover and mutation
        char newPopulation[POPULATION_SIZE][CODE_LENGTH];
        for (int i = 0; i < POPULATION_SIZE; ++i) {
            crossover(population[parent1], population[rand() % POPULATION_SIZE], newPopulation[i]);
            mutate(newPopulation[i]);
        }

        // Copy the new population back to the original population
        for (int i = 0; i < POPULATION_SIZE; ++i) {
            for (int j = 0; j < CODE_LENGTH; ++j) {
                population[i][j] = newPopulation[i][j];
            }
        }
    }

    return 0;
}
