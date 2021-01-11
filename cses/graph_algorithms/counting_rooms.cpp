#include<bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define INF ((1LL<<62LL) - 1)

const int N = 1005;
char c[N][N];
bool vis[N][N];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

int n,m;


bool inside(int x, int y){
    return x>=1 && x<=n && y>=1 && y<=m;
}

void dfs(int x, int y){
    vis[x][y] = true;
    for(int i=0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(inside(nx, ny) && !vis[nx][ny] && c[nx][ny] == '.'){
            dfs(nx, ny);
        }
    }
}

/*
 Connected components counting on GRID

 */

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> c[i][j];
        }
    }

    int rooms = 0;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(c[i][j] == '.' && !vis[i][j]){
                rooms++;
                dfs(i,j);
            }
        }
    }

    cout << rooms << "\n";



}
