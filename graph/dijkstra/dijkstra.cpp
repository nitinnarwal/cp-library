#include<bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define INF ((1LL<<62LL) - 1)

const int N = 1e5 + 5;
vector<pair<int,int> > g[N];
bool processed[N];
int dist[N];

int n,m;

/*
 Dijkstra algorithm

 add {-distance, node_number} in priority queue to get Node with minimum distance.
*/
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

    priority_queue<pair<int,int> > q;

    q.push({0,1});

    while(!q.empty()){
        int cur_node = q.top().second;
        q.pop();
        if(processed[cur_node]) continue;
        processed[cur_node] = true;

        for(pair<int,int> p : g[cur_node]){
            int b = p.first;
            int w = p.second;

            if(dist[cur_node] + w < dist[b]){
                dist[b] = dist[cur_node] + w;
                q.push({-dist[b], b});
            }
        }
    }

    for(int i=1;i<=n;i++){
        cout << dist[i] << " ";
    }
    cout << "\n";

}
