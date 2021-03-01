#include<bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define INF ((1LL<<62LL) - 1)

const int N = 1e5 + 5;
vector<int> g[N], g_inv[N];
bool vis[N], vis_inv[N];

int n,m;

void dfs(int node){
    vis[node] = true;
    for(int x : g[node]){
        if(!vis[x]){
            dfs(x);
        }
    }
}

void dfs_inv(int node){
    vis_inv[node] = true;
    for(int x : g_inv[node]){
        if(!vis_inv[x]){
            dfs_inv(x);
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

    dfs(1);
    dfs_inv(1);

    for(int i=2;i<=n;i++){
        if(!vis[i]){
            cout << "NO\n";
            cout << "1 " << i << "\n";
            return 0;
        } else if(!vis_inv[i]){
            cout << "NO\n";
            cout << i << " " << 1 << "\n";
            return 0;
        }
    }

    cout << "YES\n";



}
