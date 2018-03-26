#define maxSize 100

/**
 * 链栈结点定义
 */
typedef struct LNode {
    int data;
    struct LNode *next;
} LNode;

/**
 * 顺序栈定义
 */
typedef struct {
    int data[maxSize];
    int top;
} SqStack;

/**
 * 进栈
 */
int pushStack(SqStack &stack, int x) {
    if (stack.top == maxSize - 1) {
        return 0;
    }
    ++stack.top;
    stack.data[stack.top] = x;
    return 1;
}

/**
 * 出栈
 */
int popStack(SqStack &stack, int &x) {
    if (stack.top == -1) {
        return 0;
    }
    x = stack.data[stack.top];
    --stack.top;
    return 1;
}

/**
 * 顺序队列定义
 */
typedef struct {
    int data[maxSize];
    int front;
    int rear;
} SqQueue;

/**
 * 链式队列定义
 */
//队结点定义
typedef struct QNode {
    int data;
    struct QNode *next;
} QNode;

typedef struct {
    QNode *front;
    QNode *rear;
} LiQueue;