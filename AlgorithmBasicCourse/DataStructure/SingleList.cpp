//
// Created by 86159 on 2023-04-16.
// 单链表 https://www.acwing.com/problem/content/828/
//
#include "iostream"

using namespace std;

const int M = (int )1e5+10;

int pointerArray[M], valueArray[M], idx = 1;

void add(int pointer, int value) {
    valueArray[idx] = value;
    pointerArray[idx] = pointerArray[pointer];
    pointerArray[pointer] = idx++;
}

void remove(int pointer) {
pointerArray[pointer] = pointerArray[pointerArray[pointer]];
}

int main() {
    pointerArray[0] = -1;
    int n;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        char op;
        int p,e;
        cin>>op;

        if (op == 'H') {
            cin>>e;
            add(0, e);
        } else if (op == 'D') {
            cin>>p;
            remove(p);
        } else {
            cin>>p>>e;
            add(p, e);
        }
    }
    for (int i = pointerArray[0]; i != -1; i = pointerArray[i]) {
        cout<<valueArray[i]<<" ";
    }
    return 0;
}