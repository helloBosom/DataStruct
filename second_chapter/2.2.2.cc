#define maxSize 100

typedef struct {
    int data[maxSize];
    int length;
} Sqlist;

int Error;

int findElem(Sqlist L, int x) {
    int i;
    for (i = 0; i < L.length; ++i) {
        if (x < L.data[i]) {
            return i;
        }
    }
    return -1;
}

int insertElem(Sqlist &L, int x) {
    int p;
    p = findElem(L, x);
    if (p < 0 || p > L.length || L.length == maxSize) {
        return 0;
    }
    for (int i = L.length - 1; i > p; --i) {
        L.data[i + 1] = L.data[i];
    }
    L.data[p] = x;
    ++L.length;
    return -1;
}

int deleteElem(Sqlist &L, int p, int &e) {
    if (p < 0 || p > L.length - 1)
        return -1;
    e = L.data[p];
    for (int i = p; i < L.length; ++i) {
        L.data[i] = L.data[i + 1];
    }
    --L.length;
    return 1;
}

void initList(Sqlist &L) {
    L.length = 0;
}

int findElem(Sqlist L, int p, int &e) {
    if (p < 0 || p > L.length - 1)
        return Error;
    e = L.data[p];
    return e;
}