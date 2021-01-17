#include<bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define INF ((1LL<<62LL) - 1)

const int N = 505;
vector<int> g[N];
int dp[N][N];

int n,m,q;

/*
Floyd-Warshall Implementation

*/
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i == j){
                dp[i][j] = 0;
            } else {
                dp[i][j] = INF;
            }
        }
    }

    for(int i=1;i<=m;i++){
        int u,v,w; cin >> u >> v >> w;
        dp[u][v] = min(dp[u][v], w);
        dp[v][u] = min(dp[v][u], w);
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                dp[j][k] = min(dp[j][k], dp[j][i] + dp[i][k]);
            }
        }
    }

    while(q--){
        int u,v; cin >> u >> v;
        cout << (dp[u][v] == INF ? -1 : dp[u][v]) << "\n";
    }



}
