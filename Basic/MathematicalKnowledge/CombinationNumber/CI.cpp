//
// Created by 86159 on 2024-01-18.
// 求组合数 I
// https://www.acwing.com/problem/content/887/
//
#include "iostream"

using namespace std;

#define N 2010
const int MOD = 1e9 + 7;
int c[N][N], n;

void init() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (!j)c[i][j] = 1;
            else c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
        }
    }
}

int main() {
    init();
    cin >> n;
    int a, b;
    while (n--) {
        cin >> a >> b;
        cout << c[a][b] << endl;
    }
    return 0;
}