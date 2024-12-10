#include <stdio.h>

int check(int n, int rev) 
{
    if (n == 0) 
    {
        return rev;
    }
    return check(n / 10, rev * 10 + (n % 10));
}

int main() {
    int n;

    printf("Enter n: ");
    scanf("%d", &n);

    int rev = check(n, 0);
    if (n == rev) 
    {
        printf("%d is palindrome", n);
    } else 
    {
        printf("%d is not palindrome", n);
    }

    return 0;
}
