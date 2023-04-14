//
// Created by 86159 on 2023-04-14.
// 区间和 https://www.acwing.com/problem/content/804/
// 离散化本体: 排序 + 去重；查找: 二分；应用: 前缀和（本题）
//

#include "iostream"
#include "algorithm"
#include "vector"

using namespace std;
typedef pair<int,int> PII;
const int N = (int )1e5*3+10;

int nums[N];
vector<int> point;
vector<PII> xc,lr;

void discretization(){
    sort(point.begin(),point.end());
    point.erase(std::unique(point.begin(), point.end()),point.end());
}

int dichotomize(int num){
    int l = 0,r = point.size()-1;
    while (l<r){
        int mid = (l+r)>>1;
        if (point[mid]>=num){
            r = mid;
        } else{
            l = mid+1;
        }
    }
    return l;
}

void prefixSum(){
    for (int i = 1; i < point.size(); ++i) {
        nums[i] += nums[i-1];
    }
}

int main(){
    int n,m,x,c,l,r;
    cin>>n>>m;
    for (int i = 0; i < n; ++i) {
        cin>>x>>c;
        xc.emplace_back(x,c);
        point.push_back(x);
    }
    for (int i = 0; i < m; ++i) {
        cin>>l>>r;
        lr.emplace_back(l,r);
        point.emplace_back(l);
        point.emplace_back(r);
    }
    discretization();
    for (auto item:xc) {
        x = dichotomize(item.first);
        nums[x]+=item.second;
    }
    prefixSum();
    for (auto item:lr) {
        l = dichotomize(item.first);
        r = dichotomize(item.second);
        cout<<nums[r]-nums[l-1]<<endl;   // 注：此时可能存在 num[-1] 但该写法合法，不过指向内容未知，本题纯属侥幸，不推荐使用
    }
    return 0;
}