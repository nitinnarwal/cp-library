#include<bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define INF ((1LL<<62LL) - 1)

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    string s; cin >> s;
    int k = s.size();

    int ans = 1;
    int cur = n;
    while(cur > n%k){
        ans *= cur;
        cur -= k;
    }
    if(cur > 0) ans*=cur;

    cout << ans << "\n";



}
