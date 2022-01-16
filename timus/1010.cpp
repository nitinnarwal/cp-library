#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;
#define int long long
const int M = 1e9 + 7;
const int INF = 1e18 + 5;

void solve(){
    int n; cin >> n;
    int a[n + 1];
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    int diff = 0;
    int ans = -1;

    for(int i = 1; i + 1 <= n; i++){
        if(abs(a[i + 1] - a[i]) > diff){
            diff = abs(a[i + 1] - a[i]);
            ans = i;
        }
    }

    cout << ans << " " << ans + 1 << "\n";

}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}