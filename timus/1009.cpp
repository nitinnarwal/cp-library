#include<bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define INF ((1LL<<62LL) - 1)

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,k; cin >> n >> k;

    int dp[n][2];

    dp[0][0] = 0; // ending with ZERO
    dp[0][1] = k-1; // ending with NON-ZERO

    for(int i=1;i<n;i++){
        dp[i][0] = dp[i-1][1];
        dp[i][1] = (k-1)*(dp[i-1][0] + dp[i-1][1]);
    }

    cout << dp[n-1][0] + dp[n-1][1] << "\n";



}
