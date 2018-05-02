/**
 * 冒泡排序，默认不降序
 * 时间复杂度:O(n^2)
 * 空间复杂度:O(1)
 * @param R
 * @param n
 */
void bubbleSort(int R[], int n) {
    int temp, flag;
    for (int i = n - 1; i >= 1; --i) {
        flag = 0;
        for (int j = 1; j <= i; ++j) {
            if (R[j - 1] > R[j]) {
                temp = R[j];
                R[j] = R[j - 1];
                R[j - 1] = temp;
                flag = 1;
            }
        }
        if (flag == 0) {
            return;
        }
    }
}