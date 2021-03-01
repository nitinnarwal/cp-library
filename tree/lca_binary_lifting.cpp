#include<bits/stdc++.h>
using namespace std;
//#define int long long
#define M 1000000007
#define INF ((1LL<<30LL) - 1)

const int N = 1e5 + 5;
const int LOGN = 20;

vector<int> g[N];
int par[N][LOGN];
int depth[N];

void dfs(int node, int from){
    par[node][0] = from;
    
    for(int x : g[node]){
        if(x != from){
            depth[x] = depth[node] + 1;
            dfs(x, node);
        }
    }
}

void calc_par(){
    for(int bit=1;bit<LOGN;bit++){
        for(int i=1;i<N;i++){
            if(par[i][bit-1] != -1){
                par[i][bit] = par[par[i][bit-1]][bit-1];
            }
        }
    }
}

int lca(int a, int b){
    if(depth[a] > depth[b]){
        swap(a, b);
    }
    
    int lift = depth[b] - depth[a];
    
    for(int i=0;i<LOGN;i++){
        if((lift>>i)&1){
            b = par[b][i];
        }
    }
    
    if(a == b){
        return a;
    }
    
    for(int i = LOGN-1;i>=0;i--){
        if(par[a][i] != par[b][i]){
            a = par[a][i];
            b = par[b][i];
        }
    }

    return par[a][0];
}

int dist(int a, int b){
    return depth[a] + depth[b] - 2*depth[lca(a, b)];
}

void init_lca_calc(){
    for(int i=1;i<N;i++){
        depth[i] = 0;
        for(int j = 0;j<LOGN;j++){
            par[i][j] = -1;
        }
    }

    dfs(1, -1);
    calc_par();
}



// Problem related code

int ans[N];
bool vis[N];
vector<int> reds;

void bfs(){

    for(int i=1;i<N;i++){
        ans[i] = INF;
        vis[i] = false;
    }

    queue<int> q;
    for(int x : reds){
        ans[x] = 0;
        q.push(x);
        vis[x] = true;
    }

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int x : g[u]){
            if(!vis[x]){
                ans[x] = ans[u] + 1;
                vis[x] = true;
                q.push(x);
            }
        }
    }

}


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m; cin >> n >> m;

    for(int i=1;i<=n-1;i++){
        int u,v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    init_lca_calc();



    // problem related code

    int Z = sqrt(m) + 1;
    reds.push_back(1);


    for(int i=0;i<m;i++){
        if(i%Z == 0){
            bfs();
        }

        int type, node; cin >> type >> node;

        if(type == 1){
            reds.push_back(node);
        } else {

            int temp = ans[node];
            for(int j = 0;j<Z;j++){
                int ind = reds.size() - 1 - j;
                if(ind < 0) break;

                temp = min(temp, dist(node, reds[ind]));
            }

            cout << temp << "\n";

        }
    }


}
