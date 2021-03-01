#include<bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define INF ((1LL<<62LL) - 1)

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int n; cin >> n;
    n/=2;

    int limit = pow(10,n);

    map<int,int> mp;
    for(int i=0;i<limit;i++){
        int sum = 0;
        int cur = i;
        for(int j=0;j<n;j++){
            sum += cur%10;
            cur/=10;
        }
        mp[sum]++;
    }

    int ans = 0;
    for(pair<int,int> p : mp){
        ans += p.second*p.second;
    }

    cout << ans << "\n";




}
