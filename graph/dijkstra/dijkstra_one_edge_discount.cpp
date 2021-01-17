#include<bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define INF ((1LL<<62LL) - 1)

const int N = 1e5 + 5;
vector<pair<int,int> > g[N], g_dash[N];
bool processed[N];
priority_queue<pair<int,int> > q;
int dist[N],dist_dash[N];

int n,m;

/*
Dijkstra Application

*/
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i=1;i<=m;i++){
        int u,v,w; cin >> u >> v >> w;
        g[u].push_back({v,w});
        g_dash[v].push_back({u,w});
    }

    for(int i=1;i<=n;i++){
        dist[i] = INF;
        dist_dash[i] = INF;
    }

    dist[1] = 0;
    q.push({0,1});
    while(!q.empty()){
        int cur = q.top().second;
        q.pop();
        if(processed[cur]) {
            continue;
        }
        processed[cur] = true;

        for(pair<int,int> p : g[cur]){
            int v = p.first;
            int w = p.second;

            if(dist[cur] + w < dist[v]) {
                dist[v] = dist[cur] + w;
                q.push({-dist[v], v});
            }
        }
    }

    memset(processed, false, sizeof(processed));

    dist_dash[n] = 0;
    q.push({0,n});
    while(!q.empty()){
        int cur = q.top().second;
        q.pop();
        if(processed[cur]){
            continue;
        }
        processed[cur] = true;

        for(pair<int,int> p : g_dash[cur]){
            int v = p.first;
            int w = p.second;

            if(dist_dash[cur] + w < dist_dash[v]){
                dist_dash[v] = dist_dash[cur] + w;
                q.push({-dist_dash[v], v});
            }
        }
    }

    int ans = INF;

    for(int u=1;u<=n;u++){
        for(pair<int,int> p : g[u]){
            int v = p.first;
            int w = p.second/2;

            ans = min(ans, dist[u] + w + dist_dash[v]);
        }
    }

    cout << ans << "\n";
}
