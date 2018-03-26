#include <iostream>

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

