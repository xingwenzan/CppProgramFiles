//
// Created by 86159 on 2023-03-29.
// 数的范围 https://www.acwing.com/problem/content/791/
//

#include "iostream"

#define N 100010

using namespace std;
int lst[N];

int dichotomizeMax(int num, int lenght) {
    int l = 0, r = lenght - 1;
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (lst[mid] <= num) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    if (lst[r] == num) {
        return r;
    } else {
        return -1;
    }
}

int dichotomizeMin(int num, int lenght) {
    int l = 0, r = lenght - 1;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (lst[mid] >= num) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    if (lst[l] == num) {
        return l;
    } else {
        return -1;
    }
}

int main() {
    int n, q, x;
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> lst[i];
    }
    for (int i = 0; i < q; ++i) {
        cin >> x;
        cout << dichotomizeMin(x, n) << " " << dichotomizeMax(x, n) << endl;
    }
    return 0;
}