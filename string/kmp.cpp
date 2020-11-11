#include<bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define INF ((1LL<<62LL) - 1)

vector<int> kmp_lps(string s){
    int n = s.size();
    vector<int> lps(n, 0);

    int i = 0;
    int j = 1;
    while(j<n){
        if(s[i]==s[j]){
            lps[j] = i+1;
            i++; j++;
        }
        else{
            if(i==0){
                lps[j] = 0;
                j++;
            }
            else{
                i = lps[i-1];
            }
        }
    }

    return lps;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s; cin >> s;

    vector<int> lps = kmp_lps(s);
    for(int x : lps) cout << x << " ";
    cout << "\n";



}
