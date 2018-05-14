#include <clocale>
#include <cstdlib>

typedef struct BTNode {
    int key;
    struct BTNode *lchild;
    struct BTNode *rchild;
} BTNode;

/**
 * 二叉排序树查找关键字
 * @param btNode
 * @param key
 * @return
 */
BTNode *BSTSearch(BTNode *btNode, int key) {
    if (btNode == NULL) {
        return NULL;
    } else {
        if (btNode->key == key) {
            return btNode;
        } else if (key < btNode->key) {
            return BSTSearch(btNode->lchild, key);
        } else {
            return BSTSearch(btNode->rchild, key);
        }
    }
}

/**
 * 二叉排序树上插入关键字
 * @param btNode
 * @param key
 * @return
 */
int BSTInsert(BTNode *&btNode, int key) {
    if (btNode == NULL) {
        btNode = (BTNode *) malloc(sizeof(BTNode));
        btNode->lchild = btNode->rchild = NULL;
        btNode->key = key;
        return 1;
    } else {
        if (key == btNode->key) {
            return 0;
        } else if (key < btNode->key) {
            return BSTInsert(btNode->lchild, key);
        } else {
            return BSTInsert(btNode->rchild, key);
        }
    }
}

/**
 * 构造二叉排序树
 * @param btNode
 * @param key
 * @param n
 */
void CreateBST(BTNode *&btNode, int key[], int n) {
    btNode = NULL;
    for (int j = 0; j < n; ++j) {
        BSTInsert(btNode, key[j]);
    }
}
