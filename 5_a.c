#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int value;
    int weight;
    double ratio;
} Item;

// Comparator function for qsort (descending order by ratio)
int compareItems(const void *a, const void *b) {
    double r1 = ((Item *)a)->ratio;
    double r2 = ((Item *)b)->ratio;
    if (r1 < r2) return 1;
    else if (r1 > r2) return -1;
    else return 0;
}

double fractionalKnapsack(int capacity, Item items[], int n) {
    // Calculate value-to-weight ratio
    for (int i = 0; i < n; i++) {
        items[i].ratio = (double)items[i].value / items[i].weight;
    }

    // Sort items by ratio in descending order using qsort
    qsort(items, n, sizeof(Item), compareItems);

    double totalValue = 0.0;
    int currentWeight = 0;

    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= capacity) {
            currentWeight += items[i].weight;
            totalValue += items[i].value;
        } else {
            int remainingCapacity = capacity - currentWeight;
            totalValue += items[i].ratio * remainingCapacity;
            break;
        }
    }

    return totalValue;
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

    srand(time(NULL));  // Seed random number generator

    for (int i = 0; i < n; i++) {
        items[i].weight = rand() % 20 + 1;
        items[i].value = rand() % 20 + 1;
        if (n < 20) {
            printf("Item %d: Weight = %d, Value = %d\n", i + 1, items[i].weight, items[i].value);
        }
    }

    capacity=3*n;

    clock_t start = clock();
    double maxValue = fractionalKnapsack(capacity, items, n);
    clock_t end = clock();

    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Maximum value in fractional knapsack = %.2f\n", maxValue);
    printf("Time taken: %.6f seconds\n", time_spent);

    free(items);
    return 0;
}

