/**
 * 顺序查找
 * 时间复杂度：O(n)
 * @param a
 * @param n
 * @param k
 * @return
 */
int search(int a[], int n, int k) {
    int i;
    for (i = 1; i <= n; ++i) {
        if (a[i] == k) {
            return i;
        }
    }
    return 0;
}

