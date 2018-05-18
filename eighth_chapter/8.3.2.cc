/**
 * 快速排序
 * 时间复杂度:最好:O(n㏒₂n)，最坏:O(n^2)，平均:O(n㏒₂n)
 * 空间复杂度:O(㏒₂n)
 * @param R
 * @param low
 * @param high
 */
void quickSort(int R[], int low, int high) {
    int temp;
    int i = low, j = high;
    if (low < high) {
        temp = R[low];
        while (i < j) {
            while (j > i && R[j] >= temp) {
                --j;
                if (i < j) {
                    R[i] = R[j];
                    ++i;
                }
            }
            while (i < j && R[i] < temp) {
                ++i;
                if (i < j) {
                    R[j] = R[i];
                    --j;
                }
            }
        }
        R[i] = temp;
        quickSort(R, low, i - 1);
        quickSort(R, i + 1, high);
    }
}