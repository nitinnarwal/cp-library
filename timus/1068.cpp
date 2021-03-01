#include<bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define INF ((1LL<<62LL) - 1)

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    int x = abs(n);

    x = (x*(x+1))/2;

    if(n<0){
        x = -x + 1;
    }
    if(n == 0) x = 1;

    cout << x << "\n";



}
