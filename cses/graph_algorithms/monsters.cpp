#include<bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define INF ((1LL<<62LL) - 1)

const int N = 1005;
char g[N][N];
bool vis[N][N];
pair<int,int> from[N][N];
char from_dir[N][N];
int steps[N][N];

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
char dir[] = {'D', 'U', 'R', 'L'};

int n,m;

bool inside(int x, int y){
    return x >= 1 && x<=n && y>=1 && y<=m;
}

/*
BFS from multiple sources on GRID.

 */
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    queue<pair<int,int> > monsters;
    queue<pair<int,int> > me;

    pair<int,int> start;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> g[i][j];
            if(g[i][j] == 'M'){
                monsters.push({i,j});
                vis[i][j] = true;
            } else if(g[i][j] == 'A'){
                me.push({i,j});
                vis[i][j] = true;
                start = {i,j};
            }
        }
    }

    bool found = false;

    for(int for_step = 0;for_step<n*m;for_step++){

        while(!monsters.empty()){
            int cur_x = monsters.front().first;
            int cur_y = monsters.front().second;

            //cout << "monsters visited " << cur_x << "," << cur_y << "\n";

            if(steps[cur_x][cur_y] == for_step){
                monsters.pop();

                for(int i=0;i<4;i++){
                    int nx = cur_x + dx[i];
                    int ny = cur_y + dy[i];

                    if(inside(nx, ny) && !vis[nx][ny] && g[nx][ny] != '#'){
                        vis[nx][ny] = true;
                        from[nx][ny] = {cur_x, cur_y};
                        from_dir[nx][ny] = dir[i];
                        steps[nx][ny] = for_step + 1;

                        monsters.push({nx,ny});
                    }
                }
            } else {
                break;
            }
        }

        while(!me.empty()){
            int cur_x = me.front().first;
            int cur_y = me.front().second;


            //cout << "me visited " << cur_x << "," << cur_y << "\n";

            if(cur_x == n || cur_y == m || cur_x == 1 || cur_y == 1){
                string ans = "";
                while(cur_x != start.first || cur_y != start.second){
                    ans.push_back(from_dir[cur_x][cur_y]);
                    pair<int,int> p = from[cur_x][cur_y];
                    cur_x = p.first;
                    cur_y = p.second;
                }

                reverse(ans.begin(), ans.end());

                cout << "YES\n";
                cout << ans.size() << "\n";
                cout << ans << "\n";
                return 0;

            }
            if(steps[cur_x][cur_y] == for_step){
                me.pop();

                for(int i=0;i<4;i++){
                    int nx = cur_x + dx[i];
                    int ny = cur_y + dy[i];

                    if(inside(nx, ny) && !vis[nx][ny] && g[nx][ny] != '#'){
                        vis[nx][ny] = true;
                        from[nx][ny] = {cur_x, cur_y};
                        from_dir[nx][ny] = dir[i];
                        steps[nx][ny] = for_step + 1;

                        me.push({nx,ny});
                    }
                }
            } else{
                break;
            }
        }

    }

    cout << "NO\n";

}

/*
8 8
########
#.....A#
#.######
#......#
#.####.#
#....#.#
#.##.#.#
#.#M.#.#

8 8
########
#......#
#.######
#A.....#
#M####.#
#....#.#
#.##.#.#
#.#M.#.#

8 8
########
#......#
#A######
#......#
#.####.#
#M...#.#
#.##.#.#
#.#M.#.#

 */