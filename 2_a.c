#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void merging(int *array, int low, int mid, int high)
{
    int i = low, j = mid + 1, k = 0;
    int size = high - low + 1;
    int *newarray = (int *)malloc((size) * sizeof(int));
    // int newarray[100];
    if (newarray == NULL)
    {
        printf("Memory allocation failed in merging: \n");
        exit(1);
    }
    while (i <= mid && j <= high)
    {
        if (array[i] < array[j])
        {
            newarray[k] = array[i];
            i++;
            k++;
        }
        else
        {
            newarray[k] = array[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        newarray[k] = array[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        newarray[k] = array[j];
        j++;
        k++;
    }
    for (int i = 0; i < size; i++)
    {
        array[low + i] = newarray[i];
    }

    free(newarray);
}
void merge_sort(int *array, int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        merge_sort(array, low, mid);
        merge_sort(array, mid + 1, high);
        merging(array, low, mid, high);
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

        merge_sort(arr, 0, n - 1);
    }

    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to MERGE sort %d elements: %f seconds: ", n, time_taken / repetation);

    free(arr);

    return 0;
}
