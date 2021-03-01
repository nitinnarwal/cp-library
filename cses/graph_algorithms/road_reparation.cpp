#include<bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define INF ((1LL<<62LL) - 1)

const int N = 1e5 + 5;
vector<pair<int,int> > g[N];
vector<pair<int,pair<int,int> > > edges;

int par[N];
int sz[N];

int get_parent(int a){
    if(par[a] == a) return a;
    par[a] = get_parent(par[a]);
    return par[a];
}

void merge(int a, int b){
    a = get_parent(a);
    b = get_parent(b);

    if(sz[a] < sz[b]){
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
    for(int i=1;i<=m;i++){
        int u,v,w; cin >> u >> v >> w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
        edges.push_back(make_pair(w, make_pair(u,v)));
    }

    for(int i=1;i<=n;i++){
        par[i] = i;
        sz[i] = 1;
    }

    sort(edges.begin(), edges.end());

    int ans = 0;

    for(pair<int, pair<int,int> > p : edges){
        int w = p.first;
        int u = p.second.first;
        int v = p.second.second;

        if(get_parent(u) != get_parent(v)){
            merge(u,v);
            ans += w;
        }
    }

    bool ok = true;
    for(int i=2;i<=n;i++){
        if(get_parent(i) != get_parent(1)){
            ok = false;
            break;
        }
    }

    if(ok){
        cout << ans << "\n";
    } else {
        cout << "IMPOSSIBLE\n";
    }

}
