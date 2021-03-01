#include<bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define INF ((1LL<<62LL) - 1)

const int N = 1e7 + 105;
bool prime[N];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i=2;i<N;i++){
        prime[i] = true;
    }

    vector<int> ans;

    for(int i=2;i<N;i++){
        if(prime[i]) {
            ans.push_back(i);
            for (int j = 2 * i; j < N; j += i) {
                prime[j] = false;
            }
        }
    }

    int n; cin >> n;
    while(n--){
        int x; cin >> x;
        x--;
        cout << ans[x] << "\n";
    }



}
