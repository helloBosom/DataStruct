#include <cstdlib>

#define maxSize 100
typedef struct {
    char str[maxSize + 1];     //以'\0'作为结束标识符
    int length;
} Str;

/**
 * 动态分配存储
 * 需用malloc()函数分配空间
 */
typedef struct {
    char *ch;     //指向动态分配存储区首地址的字符指针
    int length;
} Str;

/**
 * 赋值
 */
int strAssign(Str &str, char *ch) {
    if (str.ch)
        free(str.ch);
    int len = 0;
    char *c = ch;
    while (*c) {   //求字符串长度
        ++len;
        ++c;
    }
    if (len == 0) {
        str.ch = NULL;
        str.length = 0;
        return 0;
    } else {
        str.ch = (char *) malloc(sizeof(char) * (len + 1));
        if (str.ch == NULL)
            return 0;
        else {
            c = ch;
            for (int i = 0; i <= len; ++i, ++c) {
                str.ch[i] = *c;
            }
            str.length = len;
            return 1;
        }
    }
}

int strLength(Str str) {
    return str.length;
}

/**
 * 比较串
 */
int strCompare(Str s1, Str s2) {
    for (int i = 0; i < s1.length && i < s2.length; ++i) {
        if (s1.ch[i] != s2.ch[i])
            return s1.ch[i] - s2.ch[i];
        return s1.length - s2.length;
    }
}

/**
 * 合并两个串
 * @param str
 * @param str1
 * @param str2
 * @return
 */
int concat(Str &str, Str str1, Str str2) {
    if (str.ch) {
        free(str.ch);
        str.ch = NULL;
    }
    str.ch = static_cast<char *>(malloc(sizeof(char) * (str1.length + str2.length + 1)));
    if (str.ch == NULL)
        return 0;
    int i = 0;
    while (i < str1.length) {
        str.ch[i] = str1.ch[i];
        ++i;
    }
    int j = 0;
    while (j < str2.length) {
        str.ch[i + j] = str2.ch[j];
        ++j;
    }
    str.length = str1.length + str2.length;
    return 1;
}

/**
 * 求子串
 * @param subStr
 * @param str
 * @param pos
 * @param len
 * @return
 */
int subString(Str &subStr, Str str, int pos, int len) {
    if (pos < 0 || pos >= str.length || len > str.length - pos) {
        return 0;
    }
    if (subStr.ch) {
        free(subStr.ch);
        subStr.ch = NULL;
    }
    if (len == 0) {
        subStr.ch = NULL;
        subStr.length = 0;
        return 1;
    } else {
        subStr.ch = (char *) malloc(sizeof(char) * len + 1);
        int i = pos;
        int j = 0;
        while (i < pos + len) {
            subStr.ch[j] = str.ch[i];
            ++i;
            ++j;
        }
        subStr.ch[j] = '\0';
        subStr.length = len;
        return 1;
    }
}

/**
 * 清空串
 * @param str
 * @return
 */
int clearStr(Str &str) {
    if (str.ch) {
        free(str.ch);
        str.ch = NULL;
    }
    str.length = 0;
    return 1;
}