#include <malloc.h>

//结构体
typedef struct BTNode {
    int data;
    struct BTNode *lchild;
    struct BTNOde *rchild;
} BTNode;

//BTNode BT;
BTNode *BT;
BT = (BTNode*) malloc(sizeof(BTNode));

int *p;
int n;
//sizeof是个运算符
p = (int *) malloc(n * sizeof(int));
