#include "iostream"

#define MaxSize 10

typedef struct {
    int data[MaxSize];
    int length;
} SqList;

SqList S;

void  initList(SqList &s){
    s.length = 0;
}

bool add(SqList &s,int e){
    if (s.length>=MaxSize)return false;
    s.data[s.length++] = e;
    return true;
}

void outSqList(SqList s){
    if (s.length==0){
        printf("空表\n");
        return;
    }
    for (int i = 0; i < s.length; ++i) {
        printf("%d ",s.data[i]);
    }
    printf("\n表长：%d\n",s.length);
}

void turn(SqList &s,int st,int ed){
    int tmp;
    for (int i = st; i <= (ed - st) / 2; ++i) {
        tmp = s.data[i];
        s.data[i] = s.data[ed+st-i];
        s.data[ed+st-i] = tmp;
    }
}

bool change(SqList &s,int m,int n){
    if (n+m!=S.length)return false;
    if (m==0 || n==0)return true;

    turn(s,0,s.length-1);
    turn(s,0,n-1);
    turn(s,n,s.length-1);

    return true;
}

int main(){
    int tmp;
    // 初始化
    initList(S);
    scanf("%d",&tmp);
    while (tmp!=9999 && add(S,tmp))scanf("%d",&tmp);

    int m,n;
    scanf("%d%d",&m,&n);

    // 使用
    printf("操作前:\n");
    outSqList(S);
    printf("操作后:\n");
    if (change(S,m,n)){
        outSqList(S);
    } else{
        printf("表长错误，操作失败");
    }
}