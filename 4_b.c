#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int fib(int n)
{
    if (n <= 1)
    {
        return n;
    }
    return fib(n - 1) + fib(n - 2);
}
int main()
{
    int terms;
    printf("Enter the number of terms:");
    scanf("%d", &terms);
    printf("Fibonacci Series: ");
    clock_t start = clock();
    for (int i = 0; i < terms; i++)
    {
        printf("%d, ", fib(i));
    }
    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nTime taken to fibonacci series (Recursive) %d elements: %f seconds: ", terms, time_taken);

    printf("\n");
    return 0;
}