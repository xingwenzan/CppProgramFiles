//
// Created by 86159 on 2023-04-26.
// 模拟队列 https://www.acwing.com/problem/content/831/
//
#include "iostream"

using namespace std;
const int M = (int) 1e5 + 10;

int queue[M], head = 0, tail = 0;

void push(int x) {
    queue[tail++] = x;
}

void pop() {
    head++;
}

bool empty() {
    return head >= tail;
}

int query() {
    return queue[head];
}

int main() {
    int n, x;
    string op;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> op;
        if (op == "push") {
            cin >> x;
            push(x);
        } else if (op == "pop") {
            pop();
        } else if (op == "empty") {
            if (empty()) { cout << "YES" << endl; }
            else { cout << "NO" << endl; }
        } else {
            cout << query() << endl;
        }
    }
}