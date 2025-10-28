#include <stdio.h>
#include <stdlib.h>
#include <time.h>
long long fib_array[100]; // Array to store fibonacci
long long fib(int n)
{
    if (n <= 1)
    {
        return n;
    }
    // Check if we have already computed it
    if (fib_array[n] != 0)
    {
        return fib_array[n];
    }
    // If not, compute and store it
    fib_array[n] = fib(n - 1) + fib(n - 2);
    return fib_array[n];
}
int main()
{
    int terms;
    printf("Enter the number of terms (up to 92): ");
    scanf("%d", &terms);

    // Initialize array with 0s
    for (int i = 0; i < 100; i++)
    {
        fib_array[i] = 0;
    }
    printf("Fibonacci Series: ");

    clock_t start = clock();
    for (int i = 0; i < terms; i++)
    {
        printf("%lld, ", fib(i));
    }
    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nTime taken to fibonacci series (Top-Down approach) %d elements: %f seconds: ", terms, time_taken);

    printf("\n");
    return 0;
}