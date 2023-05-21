//
// Created by 86159 on 2023-04-08.
// 差分 https://www.acwing.com/problem/content/799/
//

#include "iostream"

using namespace std;
const int N = (int) 1e5 + 10;

int a[N], b[N];

void difference(int l, int r, int c) {
    b[l] += c;
    b[r + 1] -= c;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        difference(i, i, a[i]);
    }
    int l, r, c;
    for (int i = 0; i < m; ++i) {
        cin >> l >> r >> c;
        difference(l, r, c);
    }
    for (int i = 1; i <= n; ++i) {
        b[i] += b[i - 1];
        cout << b[i] << ' ';
    }
}