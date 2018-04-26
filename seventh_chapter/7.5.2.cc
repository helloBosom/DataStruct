#include "7.h"

/**
 * 弗洛伊德算法
 * 时间复杂度:O(n^3)
 * @param g
 * @param path
 */
void Floyd(MGraph g, int path[][maxSize]) {
    int i, j, k;
    int A[maxSize][maxSize];
    for (i = 0; i < g.n; ++i) {
        for (j = 0; j < g.n; ++j) {
            A[i][j] = g.edges[i][j];
            path[i][j] = -1;
        }
    }
    for (k = 0; k < g.n; ++k) {
        for (i = 0; i < g.n; ++i) {
            for (j = 0; j < g.n; ++j) {
                if (A[i][j] > A[i][k] + A[k][j]) {
                    A[i][j] = A[i][k] + A[k][j];
                    path[i][j] = k;
                }
            }
        }
    }
}

#define max 1

void printPath(int u, int v, int path[][max]) {
    if (path[u][v] == -1) {
        //printf();
    } else {
        int mid = path[u][v];
        printPath(u, mid, path);
        printPath(mid, v, path);
    }
}