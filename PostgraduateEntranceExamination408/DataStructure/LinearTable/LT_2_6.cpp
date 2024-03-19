#include "iostream"

#define MaxSize 10

typedef struct {
    int data[MaxSize];
    int length;
} SqList;


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

bool merge(SqList s1,SqList s2,SqList &ans){
    if (s1.length+s2.length>=MaxSize)return false;
    ans.length = s1.length+s2.length;
    int i = 0,j = 0,k = 0;
    while (i<s1.length && j<s2.length){
        if (s1.data[i]<s2.data[j])ans.data[k++] = s1.data[i++];
        else ans.data[k++] = s2.data[j++];
    }
    while (i<s1.length)ans.data[k++] = s1.data[i++];
    while (j<s2.length)ans.data[k++] = s2.data[j++];

    return true;
}

int main(){
    int tmp;
    SqList S1,S2,ans;
    // 初始化
    initList(S1);
    scanf("%d",&tmp);
    while (tmp!=9999 && add(S1,tmp))scanf("%d",&tmp);

    initList(S2);
    scanf("%d",&tmp);
    while (tmp!=9999 && add(S2,tmp))scanf("%d",&tmp);

    // 使用
    printf("操作前:\n");
    outSqList(S1);
    outSqList(S2);
    printf("操作后:\n");
    if (merge(S1,S2,ans)){
        outSqList(ans);
    } else{
        printf("原表过大，操作失败");
    }
}