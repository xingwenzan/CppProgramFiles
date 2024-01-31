//
// Created by 86159 on 2024-01-31.
// 容斥原理 能被整除的数 https://www.acwing.com/problem/content/892/
// 解析 https://www.acwing.com/solution/content/17517/
//
#include "iostream"

#define N 20
using namespace std;
typedef long long LL;

int p[N];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) cin >> p[i];

    int ans = 0;
    for (int i = 1; i < 1 << m; ++i) {
        int t = 1, s = 0;
        for (int j = 0; j < m; ++j) {
            if (i >> j & 1) {
                if ((LL) t * p[j] > n) {
                    t = -1;
                    break;
                }
                t *= p[j];
                s++;
            }
        }

        if (t != -1) {
            if (s % 2)ans += n / t;
            else ans -= n / t;
        }
    }

    cout << ans << endl;
    return 0;
}