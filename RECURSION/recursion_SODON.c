#include <stdio.h>

int SODON(int n) 
{
    if (n == 0)
    {
        return 0;
    }
    return (n% 10) + SODON(n / 10);
}

int main() 
{
    int n;

    printf("Enter n: ");
    scanf("%d",&n);

    int r = SODON(n);
    printf("Sum of digits : %d\n",r);

    return 0;
}
