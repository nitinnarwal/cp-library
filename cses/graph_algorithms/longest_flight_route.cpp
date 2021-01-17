#include<bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define INF ((1LL<<50LL) - 1)

const int N = 1e5 + 5;
vector<int> g[N],g_dash[N];
bool vis[N];
int from[N];
int dist[N];
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

    for(int i=1;i<=n;i++){
        dist[i] = -INF;
    }
    dist[1] = 0;

    for(int node : topo){
        for(int x : g_dash[node]){
            if(dist[x] + 1 > dist[node]){
                dist[node] = dist[x] + 1;
                from[node] = x;
            }
        }
    }

    if(!vis[n]){
        cout << "IMPOSSIBLE\n";
    } else {
        vector<int> ans;
        int cur = n;
        while(cur != 1){
            ans.push_back(cur);
            cur = from[cur];
            if(cur == 0) break;
        }
        ans.push_back(1);

        reverse(ans.begin(), ans.end());
        cout << ans.size() << "\n";
        for(int x : ans){
            cout << x << " ";
        }
        cout << "\n";
    }


}
