#include <stdio.h>
void Traverse(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}
void UnionArray(int A[], int m, int B[], int n)
{
    int C[m + n];
    int i = 0, j = 0, k = 0;
    while (i < m && j < n)
    {
        if (A[i] < B[j])
        {
            C[k++] = A[i++];
        }
        else if (A[i] > B[j])
        {
            C[k++] = B[j++];
        }
        else
        {
            C[k++] = A[i++];
            j++;
        }
    }
    while (i < m)
    {
        C[k++] = A[i++];
    }
    while (j < n)
    {
        C[k++] = B[j++];
    }
    Traverse(C, k);
}
void IntersectionArray(int A[], int m, int B[], int n)
{
    int C[m < n ? m : n];
    int i = 0, j = 0, k = 0;
    while (i < m && j < n)
    {
        if (A[i] < B[j])
        {
            i++;
        }
        else if (A[i] > B[j])
        {
            j++;
        }
        else
        {
            C[k++] = A[i++];
            j++;
        }
    }
    Traverse(C, k);
}
void DifferenceArray(int A[], int m, int B[], int n)
{
    int C[m];
    int i = 0, j = 0, k = 0;
    while (i < m && j < n)
    {
        if (A[i] < B[j])
        {
            C[k++] = A[i++];
        }
        else if (A[i] > B[j])
        {
            j++;
        }
        else
        {
            i++;
            j++;
        }
    }
    while (i < m)
    {
        C[k++] = A[i++];
    }
    Traverse(C, k);
}
void SymmetricDifferenceArray(int A[], int m, int B[], int n)
{
    int C[m + n];
    int i = 0, j = 0, k = 0;
    while (i < m && j < n)
    {
        if (A[i] < B[j])
        {
            C[k++] = A[i++];
        }
        else if (A[i] > B[j])
        {
            C[k++] = B[j++];
        }
        else
        {
            i++;
            j++;
        }
    }
    while (i < m)
    {
        C[k++] = A[i++];
    }
    while (j < n)
    {
        C[k++] = B[j++];
    }
    Traverse(C, k);
}
int main()
{
    int A[] = {1, 2, 3, 4, 5};
    int B[] = {4, 5, 6, 7, 8};
    int m = sizeof(A) / sizeof(A[0]);
    int n = sizeof(B) / sizeof(B[0]);
    printf("Union: ");
    UnionArray(A, m, B, n);
    printf("Intersection: ");
    IntersectionArray(A, m, B, n);
    printf("Difference: ");
    DifferenceArray(A, m, B, n);
    printf("Symmetric Difference: ");
    SymmetricDifferenceArray(A, m, B, n);
    return 0;
}
