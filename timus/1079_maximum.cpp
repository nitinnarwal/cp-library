#include<bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define INF ((1LL<<62LL) - 1)

const int N = 1e6 + 5;
int a[N];
int dp[N];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    a[1] = 1;

    for(int i=1;i<N;i++){
        if(i%2==0){
            a[i] = a[i/2];
        } else {
            a[i] = a[i/2] + a[(i+1)/2];
        }
        dp[i] = max(a[i], dp[i-1]);
    }

    int x;
    while(cin >> x){
        if(x == 0) break;
        cout << dp[x] << "\n";
    }




}
