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

    sort(a,a+n);
    reverse(a, a+n);

    int ans = INF;
    for(int i=0;i<(1<<n);i++){
        int temp = 0;
        for(int j=0;j<n;j++){
            if((i>>j)&1){
                temp += a[j];
            } else {
                temp -= a[j];
            }
        }
        ans = min(ans, abs(temp));
    }

    cout << ans << "\n";



}
