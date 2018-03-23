/**
 * KMP算法改进
 */
typedef struct {
    char *ch;
    int length;
} Str;

void getNextVal(Str subStr, int nextVal[]) {
    int i = 1, j = 0;
    nextVal[1] = 0;
    while (i < subStr.length) {
        if (j == 0 || subStr.ch[i] == subStr.ch[j]) {
            ++i;
            ++j;
            if (subStr.ch[i] != subStr.ch[j])
                nextVal[i] = j;
            else
                nextVal[i] = nextVal[j];
        } else
            j = nextVal[j];
    }
}