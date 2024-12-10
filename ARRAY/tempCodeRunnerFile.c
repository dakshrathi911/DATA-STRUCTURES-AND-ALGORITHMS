#include <stdio.h>
void Traverse(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}
void Insert(int a[], int n, int idx, int val)
{
    for (int i = n - 1; i >= idx; i--)
    {
        a[i + 1] = a[i];
    }
    a[idx] = val;
}
void InsertSorted(int a[], int n, int val)
{
    int idx = 0;
    while (idx < n && val > a[idx])
    {
        idx++;
    }
    Insert(a, n, idx, val);
}
int Delete(int a[], int n, int idx)
{
    int val = a[idx];
    for (int i = idx + 1; i < n; i++)
    {
        a[i - 1] = a[i];
    }
    return val;
}
void Reverse(int a[], int n)
{
    int start = 0, end = n - 1;
    while (start < end)
    {
        int temp = a[start];
        a[start] = a[end];
        a[end] = temp;
        start++;
        end--;
    }
}
void Merge(int a[], int m, int b[], int n)
{
    int c[m + n];
    int i = 0, j = 0, k = 0;
    while (i < m && j < n)
    {
        if (a[i] < b[j])
        {
            c[k++] = a[i++];
        }
        else
        {
            c[k++] = b[j++];
        }
    }
    while (i < m)
    {
        c[k++] = a[i++];
    }
    while (j < n)
    {
        c[k++] = b[j++];
    }
    Traverse(c, m + n);
}

int main()
{
    int a[6] = {10, 20, 30, 40, 50};
    int n = 5;
    printf("Original array: ");
    Traverse(a, n);
    int valToInsert = 25;
    InsertSorted(a, n, valToInsert);
    n++;
    printf("Array after inserting %d: ", valToInsert);
    Traverse(a, n);
    int idxToDelete = 2;
    int deletedVal = Delete(a, n, idxToDelete);
    n--;
    printf("Deleted element: %d\n", deletedVal);
    printf("Array after deletion: ");
    Traverse(a, n);
    Reverse(a, n);
    printf("Array after reversal: ");
    Traverse(a, n);
    int b1[] = {1, 3, 5};
    int b2[] = {2, 4, 6};
    printf("Merged array: ");
    Merge(b1, 3, b2, 3);
    return 0;
}