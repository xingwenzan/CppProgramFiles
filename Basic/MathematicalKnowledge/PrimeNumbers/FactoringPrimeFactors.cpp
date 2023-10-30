//
// Created by 86159 on 2023-10-30.
// 分解质因数 https://www.acwing.com/problem/content/869/
//

#include "iostream"

using namespace std;

void factor(int x) {
    for (int i = 2; i <= x / i; ++i) {
        if (x % i)continue;
        int num = 0;
        while (x % i == 0) {
            x /= i;
            num++;
        }
        cout << i << ' ' << num << endl;
    }
    if (x > 1) cout << x << ' ' << 1 << endl;
    cout << endl;
}

int main() {
    int n, x;
    cin >> n;
    while (n--) {
        cin >> x;
        factor(x);
    }
}