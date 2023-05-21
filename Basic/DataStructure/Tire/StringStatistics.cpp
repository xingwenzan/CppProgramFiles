//
// Created by 86159 on 2023-05-21.
// Trie字符串统计 https://www.acwing.com/problem/content/837/
//
#include "iostream"

using namespace std;
const int N = (int) 1e5 + 10;
int son[N][26], cnt[N], idx = 0;
char str[N];

void insert(char *string) {
    int p = 0;
    for (int i = 0; string[i]; ++i) {
        int u = string[i] - 'a';
        if (!son[p][u]) { son[p][u] = ++idx; }
        p = son[p][u];
    }
    cnt[p]++;
}

int query(char *string) {
    int p = 0;
    for (int i = 0; string[i]; ++i) {
        int u = string[i] - 'a';
        if (!son[p][u]) { return 0; }
        p = son[p][u];
    }
    return cnt[p];
}

int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        char op[2];
        scanf("%s%s", op, str);
        if (*op == 'I') { insert(str); }
        else { printf("%d\n", query(str)); }
    }
    return 0;
}