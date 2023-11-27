//
// Created by 86159 on 2023-11-27.
// 快速幂 https://www.acwing.com/problem/content/877/
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
    int a, b, p;
    while (n--) {
        cin >> a >> b >> p;
        cout << qmi(a, b, p) << endl;
    }
}