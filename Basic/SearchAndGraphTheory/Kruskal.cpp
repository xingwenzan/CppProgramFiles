//
// Created by 86159 on 2023-10-16.
// Kruskal算法求最小生成树 https://www.acwing.com/problem/content/861/
//
#include "iostream"
#include "algorithm"

using namespace std;

#define N 100010
#define M 200010
#define INF 0x3f3f3f3f

struct Edge {
    int a, b, w;

    bool operator<(const Edge &W) const {
        return w < W.w;
    }
} edges[M];

int n, m;
int father[N];

void init() {
    for (int i = 0; i < N; ++i) {
        father[i] = i;
    }
}

int find(int x) {
    if (father[x] != x)father[x] = find(father[x]);
    return father[x];
}

int kruskal() {
    sort(edges, edges + m);
    int ans = 0, cnt = 0;
    for (int i = 0; i < m; ++i) {
        int fa = find(edges[i].a), fb = find(edges[i].b), w = edges[i].w;
        if (fa != fb) {
            father[fa] = fb;
            ans += w;
            cnt++;
        }
    }
    if (cnt < n - 1)return INF;
    return ans;
}

int main() {
    init();
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].a >> edges[i].b >> edges[i].w;
    }
    int ans = kruskal();
    if (ans == INF)puts("impossible");
    else cout << ans << endl;
}