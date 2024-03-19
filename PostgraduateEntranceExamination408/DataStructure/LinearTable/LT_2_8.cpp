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


void check(SqList &s,int x){
    int l=0,r = s.length-1,mid,tmp;

    while (l<=r){
        mid = (l+r)>>1;
        if (s.data[mid]==x)break;
        else if (s.data[mid]>x)r = mid-1;
        else l = mid+1;
    }

    if (s.data[mid]==x && mid!=s.length-1){
        tmp = s.data[mid];
        s.data[mid] = s.data[mid+1];
        s.data[mid+1] = tmp;
    }

    if (l>r){
        for (int i = s.length-1; i > r; --i) {
            s.data[i+1] = s.data[i];
        }
        s.data[r+1] = x;s.length++;
    }
}

int main(){
    int tmp;
    // 初始化
    initList(S);
    scanf("%d",&tmp);
    while (tmp!=9999 && add(S,tmp))scanf("%d",&tmp);

    scanf("%d",&tmp);

    // 使用
    printf("操作前:\n");
    outSqList(S);
    printf("操作后:\n");
    check(S,tmp);
    outSqList(S);
}