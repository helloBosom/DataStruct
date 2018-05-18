void merge(int R[], int low, int mid, int high);

/**
 * 二路归并排序
 * 时间复杂度：O(n㏒₂n)
 * 空间复杂度：O(n)
 * @param R
 * @param low
 * @param high
 */
void mergeSort(int R[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergeSort(R, low, mid);
        mergeSort(R, mid + 1, high);
        merge(R, low, mid, high);
    }
}