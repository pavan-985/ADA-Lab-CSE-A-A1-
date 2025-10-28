#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void printFibonacci(int n)
{
    int n1 = 0, n2 = 1;
    int nextTerm;
    printf("Fibonacci Series: ");
    for (int i = 1; i <= n; ++i)
    {
        printf("%d, ", n1);
        nextTerm = n1 + n2;
        n1 = n2;
        n2 = nextTerm;
    }
    printf("\n");
}

int main()

{
    int terms;
    printf("Enter the number of terms: ");
    scanf("%d", &terms);

    clock_t start = clock();
    printFibonacci(terms);
    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to fibonacci series (Iterative) %d elements: %f seconds: ", terms, time_taken);

    return 0;
}
