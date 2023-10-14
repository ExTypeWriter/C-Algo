#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int value;
    int amount;
}Coin;

void printCombination(Coin coins[], int numCoins) {
    for (int i = 0; i < numCoins; i++) {
        printf("%d: %d\n", coins[i].value, coins[i].amount);
    }
    printf("\n");
}

int calculateTotalValue(Coin coins[], int numCoins) {
    int totalValue = 0;
    for (int i = 0; i < numCoins; i++) {
        totalValue += coins[i].value * coins[i].amount;
    }
    return totalValue;
}

void findCombinations(Coin coins[], int numCoins, int target, Coin bestSolution[], int* bestValue, int* bestAmount, int currentCoin, int currentAmount) {
    if (currentAmount == target) {
        int totalValue = calculateTotalValue(coins, numCoins);
        int totalAmount = 0;
        for (int i = 0; i < numCoins; i++) {
            totalAmount += coins[i].amount;
        }
        if (totalValue > *bestValue || (totalValue == *bestValue && totalAmount < *bestAmount)) {
            *bestValue = totalValue;
            *bestAmount = totalAmount;
            for (int i = 0; i < numCoins; i++) {
                bestSolution[i] = coins[i];
            }
        }
        // printCombination(coins, numCoins); // Print the current combination
        return;
    }
    if (currentCoin == numCoins) {
        return;
    }

    for (int i = 0; i * coins[currentCoin].value + currentAmount <= target; i++) {
        coins[currentCoin].amount = i;
        findCombinations(coins, numCoins, target, bestSolution, bestValue, bestAmount, currentCoin + 1, currentAmount + i * coins[currentCoin].value);
        coins[currentCoin].amount = 0;
    }
}

int main() {
    int target;
    // printf("Enter the target amount: ");
    scanf("%d", &target);

    int numCoins;
    // printf("Enter the number of coin types: ");
    scanf("%d", &numCoins);

    Coin coins[numCoins];

    for (int i = 0; i < numCoins; i++) {
        // printf("Enter the value of coin %d: ", i + 1);
        scanf("%d", &coins[i].value);
        coins[i].amount = 0;
    }

    Coin bestSolution[numCoins];
    int bestValue = 0;
    int bestAmount = target + 1;

    // printf("All Possible Solutions:\n");
    findCombinations(coins, numCoins, target, bestSolution, &bestValue, &bestAmount, 0, 0);

    // printf("Best Solution: \n");
    printCombination(bestSolution, numCoins);
    // printf("Total Coin used: %d coins\n",bestAmount);

    return 0;
}
