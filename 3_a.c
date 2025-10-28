#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void Matrix_Multiplication_iterative(int **matrix1, int **matrix2, int **productMatrix, int n)
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                productMatrix[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

int main()
{
    int n;

    printf("Enter n: ");
    scanf("%d", &n);

    srand(time(NULL));

    //memory allocation
    int **matrix1 = (int **)malloc(n * sizeof(int *));
    int **matrix2 = (int **)malloc(n * sizeof(int *));
    int **productMatrix = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        matrix1[i] = (int *)malloc(n * sizeof(int));
        matrix2[i] = (int *)malloc(n * sizeof(int));
        productMatrix[i] = (int *)malloc(n * sizeof(int));
    }

    //
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix1[i][j] = rand() % 10;
            matrix2[i][j] = rand() % 10;
            productMatrix[i][j] = 0;
        }
    }

    //calculating time
    clock_t start = clock();
    Matrix_Multiplication_iterative(matrix1, matrix2, productMatrix, n);
    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("time taken to Matrix Multiplication (Iterative)  elements: %f seconds", time_taken);

    //free memory
    for (int i = 0; i < n; i++)
    {
        free(matrix1[i]);
        free(matrix2[i]);
        free(productMatrix[i]);
    }
    free(matrix1);
    free(matrix2);
    free(productMatrix);

    return 0;
}
