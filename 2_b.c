#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int partition(int *array, int low, int high)
{
    int pivot = array[low],temp;
    int i = low + 1;
    int j = high;
    do
    {
        while (array[i] <= pivot)
        {
            i++;
        }
        while (array[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
             temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }while(i<j);


    temp=array[low];
    array[low] = array[j];
    array[j] = temp;
    return j;
}
void quick_sort(int *array, int low, int high)
{
    if (low < high)
    {
        int partitionindex = partition(array, low, high);
        quick_sort(array, low, partitionindex - 1);
        quick_sort(array, partitionindex + 1, high);
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

    quick_sort(arr, 0, n - 1);
    }

    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
   printf("Time taken to quick sort %d elements: %f seconds :", n, time_taken/repetation);

    free(arr);

    return 0;
}
