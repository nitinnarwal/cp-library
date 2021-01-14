#include<bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define INF ((1LL<<62LL) - 1)

const int N = 1e5 + 5;
vector<int> g[N];
bool vis[N];
int color[N];

int n,m;

bool dfs(int node, int cur_color){
    vis[node] = true;
    color[node] = cur_color;

    for(int x : g[node]){
        if(vis[x]){
            if(color[x] == cur_color){
                return false;
            }
        } else {
            if(!dfs(x, 3 - cur_color)){
                return false;
            }
        }
    }

    return true;
}

/*
 Bipartite check

 */
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i=1;i<=m;i++){
        int u,v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    bool ok = true;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            if(!dfs(i, 1)){
                ok = false;
            }
        }
    }

    if(ok){
        for(int i=1;i<=n;i++){
            cout << color[i] << " ";
        }
        cout << "\n";
    } else {
        cout << "IMPOSSIBLE\n";
    }

}
