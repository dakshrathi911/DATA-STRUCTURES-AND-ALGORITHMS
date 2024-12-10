#include <stdio.h>

int rev(int n, int r) 
{
    if (n == 0) 
    {
        return r;
    }
    return rev(n / 10, r * 10 + (n % 10));
}

int main()
{
    int n;

    printf("Enter n: ");
    scanf("%d", &n);

    int r = rev(n, 0);
    printf("Reverse: %d\n", r);

    return 0;
}
