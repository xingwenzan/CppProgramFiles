//
// Created by 86159 on 2023-10-19.
// 染色法判定二分图 https://www.acwing.com/problem/content/862/
//

#include "iostream"
#include "cstring"

using namespace std;

#define N 100010
#define M 200010

int n, m;
int h[N], e[M], ne[M], idx = 0;
int c[N];
int q[N];

void add1(int st, int ed) {
    e[idx] = ed;
    ne[idx] = h[st];
    h[st] = idx++;
}

void add2(int p1, int p2) {
    add1(p1, p2);
    add1(p2, p1);
}

bool bfs(int st) {
    q[0] = st;
    c[st] = 1;
    int hh = 0, tt = 0;
    while (hh <= tt) {
        int fa = q[hh++];
        for (int i = h[fa]; i != -1; i = ne[i]) {
            int son = e[i];
            if (c[son] == 0) {
                q[++tt] = son;
                c[son] = -c[fa];
            }
            if (c[son] == c[fa]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    memset(h, -1, sizeof h);
    memset(c, 0, sizeof c);
    cin >> n >> m;
    int a, b;
    while (m--) {
        cin >> a >> b;
        add2(a, b);
    }
    bool ans = true;
    for (int i = 1; i <= n; ++i) {
        if (c[i] == 0) {
            if (!bfs(i)) {
                ans = false;
                break;
            }
        }
    }
    if (ans)puts("Yes");
    else puts("No");
}