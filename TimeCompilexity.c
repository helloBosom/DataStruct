#include <stdio.h>

int func(int n) {
    int i = 0, sum = 0;
    while (sum < n)
        sum += ++i;
    return i;
}

int f1(unsigned n) {
    int sum = 1, power = 1;
    for (unsigned i = 0; i <= n - 1; i++) {
        power *= 2;
        sum += power;
    }
    return sum;
}

typedef struct BTree {
    int data;
    struct BTree *left;
    struct BTree *right;
} BTree;

void BtreeToE(BTree *root) {
    BtreeToExp(root, 1);    //根的高度为 1
}

void BtreeToExp(BTree *root, int deep) {
    if (root == NULL) return;
        //空结点返回
    else if (root->left == NULL && root->right == NULL)   //若为叶结点
        printf("%s", root->data); //输出操作数，不加括号
    else {
        if (deep > 1) printf("(");  //若有子表达式则加1层括号
        BtreeToExp(root->left, deep + 1);
        printf("%s", root->data); //输出操作符
        BtreeToExp(root->right, deep + 1);
        if (deep > 1) printf("(");  //若有子表达式则加1层括号
    }
}