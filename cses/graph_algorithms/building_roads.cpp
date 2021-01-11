#include<bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define INF ((1LL<<62LL) - 1)

const int N = 1e5 + 5;
vector<int> g[N];
bool vis[N];
vector<int> comp[N];
int cur_comp = 0;

void dfs(int node){
    vis[node] = true;
    comp[cur_comp].push_back(node);

    for(int x : g[node]){
        if(!vis[x]){
            dfs(x);
        }
    }
}

/*
 Connected components on Graph.
 */
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m; cin >> n >> m;
    for(int i=1;i<=m;i++){
        int u,v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for(int i=1;i<=n;i++){
        if(!vis[i]){
            cur_comp++;
            dfs(i);
        }
    }

    vector<pair<int,int> > ans;

    for(int i=1;i<cur_comp;i++){
        ans.push_back({comp[i].front(), comp[i+1].front()});
    }

    cout << ans.size() << "\n";
    for(auto p : ans){
        cout << p.first << " " << p.second << "\n";
    }



}
