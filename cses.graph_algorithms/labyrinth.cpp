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
char dir[] = {'D','U','R','L'};
int from_x[N][N], from_y[N][N];
char from_dir[N][N];

int n,m;

bool inside(int x, int y){
    return x>=1 && x<=n && y>=1 && y<=m;
}

/*
 BFS on Grid with storing paths.

 */
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int start_x=0,start_y=0,end_x=0,end_y=0;

    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> c[i][j];
            if(c[i][j] == 'A'){
                start_x = i;
                start_y = j;
            } else if(c[i][j] == 'B'){
                end_x = i;
                end_y = j;
            }
        }
    }

    queue<pair<int,int> > q;
    q.push({start_x, start_y});
    vis[start_x][start_y] = true;

    bool found_b = false;

    while(!q.empty()){
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        q.pop();

        if(cur_x == end_x && cur_y == end_y){
            found_b = true;
            break;
        }

        for(int i=0;i<4;i++){
            int nx = cur_x + dx[i];
            int ny = cur_y + dy[i];

            if(inside(nx, ny) && !vis[nx][ny] && c[nx][ny] != '#'){
                vis[nx][ny] = true;
                from_x[nx][ny] = cur_x;
                from_y[nx][ny] = cur_y;
                from_dir[nx][ny] = dir[i];

                q.push({nx,ny});
            }
        }

    }

    if(found_b){
        cout << "YES\n";

        int cur_x = end_x;
        int cur_y = end_y;

        string ans = "";
        while(cur_x != start_x || cur_y != start_y){
            //cout << cur_x << "," << cur_y << "  from  " << from_x[cur_x][cur_y] << "," << from_y[cur_x][cur_y] << "  dir: " << from_dir[cur_x][cur_y] << "\n";

            ans.push_back(from_dir[cur_x][cur_y]);
            int nx = from_x[cur_x][cur_y];
            int ny = from_y[cur_x][cur_y];

            cur_x = nx;
            cur_y = ny;
        }

        reverse(ans.begin(), ans.end());

        cout << ans.size() << "\n" << ans << "\n";

    } else {
        cout << "NO\n";
    }



}
