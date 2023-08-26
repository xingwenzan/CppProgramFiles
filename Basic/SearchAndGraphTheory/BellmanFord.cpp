//
// Created by 86159 on 2023-08-26.
// 有边数限制的最短路 https://www.acwing.com/problem/content/855/
//

#include "iostream"
#include "cstring"

using namespace std;

const int N = 510,M = 10010,INF = 0x3f3f3f3f;

typedef struct {
    int start, end, length;
} Edge;

int dist[N], last[N];
Edge edge[M];
int n, m, k;

void BF() {
    for (int i = 0; i < k; ++i) {
        memcpy(last, dist, sizeof dist);
        for (int j = 0; j < m; ++j) {
            Edge e = edge[j];
            dist[e.end] = min(dist[e.end], last[e.start] + e.length);
        }
    }
}

int main() {
    memset(dist, INF, sizeof dist);
    dist[1] = 0;

    cin >> n >> m >> k;
    for (int i = 0; i < m; ++i) {
        cin >> edge[i].start >> edge[i].end >> edge[i].length;
    }

    BF();

    if (dist[n] > INF / 2)cout << "impossible" << endl;
    else cout << dist[n] << endl;
}