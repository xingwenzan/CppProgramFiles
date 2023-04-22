//
// Created by 86159 on 2023-04-18.
// 模拟栈 https://www.acwing.com/problem/content/830/
//
#include "iostream"

using namespace std;
const int M = (int )1e5+10;

int stack[M],idx=-1;

void push(int num){
    stack[++idx] = num;
}

void pop(){
    idx--;
}

bool empty(){
    return idx==-1;
}

int query(){
    return stack[idx];
}

int main(){
    int n,x;
    string op;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        cin>>op;
        if(op=="push"){
            cin>>x;
            push(x);
        } else if(op=="pop"){
            pop();
        } else if(op=="empty"){
            cout<<(empty()? "YES": "NO")<<endl;
        } else{
            cout<<query()<<endl;
        }
    }

    return 0;
}