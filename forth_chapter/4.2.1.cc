/**
 * 简单匹配算法
 */
typedef struct {
    char *ch;
    int length;
} Str;

int index(Str str, Str subStr) {
    int i = 1, j = 1, k = 1;
    //
    while (i <= str.length && j <= subStr.length) {
        if (str.ch[i] == subStr.ch[j]) {
            ++i;
            ++j;
        } else {
            j = 1;
            i = ++k;
        }
    }
    if (j > subStr.length)
        return k;
    else
        return 0;
}