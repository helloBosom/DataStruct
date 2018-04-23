/**
 * 邻接表
 */
typedef struct ArcNode {
    int adjvex;
    struct ArcNode *nextarc;
    int info;
} ArcNode;

typedef struct {
    char data;
    ArcNode *firstArc;
} VNode;

#define maxSize 100

typedef struct {
    VNode adjList[maxSize];
    int n, e;
} AGraph;