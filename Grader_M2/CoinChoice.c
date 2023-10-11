#include <stdio.h>
#include <limits.h>

int min(int a, int b) {
    return (a < b) ? a : b;
}

void findMinCoins(int amount) {
    int coins[] = {10, 5, 2, 1}; // Coin denominations in descending order
    int n = sizeof(coins) / sizeof(coins[0]);
    
    int dp[amount + 1];
    int usedCoins[amount + 1];
    
    dp[0] = 0;
    for (int i = 1; i <= amount; i++) {
        dp[i] = INT_MAX;
        for (int j = 0; j < n; j++) {
            if (i >= coins[j] && 1 + dp[i - coins[j]] < dp[i]) {
                dp[i] = 1 + dp[i - coins[j]];
                usedCoins[i] = coins[j];
            }
        }
    }

    if (dp[amount] == INT_MAX) {
        printf("No solution exists.\n");
        return;
    }

    printf("Minimum number of coins required: %d\n", dp[amount]);
    printf("Coins used:\n");
    while (amount > 0) {
        int coin = usedCoins[amount];
        int count = amount / coin;
        printf("%d x %d\n", coin, count);
        amount -= coin * count;
    }
}

int main() {
    int amount;
    printf("Enter the desired amount: ");
    scanf("%d", &amount);
    
    findMinCoins(amount);
    
    return 0;
}
