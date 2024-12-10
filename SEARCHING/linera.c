#include<stdio.h>
int linear(int a[],int n,int k)
{
    for(int i=0;i<n;i++)
    {
        if(a[i]==k)
        {
            return i;
        }
        else
        {
            return -1;
        }
    }
}
void main()
{
    int a[25]={34,56,67,34,78,23,5,45,6,78,23,455,523,436};
    int b=linear(a,25,45);
    (b==(-1))?printf("element  not found"):printf("element at %d",b);
}
