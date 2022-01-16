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

void solve2() {
    long double p, q; cin >> p >> q;

//    p /= 100.0;
//    q /= 100.0;

    for(int i = 1; i < INF; i++){
        int l = 1;
        int h = i;
        while(l < h){
            int m = l + (h - l) / 2;

            long double pp = (m * 100.0L) / i;

            if(pp > p){
                h = m;
            } else {
                l = m + 1;
            }
        }

        long double pp = (l * 100.0L) / i;

        if(pp < q){
            cout << i << "\n";
            return;
        }
    }
}


void solve(){
    long double p, q; cin >> p >> q;

    p /= 100.0;
    q /= 100.0;

    int lo = 1;
    int hi = INF;

    while(lo < hi) {
        int mid = lo + (hi - lo) / 2;

        int l = 1;
        int h = mid;
        while(l < h){
            int m = l + (h - l) / 2;

            long double pp = (m * 1.0L) / mid;

            if(pp >= p){
                h = m;
            } else {
                l = m + 1;
            }
        }

        long double pp = (l * 1.0L) / mid;

        if(pp >= p && pp <= q){
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }

    cout << lo << "\n";

}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    //cin >> t;
    while(t--){
        solve2();
    }
    return 0;
}