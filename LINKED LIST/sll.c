#include <stdio.h> 
#include <stdlib.h>  
struct node 
{ 
int info; 
struct node *next; 
} *start; 
 
struct node *getNode(void) 
{ 
struct node *p; 
p = (struct node *)malloc(sizeof(struct node)); 
return p; 
} 
void insertBegin(int x) 
{ 
    struct node *p; 
    p = getNode(); 
    p->info = x; 
    p->next = start; 
    start = p; 
}  
void insertEnd(int x) 
{ 
    struct node *q, *p; 
    q = start; 
    while (q->next != NULL) 
    { 
        q = q->next; 
    } 
    p = getNode(); 
    p->info = x; 
    p->next = NULL; 
    q->next = p; 
} 
void Traverse() 
{ 
    struct node *p; 
    p = start; 
    while (p != NULL) 
    { 
        printf("%d   ", p->info); 
        p = p->next; 
    } 
}
int countNode() 
{ 
    struct node *p; 
    p = start; 
    int c = 0; 
    while (p != NULL) 
    { 
        c++; 
        p = p->next; 
    } 
    return c; 
} 
void swap(int *p, int *q) 
{ 
    *p = *p + *q; 
    *q = *p - *q; 
    *p = *p - *q; 
}
void swapConsecutive() 
{ 
    struct node *p, *q; 
    p = start; 
    q = start->next; 
    while (p != NULL && q != NULL) 
    { 
        swap(&(p->info), &(q->info)); 
        p = p->next; 
        p = p->next; 
        q = q->next; 
        if (q != NULL) 
            q = q->next; 
    } 
}
struct node *reverseList() 
{ 
    struct node *prev = NULL, *curr = start, *n = start->next; 
    while (curr != NULL) 
    { 
        curr->next = prev; 
        prev = curr; 
        curr = n; 
        if (n != NULL) 
            n = n->next; 
    } 
    start = prev; 
    return start; 
}
void insertAtPostition(int x, int position) 
{ 
    int y = countNode(); 
    if (position > y + 1) 
        printf("Insertion Not Possible.\n"); 
    else 
    { 
        if (position == 1) 
            insertBegin(x); 
        else 
        { 
            struct node *p = start; 
            int c = 1; 
            while (c < position - 1) 
            { 
                p = p->next; 
                c++; 
            } 
            insertAfter(p, x); 
        } 
    } 
} 
void printReverse() 
{ 
    if (start != NULL) 
    { 
        printReverse(start->next); 
        printf("%d", start->info); 
    } 
}
void insertAfter(struct node *q, int x) 
{ 
    struct node *p, *r; 
    p = getNode(); 
    p->info = x; 
    r = q->next; 
    q->next = p; 
    p->next = r; 
}
void orderedInsert(int x) 
{ 
    struct node *p, *q; 
    p = start; 
    q = NULL; 
    while (p != NULL && x >= p->info) 
    { 
        q = p; 
        p = p->next; 
 
        if (q == NULL) 
            insertBegin(x); 
        else 
            insertAfter(q, x); 
    } 
}
int main() 
{ 
    start = NULL; 
    insertBegin(10); 
    insertBegin(20); 
    insertEnd(100); 
    insertEnd(1200); 
    insertEnd(1400); 
    insertAtPostition(54, 4); 
    Traverse(); 
    printf("\n"); 
    return 0; 
}