#include <stdio.h>

// Define Coin struct
typedef struct
{
    int value; // Value of coin 
    int amount; // Amount of coin to contribute change
} Coin;

// Print coin usage for each coin type.
void PrintCoinUsage(Coin *coin_array, int M) 
{
    for (int j = 0; j < M; j++)
    {
        printf("%d: %d\n", coin_array[j].value, coin_array[j].amount);
    }
}
// Find coin used in each type.
void MinCoinChange(Coin *coin_array,int N , int M) 
{
    // Init 0 to all element in coin array.
    for (int i = 0; i < M; i++)
    {
        scanf("%d", &coin_array[i].value);
        coin_array[i].amount = 0;
    }

    int table[N + 1];
    table[0] = 0;  

    // Generate table.
    for (int i = 1; i <= N; i++)
    {
        table[i] = N + 1;

        for (int j = 0; j < M; j++)
        {
            if (coin_array[j].value <= i && table[i - coin_array[j].value] + 1 < table[i])
            {
                table[i] = table[i - coin_array[j].value] + 1;
            }
        }
    }

    // Backtrack to find the used coins.
    int amount = N;
    for (int j = M - 1; j >= 0; j--)
    {
        while (amount >= coin_array[j].value && table[amount] == table[amount - coin_array[j].value] + 1)
        {
            coin_array[j].amount++;
            amount -= coin_array[j].value;
        }
    }
}

int main()
{
    int TotalChange;
    scanf("%d", &TotalChange);

    int CoinTypeCount;
    scanf("%d", &CoinTypeCount);

    Coin coins[CoinTypeCount]; 

    MinCoinChange(coins, TotalChange ,CoinTypeCount);

    PrintCoinUsage(coins, CoinTypeCount);

    return 0;
}
