//
// Created by 86159 on 2023-06-14.
// 模拟散列表 https://www.acwing.com/problem/content/842/
// 开放寻址法
//


#include "iostream"
#include "cstring"

using namespace std;

const int N = (int )2e5+3,null = 0x3f3f3f3f;

int hashTable[N];

int find(int x){
    int p = (x%N+N)%N;
    while (hashTable[p]!=x && hashTable[p]!=null){
        p++;
        if (p==N){p=0;}
    }
    return p;
}

void insert(int x){
    hashTable[find(x)] = x;
}

int exist(int x){
    int p = find(x);
    if (hashTable[p]==x){
        return 1;
    } else{
        return 0;
    }
}

int main(){
    memset(hashTable,null,sizeof hashTable);
    int n;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        char op;
        int x;
        cin>>op>>x;
        if (op=='I'){
            insert(x);
        } else{
            if (exist(x)){
                puts("Yes");
            } else{
                puts("No");
            }
        }
    }
}