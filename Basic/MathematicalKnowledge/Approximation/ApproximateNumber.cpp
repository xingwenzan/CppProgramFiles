//
// Created by 86159 on 2023-11-09.
// 约数个数
//
#include "iostream"
#include "algorithm"
#include "unordered_map"
#define mod 1000000007
typedef long long LL;

using namespace std;

unordered_map<int, int> prime;
int n;

void count(int x) {
    for (int i = 2; i <= x / i; ++i) {
        while (x % i==0) {
            prime[i]++;
            x /= i;
        }
    }
    if (x > 1)prime[x]++;
}

int main() {
    cin >> n;
    int x;
    while (n--) {
        cin >> x;
        count(x);
    }
    LL ans = 1;
    for (auto p: prime) {
        ans = ans * (p.second + 1)%mod;
    }
    cout << ans << endl;
}