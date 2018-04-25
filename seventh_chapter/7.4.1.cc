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

/**
 * 普利姆算法
 * 时间复杂度为:O(n^2)
 * @param g
 * @param v0
 * @param sum
 */
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

typedef struct {
    int a, b;    //一条边的两个顶点
    int w;       //边的权值
} Road;

Road road[maxSize];
int v[maxSize];   //并查集数组

void sort(Road *road, int e);

int getRoot(int a) {
    while (a != v[a]) {
        a = v[a];
        return a;
    }
}

/**
 * 克鲁斯卡尔算法
 * @param g
 * @param sum
 * @param road
 */
void Kruskal(MGraph g, int &sum, Road road[]) {
    int i;
    int N, E, a, b;
    N = g.n;
    E = g.e;
    sum = 0;
    for (i = 0; i < N; ++i) {
        v[i] = i;
        sort(road, E);
    }
    for (i = 0; i < E; ++i) {
        a = getRoot(road[i].a);
        b = getRoot(road[i].b);
        if (a != b) {
            v[a] = b;
            sum += road[i].w;
        }
    }
}

void sort(Road *road, int e) {

}