//
// Created by 86159 on 2023-11-02.
// 筛质数 https://www.acwing.com/problem/content/870/
// 朴素法/埃氏筛
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
        if (st[i])continue;
        prime[cnt++] = i;
        for (int j = i + i; j <= n; j += i) {
            st[j] = true;
        }
    }
}

int main() {
    cin >> n;
    judge();
    cout << cnt << endl;
}