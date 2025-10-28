#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Global pointers
int **A, **B, **C;

// Function for recursive divide-and-conquer matrix multiplication
void Matrix_Multiplication_Divide_conquer(int n, int rowA, int colA, int rowB, int colB, int rowC, int colC)
{
    if (n == 1)
    {
        C[rowC][colC] += A[rowA][colA] * B[rowB][colB];
        return;
    }

    int k = n / 2;

    // C11 = A11*B11 + A12*B21
    Matrix_Multiplication_Divide_conquer(k, rowA, colA, rowB, colB, rowC, colC);
    Matrix_Multiplication_Divide_conquer(k, rowA, colA + k, rowB + k, colB, rowC, colC);

    // C12 = A11*B12 + A12*B22
    Matrix_Multiplication_Divide_conquer(k, rowA, colA, rowB, colB + k, rowC, colC + k);
    Matrix_Multiplication_Divide_conquer(k, rowA, colA + k, rowB + k, colB + k, rowC, colC + k);

    // C21 = A21*B11 + A22*B21
    Matrix_Multiplication_Divide_conquer(k, rowA + k, colA, rowB, colB, rowC + k, colC);
    Matrix_Multiplication_Divide_conquer(k, rowA + k, colA + k, rowB + k, colB, rowC + k, colC);

    // C22 = A21*B12 + A22*B22
    Matrix_Multiplication_Divide_conquer(k, rowA + k, colA, rowB, colB + k, rowC + k, colC + k);
    Matrix_Multiplication_Divide_conquer(k, rowA + k, colA + k, rowB + k, colB + k, rowC + k, colC + k);
}

int main()
{
    int n;

    printf("Enter n (must be a power of 2): ");
    scanf("%d", &n);

    if ((n & (n - 1)) != 0)
    {
        printf("Error: n must be a power of 2.\n");
        return 1;
    }

    srand(time(NULL));

    // Dynamic allocation for matrices
    A = (int **)malloc(n * sizeof(int *));
    B = (int **)malloc(n * sizeof(int *));
    C = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        A[i] = (int *)malloc(n * sizeof(int));
        B[i] = (int *)malloc(n * sizeof(int));
        C[i] = (int *)malloc(n * sizeof(int));
    }

    // Initialize matrices A, B and C
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            A[i][j] = rand() % 10;
            B[i][j] = rand() % 10;
            C[i][j] = 0;
        }
    }

    // Time calculation
    clock_t start = clock();
    Matrix_Multiplication_Divide_conquer(n, 0, 0, 0, 0, 0, 0);
    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken for Matrix Multiplication (Divide and Conquer): %f seconds\n", time_taken);

    // Free allocated memory
    for (int i = 0; i < n; i++)
    {
        free(A[i]);
        free(B[i]);
        free(C[i]);
    }
    free(A);
    free(B);
    free(C);

    return 0;
}
