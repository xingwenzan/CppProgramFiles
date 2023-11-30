//
// Created by 86159 on 2023-11-30.
// 快速幂求逆元 https://www.acwing.com/problem/content/878/
//

#include "iostream"

using namespace std;

typedef long long LL;

int n;

LL qmi(int a, int b, int p) {
    LL ans = 1 % p;
    while (b) {
        if (b & 1)ans = ans * a % p;
        a = a * (LL) a % p;
        b >>= 1;
    }
    return ans;
}

int main() {
    cin >> n;
    int a, p;
    while (n--) {
        cin >> a >> p;
        if (a % p)cout << qmi(a, p - 2, p) << endl;
        else puts("impossible");
    }
    return 0;
}