#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int nthFibonacci(int n)
{

    // Handle the edge cases
    if (n <= 1)
        return n;
    // Create an array to store Fibonacci
    int dp[n + 1];
    // Initialize the first two Fibonacci

    dp[0] = 0;
    dp[1] = 1;
    // Fill the array iteratively
    for (int i = 2; i <= n; ++i)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    // Return the nth Fibonacci number
    return dp[n];
}
int main()
{
    int n;
    printf("Enter the no. :");
    scanf("%d", &n);

    
    clock_t start = clock();
    for (int i = 0; i < n; i++)
    {
        printf("%d, ", nthFibonacci(i));
    }
    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nTime taken to fibonacci series (Bottom -up approch) elements: %f seconds: ",  time_taken);

    return 0;
}