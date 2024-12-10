#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10
#define TRUE 1
#define FALSE 0

/************************************************************************/

typedef struct
{
    int item[MAXSIZE];
    int rear;
    int front;
} CQueue;

/***********************************************************************/

void IQueue(CQueue *q)
{
    q->front = -1;
    q->rear = -1;
}
int isEmpty(CQueue *q)
{
    return (q->front == -1);
}
int isFull(CQueue *q)
{
    return ((q->rear + 1) % MAXSIZE == q->front);
}

/************************************************************************/

void enqueue(CQueue *q, int value)
{
    if (isFull(q))
    {
        printf("Queue is full! Cannot enqueue %d\n", value);
        return;
    }
    if (isEmpty(q))
    {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % MAXSIZE;
    q->item[q->rear] = value;
    printf("Enqueued: %d\n", value);
}

/************************************************************************/

int dequeue(CQueue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty! Cannot dequeue.\n");
        return -1; // Indicate that the queue is empty
    }
    int value = q->item[q->front];
    if (q->front == q->rear)
    {
        q->front = -1; // Queue is now empty
        q->rear = -1;
    }
    else
    {
        q->front = (q->front + 1) % MAXSIZE;
    }
    printf("Dequeued: %d\n", value);
    return value;
}

/************************************************************************/

void displayQueue(CQueue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    int i = q->front;
    while (1)
    {
        printf("%d ", q->item[i]);
        if (i == q->rear)
            break;
        i = (i + 1) % MAXSIZE;
    }
    printf("\n");
}

/*****************************************************************************/

int main()
{
    CQueue q;
    IQueue(&q);
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 470);
    enqueue(&q, 450);
    enqueue(&q, 440);
    enqueue(&q, 240);
    enqueue(&q, 420);
    enqueue(&q, 404);
    enqueue(&q, 401);
    enqueue(&q, 420);
    enqueue(&q, 4);
    enqueue(&q, 50);
    displayQueue(&q);
    dequeue(&q);
    displayQueue(&q);
    enqueue(&q, 50);
    displayQueue(&q);
    enqueue(&q, 60);
    dequeue(&q);
    enqueue(&q, 60);
    displayQueue(&q);
    return 0;
}
