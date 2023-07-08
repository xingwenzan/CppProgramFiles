//
// Created by 86159 on 2023-07-08.
// Dijkstra求最短路 II https://www.acwing.com/problem/content/852/
// 堆优化
//

#include "iostream"
#include "cstring"
#include "queue"

using namespace std;

typedef pair<int, int> PII;

const int INF = 0x3f3f3f3f;
const int N = 150010;

int h[N], e[N], p[N], w[N], idx = 0;
int d[N];
bool st[N];
priority_queue<PII, vector<PII>, greater<PII>> heap;

void init() {
    memset(h, -1, sizeof h);
    memset(e, 0, sizeof e);
    memset(p, 0, sizeof p);
    memset(w, INF, sizeof w);
    memset(d, INF, sizeof d);
    memset(st, false, sizeof st);
}

void add(int father, int son, int length) {
    e[idx] = son, w[idx] = length, p[idx] = h[father], h[father] = idx++;
}

int dijkstra(int n) {
    d[1] = 0;
    heap.push({d[1], 1});
    while (!heap.empty()) {
        auto father = heap.top();
        heap.pop();
        int f = father.second, fd = father.first;   // father's distance

        if (st[f]) { continue; }
        st[f] = true;

        for (int i = h[f]; i != -1; i = p[i]) {
            int son = e[i], f2s = w[i];   // father to son
            if (d[son] > fd + f2s) {
                d[son] = fd + f2s;
                heap.push({d[son], son});
            }
        }
    }
    return d[n] == INF ? -1 : d[n];
}

int main() {
    init();
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        add(x, y, z);
    }
    cout << dijkstra(n) << endl;
    return 0;
}