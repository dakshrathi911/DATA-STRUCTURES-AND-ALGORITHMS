#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int d;
    struct node *n;
} node;

node *create(int v) {
    node *t = (node *)malloc(sizeof(node));
    t->d = v;
    t->n = NULL;
    return t;
}

node *insbeg(node *h, int v) {
    node *t = create(v);
    t->n = h;
    return t;
}

node *insend(node *h, int v) {
    node *t = create(v);
    if (!h) return t;
    node *c = h;
    while (c->n) c = c->n;
    c->n = t;
    return h;
}

node *delbeg(node *h) {
    if (!h) return NULL;
    node *t = h;
    h = h->n;
    free(t);
    return h;
}

node *delend(node *h) {
    if (!h) return NULL;
    if (!h->n) {
        free(h);
        return NULL;
    }
    node *c = h;
    while (c->n->n) c = c->n;
    free(c->n);
    c->n = NULL;
    return h;
}

void disp(node *h) {
    while (h) {
        printf("%d ", h->d);
        h = h->n;
    }
    printf("\n");
}

node *concat(node *h1, node *h2) {
    if (!h1) return h2;
    node *c = h1;
    while (c->n) c = c->n;
    c->n = h2;
    return h1;
}

int main() {
    node *l1 = NULL, *l2 = NULL;
    l1 = insbeg(l1, 1);
    l1 = insend(l1, 2);
    l2 = insbeg(l2, 3);
    l2 = insend(l2, 4);
    printf("List 1: ");
    disp(l1);
    printf("List 2: ");
    disp(l2);
    l1 = concat(l1, l2);
    printf("Concatenated: ");
    disp(l1);
    return 0;
}
