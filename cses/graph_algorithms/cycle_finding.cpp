#include<bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define INF ((1LL<<62LL) - 1)

const int N = 2505;
vector<pair<int,int> > g[N];
int dist[N];
int from[N];

int n,m;

/*
 Negative Cycle Finding using Bellman-Ford

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

    for(int i=1;i<=n-1;i++){
        for(int u=1;u<=n;u++){
            for(pair<int,int> p : g[u]){
                int v = p.first;
                int w = p.second;

                if(dist[u] + w < dist[v]){
                    dist[v] = dist[u] + w;
                    from[v] = u;
                }
            }
        }
    }

    int start = -1;

    for(int u=1;u<=n;u++){
        for(pair<int,int> p : g[u]){
            int v = p.first;
            int w = p.second;

            if(dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
                from[v] = u;
                start = v;
                break;
            }
        }
        if(start != -1){
            break;
        }
    }

    if(start != -1) {

        //to make sure that start is in a cycle.
        for(int i=1;i<=n;i++){
            start = from[start];
        }

        vector<int> cycle;

        cycle.push_back(start);
        int cur = from[start];
        while (cur != start) {
            cycle.push_back(cur);
            cur = from[cur];
        }
        cycle.push_back(cur);

        reverse(cycle.begin(), cycle.end());

        cout << "YES\n";
        for(int x : cycle){
            cout << x << " ";
        }
        cout << "\n";
    } else{
        cout << "NO\n";
    }





}
