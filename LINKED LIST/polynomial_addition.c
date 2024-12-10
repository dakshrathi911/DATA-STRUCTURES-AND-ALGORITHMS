#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *next;
    //self referential structure
};
struct node *GetNode(void)
{
    struct node *p;
    p=(struct node *)malloc(sizeof(struct node));
    return p;
}
struct node * start;
void InsBeg(int x)
{
    struct node *p;
    p=GetNode();
    p->info=x;
    p->next=start;
    start=p;
}
void InsertAfter(struct node **q, int x)
{
    struct node* p=GetNode();
    p->info=x;
    struct node* r=(*q)->next;
    (*q)->next=p;
    p->next=r;
}
void InsEnd(int x)
{
    struct node *q=start;
    while(q->next!=NULL)
    {
        q=q->next;
    }
    struct node* p=GetNode();
    p->info=x;
    p->next=NULL;
    q->next=p;
}
int CountNodes(void)
{
    int count=0;
    struct node* p=start;
    while(p!=NULL)
    {
        count++;
        p=p->next;
    }
    return count;
}

void swap(void)
{
    struct node* p=start;
    struct node* q= start->next;
    while(p!=NULL && q!=NULL)
    {
        int t=p->info;
        p->info=q->info;
        q->info=t;
        p=p->next;
        p=p->next;
        q=q->next;
        if(q!=NULL)
        {
            q=q->next;
        }
    }
}
void OrderedInsertion(int x)
{
    struct node* p=start;
    struct node* q=NULL;
    while(p!=NULL && x>=p->info)
    {
        q=p;
        p=p->next;
    }
    if(q==NULL)
    {
        InsBeg(x);
    }
    else{
        InsertAfter(&q,x);
    }
}
void InsertAtPosition(int x, int pos)
{
    if(pos==1)
    {
        InsBeg(x);
    }
    else{
        int n=CountNodes();
        if(pos>=n+2)
        {
            printf("insertion is not possible");
        }
        else{
            struct node* p=start;
            int c=1;
            while(c<pos-1)
            {
                p=p->next;
                c=c+1;
            }
            InsertAfter(&p,x);
        }
    }
}
void traverse()
{
    struct node*p;
    p=start;
    while(p!=NULL)
    {
        printf("%d ",p->info);
        p=p->next;
    }
}
void reverse1(void)
{
    struct node* prev=NULL;
    struct node* curr=start;
    struct node* n=start->next;
    while(curr!=NULL)
    {
        curr->next=prev;
        prev=curr;
        curr=n;
        if(n!=NULL)
        {
            n=n->next;
        }
    }
    start=prev;
}
void reverse_traverse(struct node* start)
{
    if(start!=NULL)
    {
        reverse_traverse(start->next);
        printf("%d ",start->info);
    }
}
struct stack{
    int Item[100];
    int Top;
};
struct stack S;
void Initialise()
{
    S.Top=-1;
}
int IsEmpty()
{
    if(S.Top==-1) return 1;
    else   return 0;
}
void Push(int x)
{
    if(S.Top==99)
    {
        printf("Stack Overflows");
        exit(1);
    }
    else
    {
        S.Top+=1;
        S.Item[S.Top]=x;
    }
}
int Pop()
{
    int x;
    if(S.Top==-1)
    {
        printf("Stack Underflows");
        exit(1);
    }
    else
    {
        x=S.Item[S.Top];
        S.Top-=1;
    }
    return x;
}
void reverse2()
{
    struct node* p=start;
    Initialise();
    while(p!=NULL)
    {
        int x=p->info;
        Push(x);
        p=p->next;
    }
    p= start;
    while(!IsEmpty())
    {
        int x=Pop();
        p->info=x;
        p=p->next;
    }
}
void main()
{
    //struct node* start;
    start=NULL;
    // InsBeg(&start,10);
    // InsBeg(20);
    // InsBeg(30);
    // InsBeg(40);
    // InsBeg(50);
    // InsBeg(60);
    // InsBeg(70);
    // InsEnd(100);
    // InsEnd(200);
    // InsEnd(300);
    // traverse();
    // int count=CountNodes();
    // printf("\n%d\n",count);
    // swap();
    // traverse();

    InsBeg(70);
    InsBeg(60);
    InsBeg(50);
    InsBeg(40);
    InsBeg(30);
    InsBeg(20);
    InsBeg(10);
    traverse();
    printf("\n");

    // int x;
    // scanf("%d",&x);
    // OrderedInsertion(x);
    // traverse();

    // reverse1();
    // traverse();

    // int x;
    // scanf("%d",&x);
    // int pos;
    // scanf("%d",&pos);
    // InsertAtPosition(x,pos);
    //traverse();

    // reverse_traverse(start);

    // reverse2();
    // traverse();

    struct node*p;
    p=start;
    while(p->info!=40)
      p=p->next;
    InsertAfter(&p, 1000);
    traverse();

}