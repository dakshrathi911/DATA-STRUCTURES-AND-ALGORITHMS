#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node
{
        int info;
        struct node*left;
        struct node*right;
};
struct node *makenode(int x)
{
    struct node *p;
    p=(struct node*)malloc(sizeof(struct node));
    p->info=x;
    p->left=NULL;
    p->right=NULL;
}
void pre(struct node *t)
{
    if(t!=NULL)
    {
        printf("%d ",t->info);
        pre(t->left);
        pre(t->right);
    }
}
void post(struct node *t)
{
    if(t!=NULL)
    {
        post(t->left);
        post(t->right);
        printf("%d ",t->info);
    }
}
void in(struct node *t)
{
    if(t!=NULL)
    {
        in(t->left);
        printf("%d ",t->info);
        in(t->right);
    }
}

int count(struct node *t)
{
    if(t!= NULL)
    {
        in(t->left);
        in(t->right);
    }
}