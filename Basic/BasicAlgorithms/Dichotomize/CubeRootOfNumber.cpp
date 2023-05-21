//
// Created by 86159 on 2023-03-30.
// 数的三次方根 https://www.acwing.com/problem/content/792/
//

#include "iostream"

using namespace std;

double dichotomize(double x) {
    double l = -100, r = 100;
    while (r - l > 1e-8) {
        double mid = (l + r) / 2;
        if (mid * mid * mid <= x) {
            l = mid;
        } else {
            r = mid;
        }
    }
    return l;
}

int main() {
    double x;
    cin >> x;
    printf("%.6lf", dichotomize(x));
    return 0;
}