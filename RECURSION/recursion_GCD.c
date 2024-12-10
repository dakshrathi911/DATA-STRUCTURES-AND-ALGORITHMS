#include <stdio.h>

int gcd(int a, int b) 
{
    if (b == 0) 
    {
        return a;
    }
    return gcd(b, a % b);
}

int main() 
{
    int n1, n2;

    printf("Enter two numbers: ");
    scanf("%d %d", &n1, &n2);

    int r=gcd(n1, n2);
    printf("GCD: %d",r);

    return 0;
}
