#include<bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define INF ((1LL<<62LL) - 1)

const int N = 505;
int g[N][N];
int dist[N][N];
int n;

void floyd_warshall(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dist[i][j] = g[i][j];
        }
    }

    for(int k=1;k<=n;k++){ // through
        for(int i=1;i<=n;i++){ // source
            for(int j=1;j<=n;j++){ // destination
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> g[i][j];
        }
    }

    floyd_warshall();



}
