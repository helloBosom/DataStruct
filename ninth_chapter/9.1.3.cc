/**
 * 折半查找
 * @param R
 * @param low
 * @param high
 * @param k
 * @return
 */
int midSearch(int R[], int low, int high, int k) {
    int mid;
    while (low < high) {
        mid = (low + high) / 2;
        if (R[mid] == k) {
            return mid;
        } else if (R[mid] < k) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
}