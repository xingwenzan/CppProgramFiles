//
// Created by 86159 on 2023-04-13.
// 二进制中1的个数 https://www.acwing.com/problem/content/description/803/
//

#include "iostream"

using namespace std;

int lowBit(int x) { return x & (-x); }

int main() {
    int n, x;
    cin >> n;
    while (n--) {
        int ans = 0;
        cin >> x;
        while (x) {
            x -= lowBit(x);
            ans++;
        }
        cout << ans << " ";
    }
}