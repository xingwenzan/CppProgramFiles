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

bool removeXY(SqList &s,int x,int y){
    if (s.length==0)return false;
    if (x>y)return false;
    int k = 0;
    for (int i = 0; i < s.length; ++i) {
        if (s.data[i]>=x && s.data[i]<=y)k++;
        else s.data[i-k] = s.data[i];
    }
    s.length-=k;

    return true;
}

int main(){
    int tmp;
    // 初始化
    initList(sqList);
    scanf("%d",&tmp);
    while (tmp!=9999 && add(sqList,tmp))scanf("%d",&tmp);

    int x,y;
    scanf("%d%d",&x,&y);
    // 使用
    printf("操作前:\n");
    outSqList(sqList);
    printf("操作后:\n");
    if (removeXY(sqList,x,y)){
        outSqList(sqList);
    } else{
        printf("原表为空，操作失败");
    }
}