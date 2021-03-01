#include<bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define INF ((1LL<<62LL) - 1)

const int N = 105;
vector<int> g[N];
bool vis[N];
vector<int> topo;

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

    int n; cin >> n;

    for(int i=1;i<=n;i++){
        int x;
        while(cin >> x){
            if(x == 0) break;
            g[i].push_back(x);
        }
    }

    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i);
        }
    }

    reverse(topo.begin(), topo.end());

    for(int x : topo) cout << x << " ";

    cout << "\n";



}
