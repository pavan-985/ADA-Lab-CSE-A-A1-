#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int binary_search(int arr[], int start, int end, int key)
{

    if (start <= end)
    {

        int mid = start + (end - start) / 2;

        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] < key)
        {
            return binary_search(arr, mid + 1, end, key);
        }
        else
        {
            return binary_search(arr, start, mid - 1, key);
        }
    }

    return -1;
}
void generateRandomarray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100000;
        // printf("%d ", arr[i]); // generate random number
    }
}

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}
int main()
{
    int n;
    printf("Enter the size of array: ");
    if (scanf("%d", &n) != 1 || n <= 0)
    {
        printf("Invalid array size\n");
        return 1;
    }

    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    srand(time(NULL)); // Seed the random number generator
    generateRandomarray(arr, n);
    qsort(arr, n, sizeof(int), compare);
   
    
    int key;
    printf("\nEnter the key (0 to 99999): ");
    if (scanf("%d", &key) != 1 || key < 0 || key >= 100000)
    {
        printf("Invalid key\n");
        free(arr);
        return 1;
    }
    int repetation = 10;
    clock_t start = clock();
    for (int i = 0; i < repetation; i++)
    {
        int ans = binary_search(arr, 0, n - 1, key);
        if (ans == -1)
        {
            printf("the key %d is not found: ", key);
        }
        else
        {
            printf("the key %d is found at %dth index: ", key, ans);
        }
    }

    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\ntime taken to binary search  elements: %f seconds\n", time_taken / repetation);
    free(arr);

    return 0;
}
