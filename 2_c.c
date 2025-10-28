#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void selection_sort(int *array, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int index_of_min = i, j;
        for (int j = i + 1; j < size; j++)
        {
            if (array[j] < array[index_of_min])
            {
                index_of_min = j;
            }
        }
        int temp = array[i];
        array[i] = array[index_of_min];
        array[index_of_min] = temp;
    }
    
}
void generateRandomarray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100000;
        // printf("%d ", arr[i]); // generate random number
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

    int repetation = 1000;
    clock_t start = clock();
    for (int i = 0; i < repetation; i++)
    {

    selection_sort(arr, n);
    }

    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
   printf("Time taken to selection sort %d elements: %f seconds", n, time_taken/repetation);

    free(arr);

    return 0;
}
