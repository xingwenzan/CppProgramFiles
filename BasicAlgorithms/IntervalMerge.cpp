//
// Created by 86159 on 2023-04-15.
// 区间合并 https://www.acwing.com/problem/content/805/
//

#include "iostream"
#include "algorithm"
#include "vector"

using namespace std;
typedef pair<int, int> PII;

vector<PII> interval;

int merge() {
    vector<PII> tmp;
    sort(interval.begin(), interval.end());
    int start = -2e9, end = -2e9;
    for (auto item: interval) {
        if (item.first > end) {
            if (start != -2e9) {
                tmp.emplace_back(start, end);
            }
            start = item.first;
            end = item.second;
        } else {
            end = max(end, item.second);
        }
    }
    if (start != -2e9) {
        tmp.emplace_back(start, end);
    }
    return tmp.size();
}

int main() {
    int n, l, r;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> l >> r;
        interval.emplace_back(l, r);
    }
    cout << merge() << endl;
    return 0;
}