#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node *l;
    struct node *r;
    struct node *father;
};

struct node* create(int x, struct node* father) {
    struct node* p = (struct node*)malloc(sizeof(struct node));
    p->val = x;
    p->l = NULL;
    p->r = NULL;
    p->father = father;
    return p;
}

struct node* insert(struct node* root, int x) {
    struct node *p, *q;
    if (root == NULL) {
        return create(x, NULL);
    }
    p = root;
    q = NULL;
    while (p != NULL) {
        q = p;
        if (p->val < x) {
            p = p->r;
        } else {
            p = p->l;
        }
    }
    if (x < q->val) {
        q->l = create(x, q);
    } else {
        q->r = create(x, q);
    }
    return root;
}

void inorder(struct node* t) {
    if (t != NULL) {
        inorder(t->l);
        printf("%d ", t->val);
        inorder(t->r);
    }
}

struct node* search(struct node* t, int x) {
    struct node* p = t;
    while (p != NULL) {
        if (p->val == x) {
            return p;
        } else if (x < p->val) {
            p = p->l;
        } else {
            p = p->r;
        }
    }
    return NULL;
}

struct node* findMin(struct node* t) {
    struct node* p = t;
    while (p != NULL && p->l != NULL) {
        p = p->l;
    }
    return p;
}

struct node* findMax(struct node* t) {
    struct node* p = t;
    while (p != NULL && p->r != NULL) {
        p = p->r;
    }
    return p;
}



int main() {
    struct node* root = NULL;
    root = insert(root, 100);
    root = insert(root, 50);
    root = insert(root, 160);
    root = insert(root, 40);
    root = insert(root, 120);
    root = insert(root, 170);
    root = insert(root, 45);

    printf("In-order traversal: ");
    inorder(root);
    printf("\n");

    struct node* res = search(root, 120);
    if (res != NULL) {
        struct node* succ = successor(res);
        struct node* pred = predecessor(res);
        if (succ != NULL) {
            printf("Successor of %d: %d\n", res->val, succ->val);
        } else {
            printf("Successor of %d: None\n", res->val);
        }
        if (pred != NULL) {
            printf("Predecessor of %d: %d\n", res->val, pred->val);
        } else {
            printf("Predecessor of %d: None\n", res->val);
        }
    }

    printf("Deleting node 50...\n");
    root = deleteNode(root, 50);

    printf("In-order traversal after deletion: ");
    inorder(root);
    printf("\n");

    return 0;
}
