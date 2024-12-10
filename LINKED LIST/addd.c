#include <stdio.h>
#include <stdlib.h>

typedef struct Node *NODE;

struct Node
{
    int coef, exp;
    NODE next;
};

NODE create()
{
    NODE node = (NODE)malloc(sizeof(struct Node));
    return node;
}

NODE insert(NODE start, int coef, int exp)
{
    NODE temp, node;
    if (start == NULL)
    {
        node = create();
        node->coef = coef;
        node->exp = exp;
        node->next = NULL;
        start = node;
        return start;
    }
    temp = start;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    node = create();
    node->coef = coef;
    node->exp = exp;
    node->next = NULL;
    temp->next = node;
    return start;
}

void display(NODE start)
{
    NODE temp = start;
    while (temp != NULL)
    {
        printf("%dx^%d ", temp->coef, temp->exp);
        if (temp->next != NULL)
        {
            printf("+ ");
        }
        temp = temp->next;
    }
}

NODE add(NODE poly1, NODE poly2)
{
    NODE result = NULL;
    NODE p = poly1, q = poly2;
    while (p != NULL && q != NULL)
    {
        if (p->exp == q->exp)
        {
            result = insert(result, p->coef + q->coef, p->exp);
            p = p->next;
            q = q->next;
        }
        else if (p->exp > q->exp)
        {
            result = insert(result, p->coef, p->exp);
            p = p->next;
        }
        else
        {
            result = insert(result, q->coef, q->exp);
            q = q->next;
        }
    }

    while (p != NULL)
    {
        result = insert(result, p->coef, p->exp);
        p = p->next;
    }

    while (q != NULL)
    {
        result = insert(result, q->coef, q->exp);
        q = q->next;
    }

    return result;
}

int main()
{
    NODE poly1 = NULL, poly2 = NULL, poly3 = NULL;

    poly1 = insert(poly1, 3, 7);
    poly1 = insert(poly1, 4, 6);
    poly1 = insert(poly1, -5, 4);
    poly1 = insert(poly1, 1, 2);
    poly1 = insert(poly1, -9, 0);
    display(poly1);
    printf("\n\n");

    poly2 = insert(poly2, 2, 6);
    poly2 = insert(poly2, 1, 5);
    poly2 = insert(poly2, -3, 4);
    poly2 = insert(poly2, 2, 3);
    poly2 = insert(poly2, 3, 2);
    poly2 = insert(poly2, -2, 0);
    display(poly2);
    printf("\n\n");

    poly3 = add(poly1, poly2);
    display(poly3);
    printf("\n\n");

    return 0;
}
