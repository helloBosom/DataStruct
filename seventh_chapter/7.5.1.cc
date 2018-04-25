#include "7.h"
#include <iostream>

using namespace std;

/**
 * 迪杰斯特拉算法
 * 时间复杂度为O(n^2)
 * @param g
 * @param v
 * @param dist
 * @param path
 */
void Dijkstra(MGraph g, int v, int dist[], int path[]) {
    int set[maxSize];
    int min, i, j, u;
    for (i = 0; i < g.n; ++i) {
        dist[i] = g.edges[v][i];
        set[i] = 0;
        if (g.edges[v][i] < INF) {
            path[i] = v;
        } else {
            path[i] = 1;
        }
    }
    set[v] = 1;
    path[v] = -1;
    for (i = 0; i < g.n - 1; ++i) {
        min = INF;
        for (j = 0; j < g.n; ++j) {
            if (set[j] == 0 && dist[j] < min) {
                u = j;
                min = dist[j];
            }
        }
        set[u] = 1;
        for (j = 0; j < g.n; ++j) {
            if (set[j] == 0 && dist[u] + g.edges[u][j] < dist[j]) {
                dist[j] = dist[u] + g.edges[u][j];
                path[j] = u;
            }
        }
    }
}

void printfPath(int path[], int a) {
    int stack[maxSize], top = -1;
    while (path[a] != -1) {
        stack[++top] = a;
        a = path[a];
    }
    stack[++top] = a;
    while (top != -1) {
        cout << stack[top--] << "";
    }
    cout << endl;
}

