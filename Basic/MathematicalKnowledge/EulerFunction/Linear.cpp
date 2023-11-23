//
// Created by 86159 on 2023-11-23.
// 筛法求欧拉函数 https://www.acwing.com/problem/content/876/
//

#include "iostream"

#define N 1000010
using namespace std;

typedef long long LL;

int prime[N], cnt = 0;
int euler[N];
bool st[N];
int n;

void get_euler() {
    euler[1] = 1;
    for (int i = 2; i <= n; ++i) {
        if (!st[i]) {
            prime[cnt++] = i;
            euler[i] = i - 1;
        }
        for (int j = 0; prime[j] <= n / i; ++j) {
            int t = i * prime[j];
            st[t] = true;
            if (i % prime[j] == 0) {
                euler[t] = euler[i] * prime[j];
                break;
            }
            euler[t] = euler[i] * (prime[j] - 1);
        }
    }
}

int main() {
    cin >> n;
    get_euler();
    LL ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += euler[i];
    }
    cout << ans << endl;
}