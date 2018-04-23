#include <clocale>

#define maxSize 100

typedef struct ArcNode {
    int adjVex;
    struct ArcNode *nextArc;
} ArcNode;

typedef struct {
    ArcNode *firstArc;
    char data;
} VNode;

typedef struct {
    VNode *adjList[maxSize];
    int n, e;
} AGraph;

void Visit(int i);

/**
 * 广度优先
 * @param G
 * @param v
 * @param visit
 */
void BFS(AGraph *G, int v, int visit[maxSize]) {
    ArcNode *p;
    int que[maxSize], front = 0, rear = 0;
    int j;
    Visit(v);
    visit[v] = 1;
    rear = (rear + 1) % maxSize;
    que[rear] = v;
    while (front != rear) {
        front = (front + 1) % maxSize;
        j = que[front];
        p = G->adjList[j]->firstArc;
        while (p != NULL) {
            if (visit[p->adjVex == 0]) {
                Visit(p->adjVex);
                visit[p->adjVex] = 1;
                rear = (rear + 1) % maxSize;
                que[rear] = p->adjVex;
            }
            p = p->nextArc;
        }
    }
}

void Visit(int i) {

}

