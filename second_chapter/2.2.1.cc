#include <malloc.h>

#define maxSize 100

/**
 * 定义顺序表方式一
 */
typedef struct {
    int data[maxSize];
    int length;
} Sqlist;

/**
 * 定义顺序表方式二
 */
int A[maxSize];
int n;

/**
 * 定义单链表
 */
typedef struct LNode {
    int data;
    struct LNode *next;
} LNode; //节点类型

//AT同时命名了结点和指向结点的指针
LNode *AT = (LNode *) malloc(sizeof(LNode));

/**
 * 定义双链表
 */
typedef struct DLNode {
    int data;
    struct DLNode *prior;
    struct DLNode *next;
} DLNode;
