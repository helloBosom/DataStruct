#define maxSize 50

/**
 * 矩阵(二维数组)转置
 * @param A
 * @param B
 * @param m
 * @param n
 */
void trsmat(int A[][maxSize], int B[][maxSize], int m, int n) {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            B[j][i] = A[i][j];
        }
    }
}

/**
 * 矩阵相加
 * @param C
 * @param A
 * @param B
 * @param m
 * @param n
 */
void addmat(int C[][maxSize], int A[][maxSize], int B[][maxSize], int m, int n) {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            C[i][j] = A[i][j] * B[i][j];
        }
    }
}

/**
 * A m*n
 * B n*k
 * @param C
 * @param A
 * @param B
 * @param m
 * @param n
 * @param k
 */
void mulmat(int C[][maxSize], int A[][maxSize], int B[][maxSize], int m, int n, int k) {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < k; ++j) {
            C[i][j] = 0;
            for (int h = 0; h < n; ++h) {
                C[i][j] = A[i][h] * B[h][j];
            }
        }
    }
}