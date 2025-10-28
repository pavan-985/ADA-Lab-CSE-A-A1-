#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int value;
    int weight;
} Item;

// 0/1 Knapsack using dynamic programming
int knapsack01(int capacity, Item items[], int n) {
    // Create a DP table
    int **dp = (int **)malloc((n + 1) * sizeof(int *));
    for (int i = 0; i <= n; i++) {
        dp[i] = (int *)malloc((capacity + 1) * sizeof(int));
    }

    // Build the table
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (items[i - 1].weight <= w)
                dp[i][w] = (items[i - 1].value + dp[i - 1][w - items[i - 1].weight] > dp[i - 1][w]) ?
                            items[i - 1].value + dp[i - 1][w - items[i - 1].weight] :
                            dp[i - 1][w];
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    int result = dp[n][capacity];

    // Free memory
    for (int i = 0; i <= n; i++) {
        free(dp[i]);
    }
    free(dp);

    return result;
}

int main() {
    int n, capacity;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    Item *items = (Item *)malloc(n * sizeof(Item));
    if (items == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    srand(time(NULL));  // Seed the random generator

    // Generate random items
    for (int i = 0; i < n; i++) {
        items[i].weight = rand() % 20 + 1;
        items[i].value = rand() % 20 + 1;
        if (n < 20) {
            printf("Item %d: Weight = %d, Value = %d\n", i + 1, items[i].weight, items[i].value);
        }
    }

    capacity=3*n;

    clock_t start = clock();
    int maxValue = knapsack01(capacity, items, n);
    clock_t end = clock();

    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Maximum value in 0/1 knapsack = %d\n", maxValue);
    printf("Time taken: %.6f seconds\n", time_spent);

    free(items);
    return 0;
}
