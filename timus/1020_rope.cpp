#include<bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define INF ((1LL<<62LL) - 1)
#define PI 3.141592653589793238


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    double r;
    cin >> n >> r;
    double a[n],b[n];
    for(int i=0;i<n;i++){
        cin >> a[i] >> b[i];
    }

    double ans = 2*PI*r;

    for(int i=0;i<n;i++){
        double x = a[i] - a[(i+1)%n];
        x*=x;
        double y = b[i] - b[(i+1)%n];
        y*=y;
        x+=y;
        x = sqrt(x);

        ans+=x;
    }

    cout << fixed << setprecision(2) << ans << "\n";



}
