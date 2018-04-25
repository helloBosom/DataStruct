#ifndef DATASTRUCT_7_H
#define maxSize 100
#define INF 1000000000

typedef struct {
    int no;
    char info;
} VertexType;

typedef struct {
    int edges[maxSize][maxSize];
    int n, e;
    VertexType vertexType[maxSize];
} MGraph;

#endif
