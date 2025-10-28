#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void linear_search(int arr[], int size, int element)
{
    int found = 0, i;
    for (i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            found = 1;
            break;
        }
    }
    if (found)
    {
        // printf("the element %d is found at %dth index", element, i);
    }
    else
    {
        // printf("the element %d is not found :", element);
    }
}
void generateRandomarray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100000;
        // printf("%d ",arr[i]);// generate random number
    }
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

    int key;
    printf("\nEnter the key (0 to 99999): ");
    if (scanf("%d", &key) != 1 || key < 0 || key >= 100000)
    {
        printf("Invalid key\n");
        free(arr);
        return 1;
    }
    int repetation = 1000;
    clock_t start = clock();
    for (int i = 0; i < repetation; i++)
    {
        linear_search(arr, n, key);
    }

    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\ntime taken to linear search  elements: %f seconds\n", time_taken / repetation);
    free(arr);

    return 0;
}
