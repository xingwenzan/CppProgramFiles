//
// Created by 86159 on 2024-01-26.
// 求组合数 IV https://www.acwing.com/problem/content/890/
// 筛质数 - a!分解 - 高精度计算
// a!分解 https://www.acwing.com/video/309/
//
#include "iostream"
#include "vector"

#define N 5005
using namespace std;

int prime[N], cnt = 0, power[N];
bool st[N];


void get_prime(int x) {
    for (int i = 2; i <= x; ++i) {
        if (!st[i])prime[cnt++] = i;
        for (int j = 0; prime[j] <= x / i; ++j) {
            st[i * prime[j]] = true;
            if (i % prime[j] == 0)break;
        }
    }
}

int get_power(int x, int p) {
    int ans = 0;
    while (x) {
        ans += x / p;
        x /= p;
    }
    return ans;
}

vector<int> mul(vector<int> a, int b) {
    int tmp = 0;
    vector<int> c;
    for (int i = 0; i < a.size(); ++i) {
        tmp += a[i] * b;
        c.push_back(tmp % 10);
        tmp /= 10;
    }
    while (tmp) {
        c.push_back(tmp % 10);
        tmp /= 10;
    }
    return c;
}

int main() {
    int a, b;
    cin >> a >> b;
    get_prime(a);
    for (int i = 0; i < cnt; ++i) {
        int p = prime[i];
        power[i] = get_power(a, p) - get_power(b, p) - get_power(a - b, p);
    }
    vector<int> ans;
    ans.push_back(1);
    for (int i = 0; i < cnt; ++i) {
        for (int j = 0; j < power[i]; ++j) ans = mul(ans, prime[i]);
    }
    for (int i = ans.size() - 1; i >= 0; i--) printf("%d", ans[i]);
    puts("");
    return 0;
}