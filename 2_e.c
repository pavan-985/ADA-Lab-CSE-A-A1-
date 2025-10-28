#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void bubblesort(int *array, int size)
{
    int issorted;
    for (int i = 0; i < size - 1; i++)//no of passes 
    {
        // printf("Working on pass number %d\n", i + 1);
        int issorted = 1;

        for (int j = 0; j < size - 1 - i; j++)// no of comparisons in each pass
        {
            if (array[j] > array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                issorted = 0;
            }
        }
   
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

    bubblesort(arr, n);
    }

    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
   printf("Time taken to bubble sort %d elements: %f seconds", n, time_taken/repetation);

    free(arr);

    return 0;
}