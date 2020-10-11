#include<bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define INF ((1LL<<62LL) - 1)

const int N = 2e5 + 5;
int BIT[N];

void add(int ind, int val){
    for(;ind<N;ind += (ind&-ind)) BIT[ind]+=val;
}

int get(int ind){
    int sum = 0;
    for(;ind>0;ind-=(ind&-ind)) sum+=BIT[ind];
    return sum;
}

int get(int l, int r){
    if(l>r) return 0;
    return get(r) - get(l-1);
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);



}
