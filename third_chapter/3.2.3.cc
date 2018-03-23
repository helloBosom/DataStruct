#include <malloc.h>
#include <clocale>

typedef struct LNode {
    int data;
    struct LNode *next;
} LNode;

/**
 * 初始化
 */
void initStack(LNode *&lNode) {
    lNode = (LNode *) malloc(sizeof(LNode));
    lNode->next = NULL;
}

/**
 * 判断栈空
 */
int isEmpty(LNode *lNode) {
    if (lNode->next == NULL) {
        return 1;
    } else
        return 0;
}

/**
 * 进栈
 */
void pushStack(LNode *pLNode, int x) {
    LNode *p;
    p = (LNode *) malloc(sizeof(LNode));//为进栈元素申请结点空间
    p->next = NULL;

    /**
     * 链表头插法
     */
    p->data = x;
    p->next = pLNode->next;
    pLNode->next = p;
}

int popStack(LNode *lNode, int &x) {
    LNode *p;
    if (LNode.next == NULL)
        return 0;
    p = lNode->next;
    x = p->data;
    lNode->next = p->next;
    free(p);
    return 1;
}
