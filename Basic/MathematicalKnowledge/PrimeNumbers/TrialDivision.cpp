//
// Created by 86159 on 2023-10-26.
// 试除法判定质数 https://www.acwing.com/problem/content/868/
//

#include "iostream"

using namespace std;

bool judge(int x) {
    if (x < 2)return false;
    for (int i = 2; i <= x / i; ++i) {
        if (x % i)continue;
        return false;
    }
    return true;
}

int main() {
    int n, x;
    cin >> n;
    while (n--) {
        cin >> x;
        if (judge(x))puts("Yes");
        else puts("No");
    }
}