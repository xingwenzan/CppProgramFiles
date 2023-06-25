//
// Created by 86159 on 2023-06-25.
// 走迷宫 https://www.acwing.com/problem/content/846/
//
#include "iostream"
#include "cstring"
#include "queue"

using namespace std;

const int N = 110;

typedef pair<int, int> PII;

int maze[N][N], n, m;
int X[4] = {0, 1, 0, -1}, Y[4] = {1, 0, -1, 0};

int bfs() {
    int distance[N][N];
    memset(distance, -1, sizeof distance);
    distance[0][0] = 0;
    queue<PII> q;
    q.push({0, 0});
    while (!q.empty()) {
        auto tmp = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int x = tmp.first + X[i], y = tmp.second + Y[i];
            if (x >= 0 && x < n && y >= 0 && y < m && maze[x][y] == 0 && distance[x][y] == -1) {
                q.push({x, y});
                distance[x][y] = distance[tmp.first][tmp.second] + 1;
            }
        }
    }
    return distance[n - 1][m - 1];
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> maze[i][j];
        }
    }
    cout << bfs() << endl;
}