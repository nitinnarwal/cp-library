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

int gcd(int a, int b){
    return b == 0 ? a : gcd(b, a % b);
}

struct SparseTableGcd{
    static const int MAXN = 3e5 + 5;
    static const int K = 25;
    int st[MAXN][K];
    int log[MAXN];
    int n;

    static int f(int x, int y){
        return gcd(x, y);
    }

    SparseTableGcd(const vector<int>& a){
        n = a.size();
        for(int i = 0; i < n; i++){
            st[i][0] = a[i];
        }

        for(int j = 1; j < K; j++){
            for(int i = 0; i + (1 << j) - 1 < n; i++){
                st[i][j] = f(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            }
        }

        log[1] = 0;
        for(int i = 2; i <= n; i++){
            log[i] = log[i / 2] + 1;
        }
    }

    int get(int l, int r) {
        int size = r - l + 1;
        int j = log[size];
        return f(st[l][j], st[r - (1 << j) + 1][j]);
    }
};

struct SparseTableMin{
    static const int MAXN = 3e5 + 5;
    static const int K = 25;
    int st[MAXN][K];
    int log[MAXN];
    int n;

    static int f(int x, int y){
        return min(x, y);
    }

    SparseTableMin(const vector<int>& a){
        n = a.size();
        for(int i = 0; i < n; i++){
            st[i][0] = a[i];
        }

        for(int j = 1; j < K; j++){
            for(int i = 0; i + (1 << j) - 1 < n; i++){
                st[i][j] = f(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            }
        }

        log[1] = 0;
        for(int i = 2; i <= n; i++){
            log[i] = log[i / 2] + 1;
        }
    }

    int get(int l, int r) {
        int size = r - l + 1;
        int j = log[size];
        return f(st[l][j], st[r - (1 << j) + 1][j]);
    }
};


void solve(){
    int n; cin >> n;
    vector<int> a(n);

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    auto stGcd = SparseTableGcd(a);
    auto stMin = SparseTableMin(a);

    int lo = 1;
    int hi = n;

    while(lo < hi) {
        int mid = (lo + hi + 1) / 2;

        bool ok = false;

        for(int i = 0; i + mid - 1 < n; i++){
            int l = i;
            int r = i + mid - 1;
            int gg = stGcd.get(l, r);
            int mm = stMin.get(l, r);

            if(gg == mm){
                ok = true;
                break;
            }
        }

        if(ok){
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }

    int range = lo;
    vector<int> ans;
    for(int i = 0; i + range - 1 < n; i++){
        int l = i;
        int r = i + range - 1;
        int gg = stGcd.get(l, r);
        int mm = stMin.get(l, r);

        if(gg == mm){
            ans.push_back(l + 1);
        }
    }

    cout << ans.size() << " " << range - 1 << "\n";
    for(int x : ans){
        cout << x << " ";
    }
    cout << "\n";

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
