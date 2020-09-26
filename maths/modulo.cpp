#include<bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define INF ((1LL<<62LL) - 1)

void mul(int& a, int b){
    a = (a*b)%M;
}

void add(int& a, int b){
    a = (a+b)%M;
}

int po(int x, int y){
    if(y == 0) return 1;
    if(y == 1) return x;

    int temp = po(x, y/2);
    mul(temp, temp);

    if(y&1) mul(temp, x);
    return temp;
}

const int N = 3e5 + 5;

int fact[N];
void init(){
    fact[0] = 1;
    for(int i=1;i<N;i++){
        fact[i] = fact[i-1]*i;
        fact[i]%=M;
    }
}

int ncr(int n, int r){
    int temp = fact[n];
    int temp2 = fact[r];
    int temp3 = fact[n-r];
    mul(temp2, temp3);

    mul(temp, po(temp2, M-2));
    return temp;
}


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);




}
