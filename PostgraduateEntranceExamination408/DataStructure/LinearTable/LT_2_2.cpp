#include "iostream"

#define MaxSize 10

typedef struct {
    int data[MaxSize];
    int length;
} SqList;

SqList sqList;

void  initList(SqList &s){
    s.length = 0;
}

bool add(SqList &s,int e){
    if (s.length>=MaxSize)return false;
    s.data[s.length++] = e;
    return true;
}

void outSqList(SqList &s){
    if (s.length==0){
        printf("空表\n");
        return;
    }
    for (int i = 0; i < s.length; ++i) {
        printf("%d ",s.data[i]);
    }
    printf("\n");
}

bool Reverse(SqList &s){
    if (s.length==0)return false;
    int tmp;
    for (int i = 0; i < s.length/2; ++i) {
        tmp = s.data[i];
        s.data[i] = s.data[s.length-i-1];
        s.data[s.length-i-1] = tmp;
    }
    return true;
}

int main(){
    int tmp;
    // 初始化
    initList(sqList);
    scanf("%d",&tmp);
    while (tmp!=9999 && add(sqList,tmp))scanf("%d",&tmp);
    // 使用
    printf("操作前:\n");
    outSqList(sqList);
    printf("操作后:\n");
    if (Reverse(sqList)){
        outSqList(sqList);
    } else{
        printf("原表为空，操作失败");
    }
}