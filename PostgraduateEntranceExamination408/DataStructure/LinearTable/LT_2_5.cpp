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
    printf("\n表长：%d\n",s.length);
}

bool DeDuplicate(SqList &s){
    if (s.length==0)return false;
    int i = 0;
    for (int j = 1; j < s.length; ++j) {
        if (s.data[i] != s.data[j])s.data[++i] = s.data[j];
    }
    s.length = i+1;

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
    if (DeDuplicate(sqList)){
        outSqList(sqList);
    } else{
        printf("原表为空，操作失败");
    }
}