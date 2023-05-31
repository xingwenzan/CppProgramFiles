//
// Created by 86159 on 2023-05-31.
// 连通块中点的数量 https://www.acwing.com/problem/content/839/
//
#include "iostream"

using namespace std;
const int N = (int) 1e5 + 10;

int father[N], son[N];

int quickFather(int x) {
    if (father[x] != x) { father[x] = quickFather(father[x]); }
    return father[x];
}

void marry(int a, int b) {
    int fA = quickFather(a), fB = quickFather(b);
    if (fA != fB) {
        father[fA] = father[fB];
        son[fB] += son[fA];
    }
}

int pointNum(int x) {
    return son[quickFather(x)];
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        father[i] = i;
        son[i] = 1;
    }
    for (int i = 0; i < m; ++i) {
        string op;
        int a, b;
        cin >> op;
        if (op == "Q2") {
            cin >> a;
            cout << pointNum(a) << endl;
        } else {
            cin >> a >> b;
            if (op == "Q1") {
                if (quickFather(a) == quickFather(b)) {
                    puts("Yes");
                } else {
                    puts("No");
                }
            } else {
                marry(a, b);
            }
        }
    }
}