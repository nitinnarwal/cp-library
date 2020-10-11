#include<bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define INF ((1LL<<62LL) - 1)

const int N = 2e5 + 5;
int tree[4*N + 5];

void build(int node, int l, int r){
    if(l>r) return;
    if(l == r){
        tree[node] = 5555;
        return;
    }
    int m = (l + r)/2;
    build(2*node, l, m);
    build(2*node, m+1, r);
    tree[node] = tree[2*node] + tree[2*node+1];
}

void update(int node, int l, int r, int ind, int val){
    if(l == r){
        tree[node] += val;
        return;
    }

    int m = (l + r)/2;
    if(ind>=l && ind<=m){
        update(2*node, l, m, ind, val);
    } else {
        update(2*node+1, m+1, r, ind, val);
    }
    tree[node] = tree[2*node] + tree[2*node+1];
}

int query(int node, int l, int r, int ql, int qr){
    if(ql<=l && r<=qr) return tree[node];
    if(ql>qr || ql>r || l>r) return 0;

    int m = (l + r)/2;
    int one = query(2*node, l, m, ql, qr);
    int two = query(2*node + 1, m+1, r, ql, qr);
    return one + two;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);



}
