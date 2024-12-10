#include <stdio.h>
#include <stdlib.h>

/******************************************************************/

struct node {
    int data;
    struct node *left;
    struct node *right;
    struct node *father;
};

/******************************************************************/

struct node* create(int x, struct node* father) {
    struct node* p = (struct node*)malloc(sizeof(struct node));
    p->data = x;
    p->left = NULL;
    p->right = NULL;
    p->father = father;
    return p;
}

/******************************************************************/

struct node* bstinsert(struct node* root, int x) {
    struct node *p, *q;
    if (root == NULL) {
        return create(x, NULL);
    }
    p = root;
    q = NULL;
    while (p != NULL) {
        q = p;
        if (p->data < x) {
            p = p->right;
        } else {
            p = p->left;
        }
    }
    if (x < q->data) {
        q->left = create(x, q);
    } else {
        q->right = create(x, q);
    }
    return root;
}

/******************************************************************/

void inorder(struct node* t) {
    if (t != NULL) {
        inorder(t->left);
        printf("%d ", t->data);
        inorder(t->right);
    }
}

/******************************************************************/

struct node* search(struct node* t, int x) {
    struct node* p = t;
    while (p != NULL) {
        if (p->data == x) {
            return p;
        } else if (x < p->data) {
            p = p->left;
        } else {
            p = p->right;
        }
    }
    return NULL;
}

/******************************************************************/

struct node* findMin(struct node* t) {
    struct node* p = t;
    while (p != NULL && p->left != NULL) {
        p = p->left;
    }
    return p;
}

/******************************************************************/

struct node* findMax(struct node* t) {
    struct node* p = t;
    while (p != NULL && p->right != NULL) {
        p = p->right;
    }
    return p;
}

/******************************************************************/

struct node* successor(struct node* t) {
    if (t->right != NULL) {
        return findMin(t->right);
    }
    struct node* p = t->father;
    while (p != NULL && t == p->right) {
        t = p;
        p = p->father;
    }
    return p;
}

/******************************************************************/

struct node* predecessor(struct node* t) {
    if (t->left != NULL) {
        return findMax(t->left);
    }
    struct node* p = t->father;
    while (p != NULL && t == p->left) {
        t = p;
        p = p->father;
    }
    return p;
}

/******************************************************************/

struct node* deleteNode(struct node* root, int x) {
    struct node* t = search(root, x);
    if (t == NULL) {
        return root;
    }
    if (t->left == NULL && t->right == NULL) {
        if (t->father == NULL) {
            root = NULL;
        } else if (t == t->father->left) {
            t->father->left = NULL;
        } else {
            t->father->right = NULL;
        }
        free(t);
    } else if (t->left == NULL || t->right == NULL) {
        struct node* child = (t->left != NULL) ? t->left : t->right;
        if (t->father == NULL) {
            root = child;
        } else if (t == t->father->left) {
            t->father->left = child;
        } else {
            t->father->right = child;
        }
        child->father = t->father;
        free(t);
    } else {
        struct node* succ = successor(t);
        t->data = succ->data;
        root = deleteNode(root, succ->data);
    }
    return root;
}

/******************************************************************/

int main() {
    struct node* root = NULL;
    root = bstinsert(root, 100);
    root = bstinsert(root, 50);
    root = bstinsert(root, 160);
    root = bstinsert(root, 40);
    root = bstinsert(root, 120);
    root = bstinsert(root, 170);
    root = bstinsert(root, 45);

    printf("In-order traversal: ");
    inorder(root);
    printf("\n");

    int key = 120;
    struct node* res = search(root, key);
    if (res != NULL) {
        printf("Element %d found.\n", key);
        if (res->father != NULL) {
            printf("Father of %d is %d.\n", key, res->father->data);
        } else {
            printf("Father of %d is NULL (root node).\n", key);
        }
    } else {
        printf("Element %d not found.\n", key);
    }

    struct node* minNode = findMin(root);
    struct node* maxNode = findMax(root);
    if (minNode != NULL) {
        printf("Min: %d\n", minNode->data);
    }
    if (maxNode != NULL) {
        printf("Max: %d\n", maxNode->data);
    }

    
    return 0;
}
