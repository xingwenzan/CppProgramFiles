//
// Created by 86159 on 2023-04-16.
// 左孩子右兄弟 https://www.acwing.com/problem/content/3425/
//

#include "iostream"
#include "cstring"

using namespace std;
const int N = (int )1e5+10;

int idx = 0,head[N],value[N],nextPointer[N];

void add(int father,int son){
    value[idx] = son;
    nextPointer[idx] = head[father];
    head[father] = idx++;
}

int dfs(int root){
    int maxHeight=0,cnt=0;
    for (int i = head[root]; i !=-1;i = nextPointer[i]) {
        int tmp = dfs(value[i]);
        maxHeight = (maxHeight> tmp?maxHeight:tmp);
        cnt++;
    }
    return maxHeight+cnt;
}

int main(){
    memset(head,-1,sizeof head);
    int n,x;
    scanf("%d",&n);
    for (int i = 2; i <= n; ++i) {
        scanf("%d",&x);
        add(x,i);
    }
    printf("%d", dfs(1));
    return 0;
}