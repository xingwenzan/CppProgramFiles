//
// Created by 86159 on 2023-11-02.
// 筛质数 https://www.acwing.com/problem/content/870/
// 线性筛法
//

#include "iostream"

using namespace std;

#define N 1000010

int n;
int prime[N], cnt = 0;
bool st[N];

void judge() {
    if (n < 2)return;
    for (int i = 2; i <= n; ++i) {
        if (!st[i])prime[cnt++] = i;
        for (int j = 0; prime[j] <= n / i; ++j) {
            st[prime[j] * i] = true;
            if (i % prime[j] == 0)break;
        }
    }
}

int main() {
    cin >> n;
    judge();
    cout << cnt << endl;
}