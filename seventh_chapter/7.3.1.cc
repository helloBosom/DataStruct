#include <clocale>

#define maxSize
int visit[maxSize];

void Visit(int v) {

};

typedef struct ArcNode {
    int adjVex;
    struct ArcNode *nextArc;
    int info;
} ArcNode;

typedef struct {
    char data;
    ArcNode *firstArc;
} VNode;

typedef struct {
    VNode adjList[maxSize];
    int n, e;
} AGraph;

/**
 * 深度优先
 * @param G
 * @param v
 */
void DFS(AGraph *G, int v) {
    ArcNode *p;
    visit[v] = 1;
    Visit(v);
    p = G->adjList[v].firstArc;
    while (p != NULL) {
        if (visit[p->adjVex] == 0) {
            DFS(G, p->adjVex);
        }
        p = p->nextArc;
    }
}