#include<bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define INF ((1LL<<62LL) - 1)

const int N = 1e5 + 5;
vector<int> g[N];
int col[N];
bool vis[N];
vector<int> topo;

int n,m;

bool dfs(int node){
    col[node] = 1;

    for(int x : g[node]){
        if(col[x] == 1){
            return true;
        } else if(col[x] == 0){
            if(dfs(x)) return true;
        }
    }
    col[node] = 2;
    return false;
}

void dfs_topo(int node){
    vis[node] = true;

    for(int x : g[node]){
        if(!vis[x]){
            dfs_topo(x);
        }
    }

    topo.push_back(node);
}

/*
 * Topological sort.
 */

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i=1;i<=m;i++){
        int u,v; cin >> u >> v;
        g[u].push_back(v);
    }

    bool is_cycle = false;
    for(int i=1;i<=n;i++){
        if(col[i] == 0){
            if(dfs(i)){
                is_cycle = true;
                break;
            }
        }
    }

    if(is_cycle){
        cout << "IMPOSSIBLE\n";
    } else {
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                dfs_topo(i);
            }
        }

        reverse(topo.begin(), topo.end());

        for(int x : topo) cout << x << " ";
        cout << "\n";
    }


}
