#include<bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define INF ((1LL<<62LL) - 1)

const int N = 1e5 + 5;
vector<pair<int,int> > g[N];
int processed[N];
int dist[N];

int n,m,k;

priority_queue<pair<int,int> > q;


/*
 * Dijkstra for first K smallest paths.
 */
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;

    for(int i=1;i<=m;i++){
        int u,v,w; cin >> u >> v >> w;
        g[u].push_back({v,w});
    }

    for(int i=1;i<=n;i++){
        dist[i] = INF;
    }

    vector<int> ans;

    dist[1] = 0;
    q.push({0,1});
    // {-d,node} d is the cost to reach node.
    // we first get d in increasing order.
    // so take first k d's where node == n.
    // and any node can't be processed more than k times.

    while(!q.empty()){
        int u = q.top().second;
        int far = -q.top().first;
        q.pop();

        processed[u]++;

        if(u == n && processed[u] <= k){
            ans.push_back(far);
        }

        if(processed[u] <= k) {
            for (pair<int, int> p : g[u]) {
                int v = p.first;
                int w = p.second;

                q.push({-(far + w), v});
            }
        }
    }

    for(int x : ans){
        cout << x << " ";
    }
    cout << "\n";



}
