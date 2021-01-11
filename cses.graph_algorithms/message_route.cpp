#include<bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define INF ((1LL<<62LL) - 1)

const int N = 1e5 + 5;

vector<int> g[N];
bool vis[N];
int from[N];

int n,m;

/*

 Simple BFS with Path tracking.

 */
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i=0;i<m;i++){
        int u,v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    queue<int> q;
    q.push(1);
    vis[1] = true;
    while(!q.empty()){
        int cur = q.front();
        q.pop();

        if(cur == n){
            break;
        }

        for(int x : g[cur]){
            if(!vis[x]){
                vis[x] = true;
                from[x] = cur;
                q.push(x);
            }
        }
    }

    if(vis[n]){
        vector<int> ans;
        int cur = n;
        while(cur != 1){
            ans.push_back(cur);
            cur = from[cur];
        }
        ans.push_back(cur);

        reverse(ans.begin(), ans.end());

        cout << ans.size() << "\n";
        for(int x : ans) cout << x << " ";
        cout << "\n";
    } else{
        cout << "IMPOSSIBLE\n";
    }


}
