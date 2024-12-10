#include <stdio.h>
void T(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}
void matrixAddition(int m, int n, int mat1[m][n], int mat2[m][n], int res[m][n])
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            res[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}
void matrixSubtraction(int m, int n, int mat1[m][n], int mat2[m][n], int res[m][n])
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            res[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
}
void matrixMultiplication(int r1, int c1, int mat1[r1][c1], int r2, int c2, int mat2[r2][c2], int res[r1][c2])
{
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            res[i][j] = 0;
        }
    }

    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            for (int k = 0; k < c1; k++)
            {
                res[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}
int main()
{
    int mat1[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int mat2[2][3] = {{7, 8, 9}, {1, 2, 3}};
    int resAdd[2][3];
    int resSub[2][3];
    matrixAddition(2, 3, mat1, mat2, resAdd);
    printf("Matrix Addition:\n");
    for (int i = 0; i < 2; i++)
    {
        T(resAdd[i], 3);
    }
    matrixSubtraction(2, 3, mat1, mat2, resSub);
    printf("Matrix Subtraction:\n");
    for (int i = 0; i < 2; i++)
    {
        T(resSub[i], 3);
    }
    int mat3[3][2] = {{1, 2}, {3, 4}, {5, 6}};
    int resMul[2][2];
    matrixMultiplication(2, 3, mat1, 3, 2, mat3, resMul);
    printf("Matrix Multiplication:\n");
    for (int i = 0; i < 2; i++)
    {
        T(resMul[i], 2);
    }
    return 0;
}
