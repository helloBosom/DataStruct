/**
 * KMP算法
 */
typedef struct {
    char *ch;
    int length;
} Str;

void getNext(Str subStr, int next[]) {
    int i = 1, j = 0;
    next[1] = 0;
    while (i < subStr.length) {
        if (j == 0 || subStr.ch[i] == subStr.ch[j]) {
            ++i;
            ++j;
            next[i] = j;
        } else
            j = next[j];
    }
}

int KMP(Str str, Str subStr, int next[]) {
    int i = 1, j = 1;
    while (i <= str.length && j < subStr.length) {
        if (str.ch[i] == subStr.ch[j] || j == 0) {
            ++i;
            ++j;
        } else {
            j = next[j];
        }
    }
    if (j > subStr.length)
        return i - subStr.length;
    else
        return 0;
}