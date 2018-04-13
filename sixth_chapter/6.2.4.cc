#include <stdio.h>
#include <iostream>

using namespace std;
typedef struct BTNode {
    char data;
    struct BTNode *lchild;
    struct BTNode *rchild;
} BTNode;

void Visit(BTNode *p) {

}

/**
 * 前序遍历
 * 1.访问根结点
 * 2.前序遍历左子树
 * 3.前序遍历右子树
 */
void preOrder(BTNode *p) {
    Visit(p);
    preOrder(p->lchild);
    preOrder(p->rchild);
}

/**
 * 中序遍历
 * 1.中序遍历左子树
 * 2.访问根节点
 * 3.中序遍历右子树
 */
void inOrder(BTNode *p) {
    inOrder(p->lchild);
    Visit(p);
    inOrder(p->rchild);
}

/**
 * 后续遍历
 * 1.后序遍历左子树
 * 2.后续遍历右子树
 * 3.访问根结点
 */
void postOrder(BTNode *p) {
    postOrder(p->lchild);
    postOrder(p->rchild);
    Visit(p);
}

int op(int a, int i, char data);

/**
 * (a-(b+c))*(d/e)
 *         *
 *       /   \
 *      -     /
 *     /\    / \
 *    a  +  d   e
 *      / \
 *     b   c
 *  后序遍历
 * @param p
 * @return
 */
int comp(BTNode *p) {
    int A, B;
    if (p != NULL) {
        if (p->lchild != NULL && p->rchild != NULL) {
            A = comp(p->lchild);
            B = comp(p->rchild);
            return op(A, B, p->data);
        } else {
            return p->data - '0';
        }
    } else {
        return 0;
    }
}

int op(int a, int i, char data) {
    switch (data) {
        case '*':
            return a * i;
        case '/':
            return a / i;
        case '+':
            return a + i;
        case '-':
            return a - i;
        default:
            return 0;
    }
}

/**
 * 获取树的深度
 * @param p
 * @return
 */
int getDepth(BTNode *p) {
    int LD, RD;
    if (p == NULL) {
        return 0;
    } else {
        LD = getDepth(p->lchild);
        RD = getDepth(p->rchild);
        return (LD > RD ? LD : RD) + 1;
    }
}

/**
 * 输出先序遍历序列中的第k个结点的值
 */
int n;

void trave(BTNode *p, int k) {
    if (p != NULL) {
        ++n;
        if (k == n) {
            cout << p->data << endl;
            return;
        }
        trave(p->lchild, k);
        trave(p->rchild, k);
    }
}

/**
 * 层次遍历
 */
#define maxSize 100

void level(BTNode *p) {
    int front, rear;
    BTNode *que[maxSize];
    front = rear = 0;
    BTNode *q;
    if (p != NULL) {
        rear = (rear + 1) % maxSize;
        que[rear] = p;
        while (front != rear) {
            front = (front + 1) % maxSize;
            q = que[front];
            Visit(q);
            if (q->lchild != NULL) {
                rear = (rear + 1) & maxSize;
                que[rear] = q->lchild;
            }
            if (q->rchild != NULL) {
                rear = (rear + 1) % maxSize;
                que[rear] = q->rchild;
            }
        }
    }
}

/**
 * 求二叉树的宽度
 */
typedef struct {
    BTNode *p;
    int lno;
} St;

int maxNode(BTNode *b) {
    St que[maxSize];
    int front, rear;
    int Lno, i, j, n, max;
    front = rear = 0;
    BTNode *q;
    if (b != NULL) {
        ++rear;
        que[rear].p = b;
        que[rear].lno = 1;
        while (front != rear) {
            ++front;
            q = que[front].p;
            Lno = que[front].lno;
            if (q->lchild != NULL) {
                ++rear;
                que[rear].p = q->lchild;
                que[rear].lno = Lno + 1;
            }
            if (q->rchild != NULL) {
                ++rear;
                que[rear].p = q->rchild;
                que[rear].lno = Lno + 1;
            }
        }
        max = 0;
        for (i = 1; i <= Lno; ++i) {
            n = 0;
            for (j = 1; j <= rear; ++j) {
                if (que[j].lno == i) {
                    ++n;
                }
                if (max < n) {
                    max = n;
                }
            }
        }
        return max;
    } else {
        return 0;
    }
}