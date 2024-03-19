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

bool removeMin(SqList &s,int &ans){
    if (s.length==0)return false;
    int last = s.data[s.length-1],idx = 0;
    ans = s.data[0];
    for (int i = 1; i < s.length; ++i) {
        if (s.data[i]<ans){
            ans = s.data[i];
            idx = i;
        }
    }
    s.data[idx] = last;
    s.length--;
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

int main(){
    int tmp;
    // 初始化
    initList(sqList);
    scanf("%d",&tmp);
    while (tmp!=9999 && add(sqList,tmp))scanf("%d",&tmp);
    // 使用
    printf("删除前:\n");
    outSqList(sqList);
    printf("删除后:\n");
    if (removeMin(sqList,tmp)){
        outSqList(sqList);
        printf("删除:%d",tmp);
    } else{
        printf("原表为空，操作失败");
    }
}