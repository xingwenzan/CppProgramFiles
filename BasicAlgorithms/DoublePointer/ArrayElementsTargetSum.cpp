//
// Created by 86159 on 2023-04-11.
// 数组元素的目标和 https://www.acwing.com/problem/content/802/
//

#include "iostream"

using namespace std;

const int N = (int ) 1e5+10;
int A[N],B[N];

int main(){
    int n,m,x;
    cin>>n>>m>>x;
    for (int i = 0; i < n; ++i) {
        cin>>A[i];
    }
    for (int i = 0; i < m; ++i) {
        cin>>B[i];
    }
    for (int i = 0,j=m-1; i < n; ++i) {
        while (j>=0 && A[i]+B[j]>x){
            j--;
        }
        if (j>=0 && A[i]+B[j]==x){
            cout<<i<<" "<<j<<endl;
            break;
        }
    }
}