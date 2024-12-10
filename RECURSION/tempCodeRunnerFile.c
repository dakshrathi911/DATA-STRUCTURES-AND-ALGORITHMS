#include<stdio.h>
int hanoi(int n,char s,char m,char d){
    if (n==1) printf("%c-->%c\n",s,d);
    else{
        hanoi(n-1,s,d,m);
        printf("%c-->%c\n",s,d);
        hanoi(n-1,m,s,d);
    }
}
void main(){
    int n;
    char s='S',m='M',d='D';
    printf("Enter value of n: ");
    scanf("%d",&n);
    hanoi(n,s,m,d);
}