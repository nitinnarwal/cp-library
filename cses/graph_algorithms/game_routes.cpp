#include<bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define INF ((1LL<<62LL) - 1)

const int N = 1e5 + 5;
vector<int> g[N], g_dash[N];
bool vis[N];
int dp[N];
vector<int> topo;

int n,m;

void dfs(int node){
    vis[node] = true;
    for(int x : g[node]){
        if(!vis[x]){
            dfs(x);
        }
    }
    topo.push_back(node);
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i=1;i<=m;i++){
        int u,v; cin >> u >> v;
        g[u].push_back(v);
        g_dash[v].push_back(u);
    }

    dfs(1);
    reverse(topo.begin(), topo.end());

    dp[1] = 1;

    for(int node : topo){
        for(int par : g_dash[node]){
            dp[node] += dp[par];
            dp[node]%=M;
        }
    }

    cout << dp[n] << "\n";



}
