#include <clocale>
#include <cstdlib>

void f(int *&x) {
    ++x;
}

typedef struct Sqlist {
    int data[];
    int length;

} Sqlist;

int LocateElem(Sqlist &sqlist, int x);

void insert(Sqlist &L, int x) {
    int p, i;
    p = LocateElem(L, x);
    for (
            i = L.length - 1;
            i >=
                    p;
            --i) {
        L.data[i + 1] = L.data[i];
    }
    L.data[p] =
            x;
    ++(L.length);
}

int LocateElem(Sqlist &sqlist, int x) {
    return 0;
}


typedef struct LNode {
    int data;
    struct LNode *next;
} LNode;

int SearchAndDelete(LNode *C, int x) {
    LNode *p, *q;
    p = C;
    while (p->next != NULL) {
        if (p->next->data == x) {
            break;
        }
        p = p->next;
    }
    if (p->next == NULL)
        return 0;
    else {
        q = p->next;
        p->next = p->next->next;
        free(q);
        return 1;
    }

}

void merge(LNode *A, LNode *B, LNode *&C) {

}

