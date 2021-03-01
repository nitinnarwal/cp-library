#include<bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define INF ((1LL<<62LL) - 1)

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    set<int> s;
    for(int i=1;i<=n;i++){
        int x; cin >> x;
        s.insert(x);
    }

    bool found = false;
    int m; cin >> m;

    for(int i=1;i<=m;i++){
        int x; cin >> x;
        if(s.count(10000 - x) > 0) found = true;
    }

    if(found) cout << "YES\n";
    else cout << "NO\n";



}
