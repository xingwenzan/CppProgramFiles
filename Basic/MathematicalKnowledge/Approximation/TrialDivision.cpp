//
// Created by 86159 on 2023-11-06.
// 试除法求约数 https://www.acwing.com/problem/content/871/
//
#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

int n;

vector<int> count(int x) {
    vector<int> ans;
    for (int i = 1; i <= x / i; ++i) {
        if (x % i)continue;
        ans.push_back(i);
        if (x / i > i)ans.push_back(x / i);
    }
    sort(ans.begin(), ans.end());
    return ans;
}

int main() {
    cin >> n;
    int x;
    while (n--) {
        cin >> x;
        auto y = count(x);
        for (auto i: y)cout << i << " ";
        cout << endl;
    }
    return 0;
}