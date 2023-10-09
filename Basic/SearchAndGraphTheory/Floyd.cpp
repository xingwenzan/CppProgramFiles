//
// Created by 86159 on 2023-10-09.
// Floyd求最短路 https://www.acwing.com/problem/content/856/
//
#include "iostream"

using namespace std;

#define N 210
#define INF 0x3f3f3f3f

int n, m, k;
int f[N][N];

void floyd() {
    for (int t = 1; t <= n; ++t) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                f[i][j] = min(f[i][j], f[i][t] + f[t][j]);
            }
        }
    }
}

int main() {
    cin >> n >> m >> k;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            f[i][j] = i == j ? 0 : INF;
        }
    }

    int a, b, c;
    while (m--) {
        cin >> a >> b >> c;
        f[a][b] = min(f[a][b], c);
    }

    floyd();

    while (k--) {
        cin >> a >> b;
        c = f[a][b];
        if (c > INF / 2)puts("impossible");
        else cout << c << endl;
    }
    return 0;
}