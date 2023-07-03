//
// Created by 86159 on 2023-07-03.
// 树与图的广度优先遍历 图中点的层次 https://www.acwing.com/problem/content/849/
//

#include "iostream"
#include "cstring"
#include "queue"

using namespace std;
const int N = (int) 1e5 + 10;

int d[N];
int n;
int h[N], e[N], p[N], idx = 0;
queue<int> q;

void add(int father, int son) {
    e[idx] = son, p[idx] = h[father], h[father] = idx++;
}

int bfs() {
    d[1] = 0;
    q.push(1);

    while (q.size()) {
        int father = q.front();
        q.pop();

        for (int i = h[father]; i != -1; i = p[i]) {
            int son = e[i];
            if (d[son] == -1) {
                d[son] = d[father] + 1;
                q.push(son);
            }
        }
    }

    return d[n];
}

int main() {
    memset(d, -1, sizeof d);
    memset(h, -1, sizeof h);
    int m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        add(a, b);
    }
    cout << bfs() << endl;
    return 0;
}