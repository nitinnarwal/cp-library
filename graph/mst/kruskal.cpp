#include<bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define INF ((1LL<<62LL) - 1)

vector<pair<int,pair<int,int> > > edges;

const int N = 2e5 + 5;

int par[N];
int sz[N];

int get_parent(int x){
    if(par[x] == x) return x;
    par[x] = get_parent(par[x]);
    return par[x];

}

bool same_comp(int a, int b){
    return get_parent(a) == get_parent(b);
}

void unite(int a, int b){
    if(same_comp(a, b)){
        return;
    }
    if(sz[a] < sz[b]){
        swap(a, b);
    }

    par[b] = a;
    sz[a] += sz[b];
}

int kruskal(){

    for(int i=0;i<N;i++){
        par[i] = i;
        sz[i] = 1;
    }
    sort(edges.begin(), edges.end());

    int ans = 0;

    for(pair<int, pair<int,int> > p : edges){
        int u = p.second.first;
        int v = p.second.second;

        if(!same_comp(u, v)){
            unite(u, v);
            ans += p.first;

             cout << u << " " << v << " " << p.first << "\n";
        }
    }

    return ans;
}

void generate_graph(int n){
    edges.clear();

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            edges.push_back(make_pair(i^j,  make_pair(i,j)));
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    for(int i=2;i<20;i++) {
        generate_graph(i);

        cout << i << " number of nodes\n" << kruskal() << "\n\n";
    }



}
