#include<bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define INF ((1LL<<62LL) - 1)

const int N = 1e5 + 5;
vector<int> g[N], g_inv[N];
int comp[N];
int total_comp = 0;
bool vis[N];
vector<int> topo;

int n,m;

void dfs_topo(int node){
    vis[node] = true;
    for(int x : g[node]){
        if(!vis[x]){
            dfs_topo(x);
        }
    }
    topo.push_back(node);
}

void dfs_comp(int node){
    vis[node] = true;
    comp[node] = total_comp;

    for(int x : g_inv[node]){
        if(!vis[x]){
            dfs_comp(x);
        }
    }
}

void scc(){
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs_topo(i);
        }
    }
    reverse(topo.begin(), topo.end());


    memset(vis, false, sizeof(vis));
    for(int node : topo){
        if(!vis[node]){
            total_comp++;
            dfs_comp(node);
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i=1;i<=m;i++){
        int u,v; cin >> u >> v;
        g[u].push_back(v);
        g_inv[v].push_back(u);
    }

    scc();

    cout << total_comp << "\n";
    for(int i=1;i<=n;i++){
        cout << comp[i] << " ";
    }
    cout << "\n";


}
