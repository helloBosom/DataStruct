#define maxSize 100
/**
 * 顺序栈定义
 */
typedef struct {
    int data[maxSize];
    int top;
} SqStack;

/**
 * 初始化栈
 */
void initStack(SqStack &stack) {
    stack.top = -1;
}

/**
 * 判断栈空
 */
int isEmpty(SqStack stack) {
    if (stack.top == -1)
        return 1;
    else
        return 0;
}

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
 * 实际使用中简化版
 */
//初始化
int stack[maxSize];
int top = -1;

//进栈
//stack[++top] = x;
//出栈
//x = stack[top--];