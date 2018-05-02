#include <stdio.h>

typedef struct {
    int a;
    char b;
    float c;
} TypeA;

/**
 * 链表
 */
typedef struct Node {
    int data;
    struct Node *next;
} Node;

/**
 * 二叉树
*/
typedef struct BTNode {
    int data;
    struct BTNode *lchild;
    struct BTNode *rchild;
} BTNode;

int a;
int maxSize;

void f(int x) {
    ++x;
    printf("x" + x);
}

/**
 *
 * @param x
 * @param n 将要传入函数加工的数组元素的个数，并不是数组总长度
 */
void fo(int x[], int n) {

}

/**
 *
 * @param x maxSize 为必须。  所传入的数组第二维长度也得是maxSize
 * @param n
 */
void foo(int x[][maxSize], int n) {

}

int main() {
    f(a);
    /**
     * 此处a值为0，调用f(a)只是把a的值赋给x，执行完a值不变
     */
    printf("a" + a);//0
}



