//
// Created by 86159 on 2023-11-16.
// 最大公约数 https://www.acwing.com/problem/content/874/
//

#include "iostream"

using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    int n, a, b;
    cin >> n;
    while (n--) {
        cin >> a >> b;
        cout << gcd(a, b) << endl;
    }
}