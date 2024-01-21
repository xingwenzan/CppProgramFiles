//
// Created by 86159 on 2024-01-21.
// 求组合数 II   https://www.acwing.com/problem/content/888/
// C[a][b] = a!/[(a-b)! * b!] = a! * (a-b)!^(-1) * b!^(-1)
// 预处理出 i! 和 (i!)^(-1) (i! 的逆元 = i 的逆元 * i-1 的逆元 * …… * 1 的逆元)
//
#include "iostream"

using namespace std;
typedef long long LL;
#define N 100010
const int mod = 1e9 + 7;
int fact[N], infact[N];

int qmi(int a, int b, int p) {
    int ans = 1 % p;
    while (b) {
        if (b & 1)ans = (LL) ans * a % p;
        a = (LL) a * a % p;
        b >>= 1;
    }
    return ans;
}

void init() {
    fact[0] = infact[0] = 1;
    for (int i = 1; i < N; ++i) {
        fact[i] = (LL) fact[i - 1] * i % mod;
        infact[i] = (LL) infact[i - 1] * qmi(i, mod - 2, mod) % mod;
    }
}

int main() {
    init();
    int n, a, b;
    cin >> n;
    while (n--) {
        cin >> a >> b;
        cout << (LL) fact[a] * infact[a - b] % mod * infact[b] % mod << endl;
    }
}