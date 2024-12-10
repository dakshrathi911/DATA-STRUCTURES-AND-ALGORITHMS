#include<stdio.h>
#include<stdlib.h>
struct stack{
    int item[10];
    int Top;
};

struct stack s;

void Push(int x){
    if(s.Top==9){
        printf("Stack Overflow");
        exit(1);
    }
    s.Top = s.Top+1;
    s.item[s.Top]=x;
}

int Pop(){
    int x;
    if(s.Top==-1){
        printf("Stack Underflow");
        exit(1);
    }
    x=s.item[s.Top];
    s.Top=s.Top-1;
    return x;
}

int StackTop(){
    int x;
    x=s.item[s.Top];
    return x;
}

int main(){
    int y;
    s.Top=-1;
    Push(5);
    Push(10);
    Push(11);
    y=Pop();
    printf("Popped items==>>%d\n",y);
    y=StackTop();
    printf("Top item is ==>%d",y);  
}