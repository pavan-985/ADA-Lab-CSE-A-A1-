#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void insertion_sort(int*array,int size){
    for (int i = 1; i < size; i++)
    {
        int key=array[i];
        int j = i-1;
        while (j>=0 && array[j] > key)
        {
            array[j+1]=array[j];
            j--;
        }
         
            
            array[j+1]=key;
        
        
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

    insertion_sort(arr, n);
    }

    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
   printf("Time taken to INSERTION sort %d elements: %f seconds", n, time_taken/repetation);

    free(arr);

    return 0;
}
