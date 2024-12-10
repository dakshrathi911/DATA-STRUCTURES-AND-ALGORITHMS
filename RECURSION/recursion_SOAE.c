#include <stdio.h>

int SOAE(int a[], int n) {
    if (n <= 0) {
        return 0;
    }
    return a[n - 1] + SOAE(a, n - 1);
}

int main()
{
    int s;
    printf("Enter size: ");
    scanf("%d", &s);
    int a[s];
    printf("Enter elements: ");
    for (int i = 0; i < s; i++) 
    {
        scanf("%d", &a[i]);
    }
    int r = SOAE(a, s);
    printf("Sum: %d\n", r);
    return 0;
}