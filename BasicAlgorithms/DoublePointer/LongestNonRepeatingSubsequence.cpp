//
// Created by 86159 on 2023-04-10.
// 最长连续不重复子序列 https://www.acwing.com/problem/content/801/
//

#include "iostream"

using namespace std;
const int N = (int) 1e5 + 10;
int q[N], s[N];

int main() {
    int n, ans = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> q[i];
    }
    for (int i = 0, j = 0; i < n; ++i) {
        s[q[i]]++;
        while (j < i && s[q[i]] > 1) { s[q[j++]]--; }
        ans = max(ans, i - j + 1);
    }
    cout << ans << endl;
}