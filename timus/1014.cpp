#include<bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define INF ((1LL<<62LL) - 1)

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    if(n == 0){
        cout << 10 << "\n";
    } else if(n == 1){
        cout << 1 << "\n";
    } else {
        string ans = "";
        int cur = n;
        for(int i=0;i<40;i++){
            for(int j=9;j>=2;j--){
                if(cur%j==0){
                    ans.push_back('0' + j);
                    cur/=j;
                    break;
                }
            }
            if(cur == 1){
                break;
            }
        }

        if(cur>1){
            cout << "-1\n";
        } else {
            reverse(ans.begin(), ans.end());
            cout << ans << "\n";
        }
    }



}
