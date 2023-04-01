//
// Created by 86159 on 2023-04-01.
// 前缀和 https://www.acwing.com/problem/content/797/
//

#include "iostream"

using namespace std;

const int N = 100010;
int nums[N];

int *prefixSum(int lst[], int lenght) {
    static int ans[N];
    ans[0] = 0;
    for (int i = 1; i <= lenght; ++i) {
        ans[i] = ans[i - 1] + lst[i - 1];
    }
    return ans;
}

int main() {
    int n, m, l, r;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    int *sumNums = prefixSum(nums, n);
    for (int i = 0; i < m; ++i) {
        cin >> l >> r;
        cout << *(sumNums + r) - *(sumNums + (l - 1)) << endl;
    }
    return 0;
}