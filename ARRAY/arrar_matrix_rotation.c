    #include <stdio.h>
    void traverse(int A[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            printf("%d ", A[i]);
        }
        printf("\n");
    }
    void matrixTranspose(int m, int n, int mat[m][n], int trans[n][m])
    {
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                trans[j][i] = mat[i][j];
            }
        }
    }
    void transposeInPlace(int n, int mat[n][n])
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int tmp = mat[i][j];
                mat[i][j] = mat[j][i];
                mat[j][i] = tmp;
            }
        }
    }
    void RotateArray(int A[], int n, int k)
    {
        k = k % n;
        for (int i = 1; i <= k; i++)
        {
            int last = A[n - 1];
            for (int j = n - 1; j > 0; j--)
            {
                A[j] = A[j - 1];
            }
            A[0] = last;
        }
    }
    void reverseArray(int arr[], int start, int end)
    {
        while (start < end)
        {
            int tmp = arr[start];
            arr[start] = arr[end];
            arr[end] = tmp;
            start++;
            end--;
        }
    }
    void rotateArray(int arr[], int n, int k)
    {
        k = k % n;
        reverseArray(arr, 0, n - 1);
        reverseArray(arr, 0, k - 1);
        reverseArray(arr, k, n - 1);
    }
    void rotateArrayK(int arr[], int n, int k)
    {
        k = k % n;
        if (k == 0)
            return;
        int tmp[k];
        for (int i = 0; i < k; i++)
        {
            tmp[i] = arr[n - k + i];
        }
        for (int i = n - 1; i >= k; i--)
        {
            arr[i] = arr[i - k];
        }
        for (int i = 0; i < k; i++)
        {
            arr[i] = tmp[i];
        }
    }
    void rotateArrayAntiClockwise(int arr[], int n, int k)
    {
        k = k % n;
        if (k == 0)
            return;
        int tmp[k];
        for (int i = 0; i < k; i++)
        {
            tmp[i] = arr[i];
        }
        for (int i = 0; i < n - k; i++)
        {
            arr[i] = arr[i + k];
        }
        for (int i = 0; i < k; i++)
        {
            arr[n - k + i] = tmp[i];
        }
    }
    int main()
    {
        int mat[2][3] = {{1, 2, 3}, {4, 5, 6}};
        int trans[3][2];
        matrixTranspose(2, 3, mat, trans);
        printf("Matrix Transpose:\n");
        for (int i = 0; i < 3; i++)
        {
            traverse(trans[i], 2);
        }
        int square[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
        transposeInPlace(3, square);
        printf("Matrix Transpose In Place:\n");
        for (int i = 0; i < 3; i++)
        {
            traverse(square[i], 3);
        }
        int arr[5] = {1, 2, 3, 4, 5};
        printf("Original Array:\n");
        traverse(arr, 5);
        rotateArray(arr, 5, 2);
        printf("Array after clockwise rotation:\n");
        traverse(arr, 5);
        rotateArrayAntiClockwise(arr, 5, 2);
        printf("Array after anti-clockwise rotation:\n");
        traverse(arr, 5);
        return 0;
    }
