//
// Created by 86159 on 2024-01-23.
// 求组合数 III https://www.acwing.com/problem/content/889/
// LUCAS 定理：
// C_a^b ≡ C_{a%p}^{b%p} * C_{a//p}^{b//p} ≡ C_{a%p}^{b%p} * C_{a//p%p}^{b//p%p} * C_{a//p//p}^{b//p//p} ……
//

#include "iostream"

using namespace std;

typedef long long LL;

int qmi(int a, int b, int p) {
    int ans = 1 % p;
    while (b) {
        if (b & 1)ans = (LL) ans * a % p;
        a = (LL) a * a % p;
        b >>= 1;
    }
    return ans;
}

int C(int a, int b, int p) {
    if (a < b)return 0;
    int x = 1 % p, y = 1 % p;
    for (int i = a, j = 1; j <= b; i--, j++) {
        x = (LL) x * i % p;
        y = (LL) y * j % p;   // 比每次都 qmi 更快
    }
    return (LL) x * qmi(y, p - 2, p) % p;
}

int lucas(LL a, LL b, int p) {
    if (a < p && b < p)return C(a, b, p);
    return (LL) C(a % p, b % p, p) * lucas(a / p, b / p, p) % p;
}

int main() {
    int n, p;
    LL a, b;
    cin >> n;
    while (n--) {
        cin >> a >> b >> p;
        cout << lucas(a, b, p) << endl;
    }
    return 0;
}