#include <stdio.h>

typedef struct BTNode {
    int data;
    struct BTNode *lchild;
    struct BTNode *rchild;
} BTNode;

/**
 * 先序遍历非递归算法
 * @param btNode
 */
void Visit(BTNode *pNode);

#define maxSize 100

void preOrderNonrecursion(BTNode *btNode) {
    if (btNode != NULL) {
        BTNode *Stack[maxSize];
        int top = -1;
        BTNode *p;
        Stack[++top] = btNode;
        while (top != -1) {
            p = Stack[top--];
            Visit(p);
            if (p->rchild != NULL) {
                Stack[++top] = p->rchild;
            }
            if (p->lchild != NULL) {
                Stack[++top] = p->lchild;
            }
        }
    }
}

void Visit(BTNode *pNode) {

}

/**
 * 中序遍历非递归算法
 * @param btNode
 */
void inorderNonrecursion(BTNode *btNode) {
    if (btNode != NULL) {
        BTNode *Stack[maxSize];
        int top = -1;
        BTNode *p;
        p = btNode;
        while (top != -1 || p != NULL) {
            while (p != NULL) {
                Stack[top++] = p;
                p = p->rchild;
            }
            if (top != -1) {
                p = Stack[top--];
                Visit(p);
                p = p->lchild;
            }
        }
    }
}

/**
 * 后序遍历非递归算法
 * @param btNode
 */
void postOrderNonrecursion(BTNode *btNode) {
    if (btNode != NULL) {
        BTNode *Stack1[maxSize];
        BTNode *Stack2[maxSize];
        int top1 = -1;
        int top2 = -1;
        BTNode *p;
        Stack1[++top1] = btNode;
        while (top1 != -1) {
            p = Stack1[top1--];
            Stack2[++top2] = p;
            if (p->lchild != NULL) {
                Stack1[++top1] = p->lchild;
            }
            if (p->rchild != NULL) {
                Stack1[++top1] = p->rchild;
            }
        }
        while (top2 != -1) {
            p = Stack2[top2--];
            Visit(p);
        }
    }
}

/**
 * 线索二叉树
 */
typedef struct TBTNode {
    char data;
    int ltag, rtag;
    struct TBTNode *lchild;
    struct TBTNode *rchild;
} TBTNode;

/**
 * 线索二叉树
 * @param p
 * @param pre
 */
void inThread(TBTNode *p, TBTNode *&pre) {
    if (p != NULL) {
        inThread(p->lchild, pre);
        if (p->lchild != NULL) {
            p->lchild = pre;
            p->ltag = 1;
        }
        if (pre != NULL && pre->rchild == NULL) {
            pre->rchild = p;
            pre->rtag = 1;
        }
        pre = p;
        inThread(p->rchild, pre);
    }
}

void createInThread(TBTNode *root) {
    TBTNode *pre = NULL;
    if (root != NULL) {
        inThread(root, pre);
        pre->rchild = NULL;
        pre->rtag = 1;
    }
}

/**
 * 中序线索二叉树中，中序序列下的第一个节点
 * @param p
 * @return
 */
TBTNode *first(TBTNode *p) {
    while (p->ltag == 0) {
        p = p->lchild;
    }
    return p;
}

/**
 * 中序线索二叉树下，结点p在中序下的后继结点
 * @param p
 * @return
 */
TBTNode *next(TBTNode *p) {
    if (p->rtag == 0) {
        return first(p->rchild);
    } else {
        return p->rchild;
    }
}

void inOrder(TBTNode *root) {
    for (TBTNode *p = first(root); p != NULL; p = next(p)) {
        Visit(p);
    }
}

void Visit(TBTNode *p);

/**
 * 前序线索二叉树
 * @param p
 * @param pre
 */
void preThread(TBTNode *p, TBTNode *&pre) {
    if (p != NULL) {
        if (p->lchild != NULL) {
            p->lchild = pre;
            p->ltag = 1;
        }
        if (pre != NULL && pre->rchild == NULL) {
            pre->rchild = p;
            pre->rtag = 1;
        }
        pre = p;
        /**
         * 递归入口处，左、右指针不是线索才能继续递归
         */
        if (p->ltag == 0) {
            preThread(p->lchild, pre);
        }
        if (p->rtag == 0) {
            preThread(p->rchild, pre);
        }
    }
}

/**
 * 遍历前序线索二叉树
 * @param root
 */
void preOrder(TBTNode *root) {
    if (root != NULL) {
        TBTNode *p = root;
        while (p != NULL) {
            while (p->ltag == 0) {
                Visit(p);
                p = p->rchild;
            }
            Visit(p);
            p = p->rchild;
        }
    }
}

/**
 * 后序线索二叉树
 * @param p
 * @param pre
 */
void postThread(TBTNode *p, TBTNode *&pre) {
    if (p != NULL) {
        postThread(p->lchild, pre);
        postThread(p->rchild, pre);
        if (p->lchild == NULL) {
            p->lchild = pre;
            p->ltag = 1;
        }
        if (pre != NULL && pre->rchild == NULL) {
            pre->rchild = p;
            pre->rtag = 1;
        }
        pre = p;
    }
}