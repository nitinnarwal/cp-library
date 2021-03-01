#include<bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define INF ((1LL<<62LL) - 1)

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<double> v;
    double a;
    while(cin >> a){
        v.push_back(sqrt(a));
    }

    reverse(v.begin(), v.end());

    for(double x : v){
        cout << fixed << setprecision(4) << x << "\n";
    }



}
