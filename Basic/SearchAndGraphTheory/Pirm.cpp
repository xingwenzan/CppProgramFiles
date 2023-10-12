//
// Created by 86159 on 2023-10-12.
// Prim算法求最小生成树 https://www.acwing.com/problem/content/860/
//
#include "iostream"
#include "cstring"

using namespace std;

#define N 510
#define INF 0x3f3f3f3f

int n, m;
int f[N][N];
int d[N];
bool st[N];

void init() {
    memset(f, INF, sizeof f);
    memset(d, INF, sizeof d);
    memset(st, false, sizeof st);
}

void add(int u, int v, int w) {
    f[u][v] = f[v][u] = min(f[u][v], w);
}

int prim() {
    d[1] = 0;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int start = -1;
        for (int j = 1; j <= n; ++j) {
            if (!st[j] && (start == -1 || d[j] < d[start]))start = j;
        }
        if (d[start] == INF)return INF;
        st[start] = true;
        ans += d[start];
        for (int j = 1; j <= n; ++j) {
            d[j] = min(d[j], f[start][j]);
        }
    }
    return ans;
}

int main() {
    init();
    cin >> n >> m;
    int a, b, c;
    while (m--) {
        cin >> a >> b >> c;
        add(a, b, c);
    }

    int ans = prim();
    if (ans == INF)puts("impossible");
    else cout << ans << endl;
}