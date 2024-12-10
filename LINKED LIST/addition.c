#include <stdio.h>
#include <stdlib.h>

typedef struct node* NODE;
/*/
struct node{
    int coef, exp;
    NODE next;
};

/*/

NODE getNode(void){
    NODE p;
    p = (NODE )malloc(sizeof(struct node));
    return p;
}

/*/
NODE insertBegin(NODE start, int c,int exp){
    NODE p;
    p = getNode();
    p->coef = c;
    p->exp = exp;
    p->next = start;
    start = p;
    return start;
}
/*/
NODE insertEnd(NODE start,int x,int exp){
    NODE q, p;
    if (start == NULL) {
        p = getNode();
        p->coef = x;
        p->exp = exp;
        p->next = NULL;
        start = p;
        return start;
    }
    q = start;
    while (q->next != NULL) {
        q = q->next;
    }
    p = getNode();
    p->coef = x;
    p->exp = exp;
    p->next = NULL;
    q->next = p;
    return start;
}
void Traverse(NODE start){
    NODE p;
    p = start;
    while (p != NULL){
        printf("%dx^%d + ", p->coef,p->exp);
        p = p->next;
    }
}
int countNode(NODE start){
    NODE p;
    p = start;
    int c = 0;
    while (p != NULL){
        c++;
        p = p->next;
    }
    return c;
}


NODE polyAddition(NODE P1, NODE P2){
    NODE P3 = NULL;
    NODE p = P1, q = P2;
    while(p != NULL && q != NULL){
        if(p->exp == q->exp){
            P3 = insertEnd(P3, p->coef + q->coef, p->exp);
            p = p->next;
            q = q->next;
        }
        else if(p->exp > q->exp){
            P3 = insertEnd(P3, p->coef, p->exp);
            p = p->next;
        }
        else{
            P3 = insertEnd(P3, q->coef, q->exp);
            q = q->next;
        }
    }

    while(p != NULL){
        P3 = insertEnd(P3, p->coef, p->exp);
        p = p->next;
    }

    while(q != NULL){
        P3 = insertEnd(P3, q->coef, q->exp);
        q = q->next;
    }

    return P3;
}


int main(){
    NODE p1=NULL, p2=NULL,p3=NULL;
    p1 = insertEnd(p1, 3, 7);
    p1 = insertEnd(p1, 4, 6);
    p1 = insertEnd(p1, -5, 4);
    p1 = insertEnd(p1, 1, 2);
    p1 = insertEnd(p1, -9, 0);
    Traverse(p1);
    printf("\n\n");

    p2=insertEnd(p2, 2, 6);
    p2=insertEnd(p2, 1, 5);
    p2=insertEnd(p2, -3, 4);
    p2=insertEnd(p2, 2, 3);
    p2=insertEnd(p2, 3, 2);
    p2=insertEnd(p2, -2, 0);

    Traverse(p2);
    printf("\n\n");

    p3=polyAddition(p1, p2);
    Traverse(p3);
    printf("\n\n");

}