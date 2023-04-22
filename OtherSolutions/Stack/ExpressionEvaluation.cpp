//
// Created by 86159 on 2023-04-22.
// 表达式求值 https://www.acwing.com/problem/content/3305/
//
#include "iostream"
#include "stack"
#include "unordered_map"

using namespace std;
const int N = (int) 1e5 + 10;
stack<int> num;
stack<char> sign;
unordered_map<char, int> priority{
        {'(', 0},
        {'+', 1},
        {'-', 1},
        {'*', 2},
        {'/', 2},
        {')', N}
};

void eval() {
    auto a = num.top();
    num.pop();
    auto b = num.top();
    num.pop();
    auto c = sign.top();
    sign.pop();
    int x;
    if (c == '+') {
        x = a + b;
    } else if (c == '-') {
        x = b - a;
    } else if (c == '*') {
        x = b * a;
    } else {
        x = b / a;
    }
    num.push(x);
}

int main() {
    string str;
    cin >> str;
    for (int i = 0; i < str.size(); ++i) {
        auto c = str[i];
        if (isdigit(c)) {
            int x = c - '0', j = i + 1;
            while (isdigit(str[j])) {
                x = x * 10 + (str[j++] - '0');
            }
            i = j - 1;
            num.push(x);
        } else if (c == '(') {
            sign.push(c);
        } else if (c == ')') {
            while (sign.top() != '(') {
                eval();
            }
            sign.pop();
        } else {
            while (!sign.empty() && priority[c] <= priority[sign.top()]) {
                eval();
            }
            sign.push(c);
        }
    }
    while (!sign.empty()) {
        eval();
    }
    cout << num.top() << endl;
    return 0;
}