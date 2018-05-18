/**
 * 调整堆
 * @param R
 * @param i
 * @param n
 */
void sift(int R[], int low, int high) {
    int i = low, j = 2 * i;
    int temp = R[i];
    while (j <= high) {
        if (j < high && R[j] < R[j + 1]) {
            ++j;
        }
        if (temp < R[j]) {
            R[i] = R[j];
            i = j;
            j = 2 * i;
        } else {
            break;
        }
    }
    R[i] = temp;
}

/**
 * 堆排序
 * 时间复杂度：O(n㏒₂n)
 * 空间复杂度：O(1)
 * 适用于关键字数很多的情况
 * @param R
 * @param n
 */
void heapSort(int R[], int n) {
    int i;
    int temp;
    for (i = n / 2; i >= 1; --i) {
        sift(R, i, n);
    }
    for (i = n; i >= 2; --i) {
        temp = R[1];
        R[1] = R[i];
        R[i] = temp;
        sift(R, 1, i - 1);
    }
}