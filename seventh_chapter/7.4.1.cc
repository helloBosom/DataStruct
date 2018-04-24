#define  INF 1000000000
#define maxSize 100

typedef struct {
    int no;
    char info;
} VertexType;

typedef struct {
    int edges[maxSize][maxSize];
    int n, e;
    VertexType vex[maxSize];
} MGraph;

void Prim(MGraph g, int v0, int &sum) {
    int lowCost[maxSize], vSet[maxSize], v;
    int i, j, k, min;
    v = v0;
    for (i = 0; i < g.n; ++i) {
        lowCost[i] = g.edges[v0][i];
        vSet[i] = 0;
    }
    vSet[v0] = 1;
    sum = 0;
    for (i = 0; i < g.n - 1; ++i) {
        min = INF;
        for (j = 0; j < g.n; ++j) {
            if (vSet[j] == 0 && lowCost[j] < min) {
                min = lowCost[j];
                k = j;
            }
        }
        vSet[k] = 1;
        v = k;
        sum += min;
        for (j = 0; j < g.n; ++j) {
            if (vSet[j] == 0 && g.edges[v][j] < lowCost[j]) {
                lowCost[j] = g.edges[v][j];
            }
        }
    }
}