#include <iostream>
/**
 * 设将n（n>1）个整数存放到一维数组R中，设计一个算法，将R中的序列循环左移P（0<P<n）个位置，
 * 即将R中的数据由{X0,X1,...Xn-1}变换为{Xp,Xp+1,...,Xn-1,X0,X1...Xp-1}
 */
#define N 50
using namespace std;

void Reverse(int R[], int l, int r) {
    int i, j;
    int temp;
    for (i = 0, j = r; i < j; ++i, --j) {
        temp = R[i];
        R[i] = R[j];
        R[j] = temp;
    }
}

void RCR(int R[], int n, int p) {
    if (p < 0 || p > n) {
        cout << "" << endl;
    } else {
        Reverse(R, 0, p - 1);
        Reverse(R, p, n - 1);
        Reverse(R, 0, n - 1);
    }
    int main() {
        int L, i;
        int R[N], n;
        cin >> L;
        cin >> n;
        for (i = 0; i < n - 1; ++i) {
            cin >> R[i];
        }
        RCR(R, n, L);
        for (i = 0; i < n - 1; ++i) {
            cout << R[i] << " ";
        }
        cout << endl;
        return 0;
    }
}
