/**
 * 邻接矩阵
 */
typedef struct {
    int no;
    char info;
} VertexType;

/**
 * 图
 */
#define maxSize 100
typedef struct {
    int edges[maxSize][maxSize];
    int n, e;
    VertexType vertexType[maxSize];
} MGraph;