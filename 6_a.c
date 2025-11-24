#include <stdio.h>
#include <stdlib.h>

// Structure to store start and finish times of activities
struct Activity {
    int start;
    int finish;
};

// Comparator function for qsort (sort by finish time)
int compare(const void *a, const void *b) {
    struct Activity *A = (struct Activity *)a;
    struct Activity *B = (struct Activity *)b;
    return A->finish - B->finish; // ascending order
}

// Function to perform Activity Selection iteratively
void activitySelection(struct Activity arr[], int n) {
    printf("\nSelected Activities:\n");

    // The first activity is always selected
    int i = 0;
    printf("Activity %d (Start: %d, Finish: %d)\n", i + 1, arr[i].start, arr[i].finish);

    // Iterate through the remaining activities
    for (int j = 1; j < n; j++) {
        if (arr[j].start >= arr[i].finish) {
            printf("Activity %d (Start: %d, Finish: %d)\n", j + 1, arr[j].start, arr[j].finish);
            i = j;
        }
    }
}

int main() {
    int n;

    // Step 1: Take number of activities from user
    printf("Enter number of activities: ");
    scanf("%d", &n);

    // Step 2: Dynamically allocate memory for 'n' activities
    struct Activity *arr = (struct Activity *)malloc(n * sizeof(struct Activity));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Step 3: Take start and finish times from user
    printf("\nEnter start and finish times for each activity:\n");
    for (int i = 0; i < n; i++) {
        printf("Activity %d:\n", i + 1);
        printf("  Start time: ");
        scanf("%d", &arr[i].start);
        printf("  Finish time: ");
        scanf("%d", &arr[i].finish);
    }

    // Step 4: Sort activities by finish time
    qsort(arr, n, sizeof(struct Activity), compare);

    // Step 5: Perform activity selection
    activitySelection(arr, n);

    // Step 6: Free dynamically allocated memory
    free(arr);

    return 0;
}
