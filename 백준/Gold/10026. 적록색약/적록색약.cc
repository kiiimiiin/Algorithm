#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
char board[101][101];
bool vis[101][101];
int n;
int dx[4] = { 1, 0, -1, 0};
int dy[4] = { 0, 1, 0, -1};

void bfs(int i, int j)
{
    queue<pair<int, int>> Q;
    vis[i][j] = 1;
    Q.push({i,j});
    while(!Q.empty())
    {
        auto cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 4 ; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(vis[nx][ny] == 1 || board[nx][ny] != board[cur.X][cur.Y]) continue; //같은 색이 아님
            vis[nx][ny] = 1;
            Q.push({nx,ny});            
        }
    }
}

int area()
{
    int cnt = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0 ; j < n; j++)
        {
            if(!vis[i][j])
            {
                cnt++;
                bfs(i,j); // 방문하지 않은 영역에 대해 bfs 
            }
        }
    }
    return cnt;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for(int i = 0 ; i < n; i++)
        for(int j = 0; j <n; j++)
            cin >> board[i][j];
    
    int not_g = area(); // 일반인에 대한 그림 영역 수 
    
    for(int i = 0; i < n ; i++) fill(vis[i], vis[i] + n, 0); //방문영역 초기화
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(board[i][j] == 'G')
                board[i][j] = 'R'; // R,G를 같게함
        }
    }

    int is_g = area(); // 적록색약에 대한 그림 영역 수 
    cout << not_g << " " << is_g;
}