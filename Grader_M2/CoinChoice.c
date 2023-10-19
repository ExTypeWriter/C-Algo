#include <stdio.h>
#include <limits.h>

void CoinChange(int coins[], int numCoins, int amount, int current[], int currentIndex, int *lowestCount, int *highestCoin, int *bestCombination) {
    if (amount == 0) {
        int totalCoins = 0;
        int highestValueCoin = 0;
        for (int i = 0; i < numCoins; i++) {
            totalCoins += current[i];
            if (current[i] > 0 && coins[i] > highestValueCoin) {
                highestValueCoin = coins[i];
            }
        }

        if (totalCoins < *lowestCount || (totalCoins == *lowestCount && highestValueCoin > *highestCoin)) {
            *lowestCount = totalCoins;
            *highestCoin = highestValueCoin;
            for (int i = 0; i < numCoins; i++) {
                bestCombination[i] = current[i];
            }
        }

        return;
    }

    if (currentIndex == numCoins) {
        return;
    }

    for (int i = 0; i <= amount / coins[currentIndex]; i++) {
        current[currentIndex] = i;
        CoinChange(coins, numCoins, amount - i * coins[currentIndex], current, currentIndex + 1, lowestCount, highestCoin, bestCombination);
    }
}

int main() {
    int target_value, numCoins;
    scanf("%d", &target_value);
    scanf("%d", &numCoins);
    int coins[numCoins];
    for (int k = 0; k < numCoins; k++) {
        scanf("%d", &coins[k]);
    }

    int current[numCoins];
    for (int i = 0; i < numCoins; i++) {
        current[i] = 0;
    }

    int lowestCount = INT_MAX;
    int highestCoin = 0;
    int bestCombination[numCoins];
    
    CoinChange(coins, numCoins, target_value, current, 0, &lowestCount, &highestCoin, bestCombination);
    for (int i = 0; i < numCoins; i++) {
        printf("%d: %d\n", coins[i], bestCombination[i]);
    }
    return 0;
}
