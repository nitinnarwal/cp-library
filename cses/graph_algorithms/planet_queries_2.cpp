#include<bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define INF ((1LL<<62LL) - 1)

const int N = 2e5 + 5;
vector<int> g_inv[N];
vector<int> adj[N];
int t[N];
bool is_cycle[N];
int pos_in_cycle[N];
int comp[N], depth[N];
vector<int> cycle[N];
bool vis[N];
int root[N];
const int LOGN = 30;
int par[N][LOGN];

int n,q;
int cur_comp = 0;


void dfs_comp(int node){
    comp[node] = cur_comp;

    for(int x : adj[node]){
        if(comp[x] == -1){
            dfs_comp(x);
        }
    }
}

void calc_comp(){
    for(int i=1;i<=n;i++){
        comp[i] = -1;
    }

    for(int i=1;i<=n;i++){
        if(comp[i] == -1){
            cur_comp++;
            dfs_comp(i);
        }
    }
}

void calc_cycle(){
    bool is_comp_processed[N];
    memset(is_comp_processed, false, sizeof(is_comp_processed));

    for(int i=1;i<=n;i++){
        if(is_comp_processed[comp[i]]){
            continue;
        }
        is_comp_processed[comp[i]] = true;

        int slow = t[i];
        int fast = t[slow];
        while(slow != fast){
            slow = t[slow];
            fast = t[t[fast]];
        }
        slow = i;
        while(slow != fast){
            slow = t[slow];
            fast = t[t[fast]];
        }

        int cycle_start = slow;
        cycle[comp[i]].push_back(slow);
        while(t[cycle_start] != slow){
            cycle_start = t[cycle_start];
            pos_in_cycle[cycle_start] = cycle[comp[i]].size();
            cycle[comp[i]].push_back(cycle_start);
        }

        for(int x : cycle[comp[i]]){
            is_cycle[x] = true;
        }
    }
}

void dfs_depth(int node, int d, int r){
    vis[node] = true;
    depth[node] = d;
    root[node] = r;
    for(int x : g_inv[node]){
        if(!vis[x] && !is_cycle[x]){
            dfs_depth(x, d+1, r);
        }
    }
}

void calc_depth(){
    for(int i=1;i<=cur_comp;i++){
        for(int node : cycle[i]){
            if(!vis[node]){
                dfs_depth(node, 0, node);
            }
        }
    }
}

void calc_parents(){
    for(int i=1;i<=n;i++){
        par[i][0] = t[i];
    }
    for(int i=1;i<LOGN;i++){
        for(int j=1;j<=n;j++){
            int temp = par[j][i-1];
            par[j][i] = par[temp][i-1];
        }
    }
}

int get_par(int node, int d){
    if(d<0) return 0;
    for(int bit = 0;bit<LOGN;bit++){
        if((d>>bit)&1){
            node = par[node][bit];
        }
    }

    return node;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;
    for(int i=1;i<=n;i++){
        cin >> t[i];
        g_inv[t[i]].push_back(i);
        adj[i].push_back(t[i]);
        adj[t[i]].push_back(i);
    }
    calc_comp();
    calc_cycle();
    calc_depth();
    calc_parents();

    while(q--){
        int a,b; cin >> a >> b;

        if(comp[a] != comp[b]){
            cout << "-1\n";
        } else {
            if(is_cycle[a]){
                if(is_cycle[b]){
                    cout << (pos_in_cycle[b] - pos_in_cycle[a] + cycle[comp[a]].size()) % cycle[comp[a]].size() << "\n";
                } else {
                    cout << "-1\n";
                }
            } else {
                if(is_cycle[b]){
                    int ans = (pos_in_cycle[b] - pos_in_cycle[root[a]] + cycle[comp[a]].size()) % cycle[comp[a]].size();
                    ans += depth[a];
                    cout << ans << "\n";
                } else {
                    if(root[a] != root[b]){
                        cout << "-1\n";
                    } else {
                        if(get_par(a, depth[a] - depth[b]) == b){
                            cout << depth[a] - depth[b] << "\n";
                        } else {
                            cout << "-1\n";
                        }
                    }
                }
            }
        }
    }



}
