//
// Created by 86159 on 2023-03-26.
// 第k个数 https://www.acwing.com/problem/content/description/788/
//

using namespace std;

#include <iostream>

#define N 100010

int n, k, q[N];

int quickChange(int l, int r, int k) {
    if (l >= r) {
        return q[l];
    }
    int i = l - 1, j = r + 1, x = q[(l + r + 1) >> 1];
    while (i < j) {
        while (q[++i] < x) {}
        while (q[--j] > x) {}
        if (i < j) {
            swap(q[i], q[j]);
        }
    }
    if (k <= i - l) {
        return quickChange(l, i - 1, k);
    } else {
        return quickChange(i, r, k - (i - l));
    }
}

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &q[i]);
    }
    cout << quickChange(0, n - 1, k) << endl;
}