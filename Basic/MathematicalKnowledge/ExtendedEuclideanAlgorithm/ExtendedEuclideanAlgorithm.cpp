//
// Created by 86159 on 2023-12-04.
// 扩展欧几里得算法 https://www.acwing.com/problem/content/879/
//

#include "iostream"

using namespace std;

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
    int a, b, x = 0, y = 0;
    while (n--) {
        cin >> a >> b;
        int d = exgcd(a, b, x, y);
        cout << x << ' ' << y << endl;
    }
}