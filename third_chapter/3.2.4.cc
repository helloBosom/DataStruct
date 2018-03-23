#include <iostream>

#define maxSize 100

int match(char exp[], int n) {
    char stack[maxSize];
    int top = -1;
    for (int i = 0; i < n; ++i) {
        if (exp[i] == '(')
            stack[++top] = '(';
        if (exp[i] == ')')
            if (top == -1)
                return 0;
            else
                --top;
    }
    if (top == -1)
        return 1;
    else
        return 0;
}

int op(int a, char Op, int b) {
    if (Op == '+')
        return a + b;
    if (Op == '-')
        return a - b;
    if (Op == '*')
        return a * b;
    if (Op == '/') {
        if (b == 0) {
            std::cout << "ERROR" << std::endl;
            return 0;
        } else
            return a / b;
    }
}

int com(char exp[]) {
    int a, b, c;
    int stack[maxSize];
    int top = -1;
    char Op;
    for (int i = 0; exp[i] != '\0'; ++i) {
        if (exp[i] > '0' && exp[i] < '9')
            stack[++top] = exp[i] - '0';
        else {
            Op = exp[i];
            b = stack[top--];
            a = stack[top--];
            c = op(a, Op, b);
            stack[++top] = c;
        }
    }
    return stack[top];
}

typedef struct LNode {
    int data;
    struct LNode *next;
} LNode;

void initStackl(LNode *&lNode) {
    lNode = NULL;
}

int isEmptyl(LNode *lNode) {
    if (lNode == NULL)
        return 0;
    else
        return 1;
}

void pushl(LNode *&lNode, int x) {
    LNode *p;
    p = (LNode *) malloc(sizeof(LNode));
    p->next == NULL;
    p->data = x;

    p->next = lNode;
    lNode = p;
}

int popl(LNode *&lNode, int &x) {
    LNode *p;
    if (lNode == NULL) {
        return 0;
    }
    p = lNode;
    x = p->data;
    lNode = p->next;
    free(p);
    return 1;
}

