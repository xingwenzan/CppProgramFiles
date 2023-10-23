//
// Created by 86159 on 2023-10-23.
// 二分图的最大匹配 https://www.acwing.com/problem/content/863/
//

#include "iostream"
#include "cstring"

#define N 510
#define M 100010

using namespace std;

int n1, n2, m;
int h[N], e[M], ne[M], idx = 0;
int match[N];   // 女匹配的男
bool st[N];   // 女是否被询问

void init() {
    memset(h, -1, sizeof h);
    memset(match, 0, sizeof match);
}

void add(int x, int y) {
    e[idx] = y;
    ne[idx] = h[x];
    h[x] = idx++;
}

bool find(int x) {
    for (int i = h[x]; i != -1; i = ne[i]) {
        int y = e[i];
        if (st[y])continue;
        st[y] = true;
        if (match[y] == 0 || find(match[y])) {
            match[y] = x;
            return true;
        }
    }
    return false;
}

int main() {
    init();
    cin >> n1 >> n2 >> m;
    int a, b;
    while (m--) {
        cin >> a >> b;
        add(a, b);
    }
    int ans = 0;
    for (int i = 1; i <= n1; ++i) {
        memset(st, false, sizeof st);
        if (find(i))ans++;
    }
    cout << ans << endl;
    return 0;
}