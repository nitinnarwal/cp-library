#include<bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define INF ((1LL<<62LL) - 1)

const int N = 1e5 + 5;
vector<int> g[N];
int col[N];
int from[N];

int n,m;

vector<int> cycle;

bool dfs(int node, int par){
    col[node] = 1;
    from[node] = par;

    for(int x : g[node]){
        if(x == par) continue;
        if(col[x] == 1){
            // cycle found
            cycle.push_back(x);
            int cur = node;
            while(cur != x){
                cycle.push_back(cur);
                cur = from[cur];
            }
            cycle.push_back(x);
            return true;
        } else if(col[x] == 0){
            if(dfs(x, node)){
                return true;
            }
        }
    }

    col[node] = 2;
    return false;
}

/*
 Base Cycle detection
 *
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

    bool found = false;
    for(int i=1;i<=n;i++){
        if(col[i] == 0){
            if(dfs(i, 0)){
                found = true;
                break;
            }
        }
    }

    if(found){
        reverse(cycle.begin(), cycle.end());
        cout << cycle.size() << "\n";
        for(int x : cycle){
            cout << x << " ";
        }
        cout << "\n";
    } else {
        cout << "IMPOSSIBLE\n";
    }


}
