#include <stdio.h>

typedef struct BTNode {
    char data;
    struct BTNode *lchild;
    struct BTNode *rchild;
} BTNode;

void Visit(BTNode *p) {
    printf(p->data);
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