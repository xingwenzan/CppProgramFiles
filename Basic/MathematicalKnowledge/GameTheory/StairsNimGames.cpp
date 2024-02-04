//
// Created by 86159 on 2024-02-04.
// 台阶-Nim游戏 https://www.acwing.com/problem/content/894/
// a1 ^ a3 ^ a5 ^ …… ^ an(n 是奇数) = 0   先手必败
//
#include <iostream>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    int res = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        if (i % 2 == 0)res ^= x;
    }

    if (res) puts("Yes");
    else puts("No");

    return 0;
}
