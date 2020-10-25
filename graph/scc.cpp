#include<bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define INF ((1LL<<62LL) - 1)

const int N = 1e5 + 5;
vector<int> g[N],gr[N]; // gr is TRANSPOSED Graph
vector<int> scc[N];
int total_scc = 0;
vector<int> topo_order;
bool vis[N];

void dfs_topo(int node){
    vis[node] = true;
    for(int x : g[node]){
        if(!vis[x]){
            dfs_topo(x);
        }
    }
    topo_order.push_back(node);
}

void dfs_reverse(int node){
    vis[node] = true;
    scc[total_scc].push_back(node);
    for(int x : gr[node]){ // Note the TRANSPOSED Graph
        if(!vis[x]){
            dfs_reverse(x);
        }
    }
}

void find_all_scc(int n){
    // Step 1
    memset(vis, false, sizeof(vis));
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs_topo(i);
        }
    }
    reverse(topo_order.begin(), topo_order.end());

    // Step 2
    memset(vis, false, sizeof(vis));
    for(int node : topo_order){ // Note the order of DFS. (TOPO order is used here)
        if(!vis[node]){
            total_scc++;
            dfs_reverse(node);
        }
    }

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);



}
