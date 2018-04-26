#include <iostream>

using namespace std;
#define maxSize 100

typedef struct ArcNode {
    int adjVex;
    struct ArcNode *nextArc;
} ArcNode;

typedef struct {
    char data;
    int count;
    ArcNode *firstArc;
} VNode;

typedef struct {
    int n, e;
    VNode adjList[maxSize];
} AGraph;

/**
 * 拓扑排序
 * @param g
 * @return
 */
int topSort(AGraph *g) {
    int i, j, n = 0;
    int stack[maxSize], top = -1;
    ArcNode *p;
    for (i = 0; i < g->n; ++i) {
        if (g->adjList[i].count == 0) {
            stack[++top] = i;
        }
    }
    while (top != -1) {
        i = stack[top--];
        ++n;
        cout << i << " ";
        p = g->adjList[i].firstArc;
        while (p != NULL) {
            j = p->adjVex;
            --(g->adjList[j].count);
            if (g->adjList[j].count == 0) {
                stack[++top] = j;
            }
            p = p->nextArc;
        }
    }
    if (n == g->n) {
        return 1;
    } else {
        return 0;
    }
}