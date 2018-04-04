#include <iostream>

using namespace std;
#define maxSize 50

/**
 * 矩阵三元组表示法
 * trimat[0][0],trimat[0][1],trimat[0][2]分别用来存储非零元素个数、行数和列数
 */
typedef struct {
    int val;
    int i, j;
} Trimat;

/**
 * 矩阵尺寸为m*n
 * 建立对应三元组
 * @param A
 * @param m
 * @param n
 * @param B
 */
void createTrimat(float A[][maxSize], int m, int n, float B[][3]) {
    int k = 1;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (A[i][j] != 0) {
                B[k][0] = A[i][j];
                B[k][1] = i;
                B[k][2] = j;
            }
        }
    }
    B[0][0] = k - 1;
    B[0][1] = m;
    B[0][2] = n;
}

/**
 * 输出
 * @param B
 */
void print(float B[][3]) {
    int k = 1;
    for (int i = 0; i < B[0][1]; ++i) {
        for (int j = 0; j < B[0][2]; ++j) {
            if (i == B[k][1] && j == B[k][2]) {
                cout << B[k][0] << " ";
                ++k;
            } else {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}

/**
 * 十字链表中普通节点
 */
typedef struct OLNode {
    int row, col;
    struct OLNode *right, *down;
    float val;
} OLNode;

/**
 * 十字链表头节点
 */
typedef struct {
    OLNode *rhead, *chead;
    int m, n, k;
} CrossList;

/**
 * 稀疏矩阵，尺寸m*n,非零元素k个
 * 建立对应的十字链表
 * @param A
 * @param m
 * @param n
 * @param k
 * @param M
 * @return
 */
int createCrossListMat(float A[][maxSize], int m, int n, int k, CrossList &M) {
    if (M.rhead)
        free(M.rhead);
    if (M.chead)
        free(M.chead);
    M.m = m;
    M.n = n;
    M.k = k;
    if (!(M.rhead = (OLNode *) malloc(sizeof(OLNode) * m)))
        return 0;
    if (!M.chead = (OLNode *) malloc(sizeof(OLNode) * n))
        return 0;
    for (int i = 0; i < m; ++i) {
        M.rhead[i].right = NULL;
        M.chead[i].down = NULL;
    }
    for (int j = 0; j < n; ++j) {
        M.rhead[j].right = NULL;
        M.chead[j].down = NULL;
    }
    OLNode *temp_r[maxSize];
    for (int l = 0; l < n; ++l) {
        temp_r[l] = &(M.chead[l]);
    }
    for (int i = 0; i < m; ++i) {
        OLNode *c = &(M.rhead[i]);
        for (int j = 0; j < n; ++j) {
            if (A[i][j] != 0) {
                OLNode *p = (OLNode *) malloc(sizeof(OLNode));
                p->row = i;
                p->col = j;
                p->val = A[i][j];
                p->down = NULL;
                p->right = NULL;
                c->right = p;
                c = p;
                temp_r[j]->down = p;
                temp_r[j] = p;
            }
        }
    }
    return 1;
}