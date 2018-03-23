#include <malloc.h>
#include <clocale>

/**
 * 链队
 */
typedef struct QNode {
    int data;
    struct QNode *next;
} QNode;

typedef struct {
    QNode *front;
    QNode *rear;
} LiQueue;

void initQueue(LiQueue *&liQueue) {
    liQueue = static_cast<LiQueue *>(malloc(sizeof(LiQueue)));
    liQueue->front = liQueue->rear = NULL;
}

int isQueueEmpty(LiQueue *liQueue) {
    if (liQueue->rear == NULL || liQueue->front == NULL)
        return 1;
    else
        return 0;
}

void enQueue(LiQueue *liQueue, int x) {
    QNode *p;
    p = static_cast<QNode *>(malloc(sizeof(QNode)));
    p->data = x;
    p->next = NULL;
    if (liQueue->rear == NULL)
        liQueue->front = liQueue->rear = p;
    else {
        liQueue->rear->next = p;
        liQueue->rear = p;
    }
}

int deQueue(LiQueue *&liQueue, int &x) {
    QNode *p;
    if (liQueue->rear == NULL)
        return 0;
    else
        p = liQueue->front;
    if (liQueue->front == liQueue->rear)
        liQueue->front = liQueue->rear = NULL;
    else
        liQueue->front = liQueue->front->next;
    x = p->data;
    free(p);
    return 1;
}
