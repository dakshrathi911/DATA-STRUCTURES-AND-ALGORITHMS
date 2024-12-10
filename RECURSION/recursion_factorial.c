#include<stdio.h>
int fact(int n)
{
    if(n==1)
    {
        return 1;
    }
    else
    {
        return fact(n-1)*n;
    }
}
int main()
{
    int n;
    printf("enter n:");
    scanf("%d",&n);
    printf("%d!= %d",n,fact(n));
}