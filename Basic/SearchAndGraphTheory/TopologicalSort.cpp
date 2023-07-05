//
// Created by 86159 on 2023-07-05.
// 拓扑排序 有向图的拓扑序列 https://www.acwing.com/problem/content/850/
//

#include "iostream"

using namespace std;

const int N = (int ) 1e5+10;
int score[N];
int h[N], e[N], p[N], idx = 0;
int queue[N], head = 0, tail = 0;

// 图中添加边
void addG(int father, int son) {
    e[idx] = son, p[idx] = h[father], h[father] = idx++;
}

// 队列里添加点
void addQ(int x) {
    queue[tail++] = x;
}

bool empty() {
    return head >= tail;
}

int poll() {
    return queue[head++];
}

bool bfs(int num) {
    for (int i = 1; i <= num; ++i) {
        if (!score[i]) { addQ(i); }
    }
    while (!empty()) {
        int father = poll();
        for (int i = h[father]; i != -1; i = p[i]) {
            int son = e[i];
            if (--score[son] == 0) {
                addQ(son);
            }
        }
    }
    return tail == num;
}

int main() {
    for (int i = 0; i < N; ++i) {
        score[i] = 0;
        h[i] = -1;
    }
    int n, m;
    cin>>n>>m;
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin>>x>>y;
        addG(x, y);
        score[y]++;
    }
    if (bfs(n)) {
        for (int i = 0; i < n; ++i) {
            cout<<queue[i]<<" ";
        }
    } else {
        puts("-1");
    }
    return 0;
}