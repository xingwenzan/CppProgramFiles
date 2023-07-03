//
// Created by 86159 on 2023-06-30.
// 树与图的深度优先遍历 树的重心 https://www.acwing.com/problem/content/848/
//

#include "iostream"
#include "cstring"

using namespace std;

const int N = (int) 1e5 + 10, M = 2 * N;

bool st[N];
int h[N], e[M], p[M], idx = 0;
int ans = N, n;

void add(int a, int b) {
    e[idx] = a, p[idx] = h[b], h[b] = idx++;
    e[idx] = b, p[idx] = h[a], h[a] = idx++;
}

int dfs(int father) {
    st[father] = true;
    int size = 0, sum = 0;   // 以此点为重心时各连通块最大值   子树节点总数
    for (int i = h[father]; i != -1; i = p[i]) {
        int son = e[i];
        if (st[son]) { continue; }
        int s = dfs(son);
        size = max(size, s);
        sum += s;
    }
    size = max(size, n - sum - 1);
    ans = min(ans, size);
    return sum + 1;
}

int main() {
    memset(h, -1, sizeof h);
    memset(st, false, sizeof st);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        add(a, b);
    }
    dfs(1);
    cout << ans << endl;
    return 0;
}