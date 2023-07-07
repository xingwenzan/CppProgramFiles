//
// Created by 86159 on 2023-07-07.
// Dijkstra求最短路 I https://www.acwing.com/problem/content/851/
//

#include "iostream"
#include "cstring"

using namespace std;

const int N = 510;
const int INF = 0x3f3f3f3f;

int n, m;
int f[N][N], d[N];
bool st[N];

void init() {
    memset(st, false, sizeof st);
    memset(d, INF, sizeof d);
    memset(f, INF, sizeof f);
    d[1] = 0;
}

int dijkstra() {
    for (int i = 0; i < n; ++i) {
        int start = -1;
        for (int j = 1; j <= n; ++j) {
            if (!st[j] && (start == -1 || d[j] < d[start])) {
                start = j;
            }
        }
        st[start] = true;
        for (int end = 1; end <= n; ++end) {
            d[end] = min(d[end], d[start] + f[start][end]);
        }
    }
    return d[n] == INF ? -1 : d[n];
}

int main() {
    init();
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int start, end, length;
        cin >> start >> end >> length;
        f[start][end] = min(f[start][end], length);
    }
    cout << dijkstra() << endl;
    return 0;
}