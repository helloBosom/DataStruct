#define maxSize 100

typedef struct {
    int data[maxSize];
    int front;
    int rear;
} SqQueue;

void initQueue(SqQueue &sqQueue) {
    sqQueue.front = sqQueue.rear = 0;
}

int isQueueEmpty(SqQueue sqQueue) {
    if (sqQueue.front == sqQueue.rear)
        return 0;
    else
        return 1;
}

int enQueue(SqQueue &sqQueue, int x) {
    if ((sqQueue.rear + 1) % maxSize == sqQueue.front)
        return 0;
    sqQueue.rear = (sqQueue.rear + 1) % maxSize;
    sqQueue.data[sqQueue.rear] = x;
    return 1;
}

int deQueue(SqQueue &sqQueue, int &x) {
    if (sqQueue.rear == sqQueue.front)
        return 0;
    sqQueue.front = (sqQueue.front + 1) % maxSize;
    x = sqQueue.data[sqQueue.front];
    return 1;
}