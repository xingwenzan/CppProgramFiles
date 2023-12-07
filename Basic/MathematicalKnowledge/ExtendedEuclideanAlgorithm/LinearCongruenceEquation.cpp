//
// Created by 86159 on 2023-12-07.
// 线性同余方程 https://www.acwing.com/problem/content/880/
//
#include "iostream"

using namespace std;
typedef long long LL;

int n;

int exgcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    int d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

int main() {
    cin >> n;
    int a, b, m;
    int x = 0, y = 0;
    while (n--) {
        cin >> a >> b >> m;
        int gcd = exgcd(a, m, x, y);
        if (b % gcd)puts("impossible");
        else cout << (LL) b / gcd * x % m << endl;
    }
    return 0;
}