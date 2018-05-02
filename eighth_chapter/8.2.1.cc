/**
 * 直接插入排序，默认不降序
 * 时间复杂度:O(n^2)
 * 空间复杂度:O(1)
 * @param R
 * @param n
 */
void insertSort(int R[], int n) {
    int i, j;
    int temp;
    for (i = 1; i < n; ++i) {
        temp = R[i];
        j = i - 1;
        while (j > 0 && temp < R[j]) {
            R[j + 1] = R[j];
            --j;
        }
        R[j + 1] = temp;
    }
}