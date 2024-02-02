//
// Created by 86159 on 2024-02-02.
// Nim游戏 https://www.acwing.com/problem/content/893/
// a1^a2^……^an = 0 先手必败
//
#include <iostream>

using namespace std;

const int N = 100010;


int main() {
    int n;
    scanf("%d", &n);

    int res = 0;
    while (n--) {
        int x;
        scanf("%d", &x);
        res ^= x;
    }

    if (res) puts("Yes");
    else puts("No");

    return 0;
}
