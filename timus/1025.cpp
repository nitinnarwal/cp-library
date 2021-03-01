#include<bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define INF ((1LL<<62LL) - 1)

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    int a[n];
    for(int i=0;i<n;i++) cin >> a[i];

    sort(a, a+n);

    int ans = 0;
    for(int i=1;i<=(n+1)/2;i++){
        ans += (a[i-1] + 1)/2;
    }

    cout << ans << "\n";



}
