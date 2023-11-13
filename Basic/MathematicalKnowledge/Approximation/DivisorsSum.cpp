//
// Created by 86159 on 2023-11-13.
// 约数之和 https://www.acwing.com/problem/content/873/
//

#include "iostream"
#include "unordered_map"

using namespace
std;

typedef long long LL;

const int mod = 1e9 + 7;

int main() {
    int n, x;
    cin >> n;
    LL ans = 1;
    unordered_map<int, int> p;

    while (n--) {
        cin >> x;

        for (int i = 2; i <= x / i; ++i) {
            while (x % i == 0) {
                p[i]++;
                x /= i;
            }
        }
        if (x > 1)p[x]++;
    }

    for (auto i:p) {
        LL a = i.first, b = i.second;
        LL tmp = 1;
        while (b--) {
            tmp = (tmp * a + 1) % mod;
        }
        ans = ans * tmp % mod;
    }

    cout << ans << endl;
}