#include<bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define INF ((1LL<<62LL) - 1)

const int N = 2505;
vector<pair<int,int> > g[N];
bool vis[N];
int dist[N];
int dist2[N];

int n,m;

bool dfs(int node, int other_node){
    vis[node] = true;
    if(node == other_node) return true;

    for(pair<int,int> p : g[node]){
        int x = p.first;
        if(!vis[x]){
            if(dfs(x, other_node))
                return true;
        }
    }
    return false;
}

/*
Bellman-Ford algorithm : positive cycle detection application.
*/
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i=1;i<=m;i++){
        int u,v,w; cin >> u >> v >> w;
        g[u].push_back({v,w});
    }

    // Bellman Ford base start
    for(int i=1;i<=n;i++){
        dist[i] = -INF;
    }
    dist[1] = 0;

    for(int i=1;i<=n-1;i++){
        for(int u=1;u<=n;u++){
            for(pair<int,int> p : g[u]){
                int v = p.first;
                int w = p.second;
                dist[v] = max(dist[v], dist[u] + w);
            }
        }
    }
    // Bellman Ford base end.


    //Positive Cycle detection start
    for(int i=1;i<=n;i++){
        dist2[i] = dist[i];
    }
    for(int i=1;i<=n-1;i++){
        for(int u=1;u<=n;u++){
            for(pair<int,int> p : g[u]){
                int v = p.first;
                int w = p.second;
                dist2[v] = max(dist2[v], dist2[u] + w);
            }
        }
    }

    vector<int> in_pos_cycle;
    for(int i=1;i<=n;i++){
        if(dist2[i] > dist[i]){
            in_pos_cycle.push_back(i);
        }
    }
    //Positive Cycle detection end



    // For infinite score : Node in positive cycle must be reachable from 1 and it must connect to n.
    bool reachable_from_pos_cycle = false;
    for(int x : in_pos_cycle){
        memset(vis, false, sizeof(vis));
        if(dfs(x, n)){
            memset(vis, false, sizeof(vis));
            if(dfs(1,x)) {
                reachable_from_pos_cycle = true;
                break;
            }
        }
    }

    if(reachable_from_pos_cycle){
        cout << "-1\n";
    } else {
        cout << dist[n] << "\n";
    }





}
