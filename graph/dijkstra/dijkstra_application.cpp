#include<bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define INF ((1LL<<62LL) - 1)

const int N = 1e5 + 5;
vector<pair<int,int> > g[N];
bool processed[N];
int dist[N], num_paths[N], min_flights[N], max_flights[N];

int n,m;
priority_queue<pair<int,int> > q;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i=1;i<=m;i++){
        int u,v,w; cin >> u >> v >> w;
        g[u].push_back({v,w});
    }

    for(int i=1;i<=n;i++){
        dist[i] = INF;
    }

    dist[1] = 0;
    num_paths[1] = 1;
    min_flights[1] = 0;
    max_flights[1] = 0;

    q.push({0,1});

    while(!q.empty()){
        int u = q.top().second;
        int d = q.top().first;
        q.pop();

        if(processed[u]){
            continue;
        }
        processed[u] = true;

        for(pair<int,int> p : g[u]){
            int v = p.first;
            int w = p.second;

            if(dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
                num_paths[v] = num_paths[u];
                min_flights[v] = min_flights[u] + 1;
                max_flights[v] = max_flights[u] + 1;
                q.push({-dist[v], v});
            } else if(dist[u] + w == dist[v]){
                num_paths[v] += num_paths[u];
                num_paths[v]%=M;
                min_flights[v] = min(min_flights[v], min_flights[u] + 1);
                max_flights[v] = max(max_flights[v], max_flights[u] + 1);

                q.push({-dist[v], v});
            }
        }
    }

    cout << dist[n] << " " << num_paths[n] << " " << min_flights[n] << " " << max_flights[n] << "\n";


}
