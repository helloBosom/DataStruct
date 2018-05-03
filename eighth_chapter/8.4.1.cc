/**
 * 简单选择排序
 * 时间复杂度:O(n^2)
 * 空间复杂度:O(1)
 * @param R
 * @param n
 */
void selectSort(int R[], int n) {
    int i, j, k;
    int temp;
    for (i = 0; i < n; ++i) {
        k = i;
        for (j = i + 1; j < n; ++j) {
            if (R[k] < R[j]) {
                k = j;
            }
        }
        temp = R[i];
        R[i] = R[k];
        R[k] = temp;
    }
}