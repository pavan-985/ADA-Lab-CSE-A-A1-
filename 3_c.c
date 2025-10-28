#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Function to add two matrices
void add(int n, int A[n][n], int B[n][n], int C[n][n])
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
}

// Function to subtract two matrices
void sub(int n, int A[n][n], int B[n][n], int C[n][n])
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
}

// Recursive Strassen’s multiplication
void strassen(int n, int A[n][n], int B[n][n], int C[n][n])
{
    if (n == 1)
    {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int k = n / 2;
    int A11[k][k], A12[k][k], A21[k][k], A22[k][k];
    int B11[k][k], B12[k][k], B21[k][k], B22[k][k];
    int M1[k][k], M2[k][k], M3[k][k], M4[k][k], M5[k][k], M6[k][k], M7[k][k];
    int T1[k][k], T2[k][k];

    // Divide matrices into quadrants
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + k];
            A21[i][j] = A[i + k][j];
            A22[i][j] = A[i + k][j + k];
            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + k];
            B21[i][j] = B[i + k][j];
            B22[i][j] = B[i + k][j + k];
        }
    }

    // M1 = (A11 + A22)(B11 + B22)
    add(k, A11, A22, T1);
    add(k, B11, B22, T2);
    strassen(k, T1, T2, M1);

    // M2 = (A21 + A22)B11
    add(k, A21, A22, T1);
    strassen(k, T1, B11, M2);

    // M3 = A11(B12 - B22)
    sub(k, B12, B22, T2);
    strassen(k, A11, T2, M3);

    // M4 = A22(B21 - B11)
    sub(k, B21, B11, T2);
    strassen(k, A22, T2, M4);

    // M5 = (A11 + A12)B22
    add(k, A11, A12, T1);
    strassen(k, T1, B22, M5);

    // M6 = (A21 - A11)(B11 + B12)
    sub(k, A21, A11, T1);
    add(k, B11, B12, T2);
    strassen(k, T1, T2, M6);

    // M7 = (A12 - A22)(B21 + B22)
    sub(k, A12, A22, T1);
    add(k, B21, B22, T2);
    strassen(k, T1, T2, M7);

    // C11 = M1 + M4 - M5 + M7
    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++)
            C[i][j] = M1[i][j] + M4[i][j] - M5[i][j] + M7[i][j];

    // C12 = M3 + M5
    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++)
            C[i][j + k] = M3[i][j] + M5[i][j];

    // C21 = M2 + M4
    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++)
            C[i + k][j] = M2[i][j] + M4[i][j];

    // C22 = M1 - M2 + M3 + M6
    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++)
            C[i + k][j + k] = M1[i][j] - M2[i][j] + M3[i][j] + M6[i][j];
}

int main()
{
    srand(time(0));
    int n;
    printf("Enter size of matrix (n x n): ");
    scanf("%d", &n);

    // allocate padded matrices
    int A[n][n], B[n][n], C[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)

        {
            A[i][j] = rand() % 10;
            B[i][j] = rand() % 10;
            C[i][j] = 0;
        }
    }

    clock_t start = clock();
    strassen(n, A, B, C);
    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken for Matrix Multiplication (Stresson's Method): %f seconds\n", time_taken);

    
    return 0;
}
