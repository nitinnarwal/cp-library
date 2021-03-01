#include<bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define INF ((1LL<<62LL) - 1)

const int N = 1e5 + 5;
int par[N];
int sz[N];

int get_parent(int a){
    if(par[a] == a) return a;
    return par[a] = get_parent(par[a]);
}

void merge(int a, int b){
    a = get_parent(a);
    b = get_parent(b);
    if(sz[a] < sz[b]) {
        swap(a, b);
    }

    sz[a] += sz[b];
    par[b] = a;
}

int n,m;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for(int i=1;i<=n;i++){
        par[i] = i;
        sz[i] = 1;
    }

    int comp = n;
    int mx = 1;

    for(int i=1;i<=m;i++){
        int u,v; cin >> u >> v;
        if(get_parent(u) != get_parent(v)){
            merge(u,v);
            comp--;
            mx = max(mx, sz[get_parent(u)]);
        }
        cout << comp << " " << mx << "\n";
    }


}
