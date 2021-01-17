#include<bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define INF ((1LL<<62LL) - 1)

const int N = 2e5 + 5;
const int LOGN = 31;
int g[N][LOGN];

int n,q;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;
    for(int i=1;i<=n;i++){
        cin >> g[i][0];
    }

    for(int i=1;i<LOGN;i++){
        for(int j=1;j<=n;j++){
            int half = g[j][i-1];
            g[j][i] = g[half][i-1];
        }
    }

    while(q--){
        int u,k; cin >> u >> k;

        for(int bit = LOGN - 1;bit>=0;bit--){
            if((k >> bit) & 1){
                u = g[u][bit];
            }
        }

        cout << u << "\n";
    }


}



