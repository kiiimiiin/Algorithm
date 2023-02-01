#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second 
// RGB로 그림구분
// 적록색약 RG , B | 일반인 R,G,B 그림 영역 구분
// B를 먼저 돌려서 B 영역수  -> R, G를 나눠서 돌림 -> R,G를 합쳐서 돌림 
string board[102];
int n;
int dx[4] = { 1, 0, -1, 0};
int dy[4] = { 0, 1, 0, -1};
int vis[102][102];

int colorNumBfs(char colorName)
{
    int Num = 0;
    queue<pair<int,int>> color;
    for(int i = 0 ; i < n; i++) // 색에 대한 bfs
    {
        for(int j = 0; j < n; j++)
        {
            if(board[i][j] == colorName && vis[i][j] == 0)
            {
                Num++;
                vis[i][j] = 1;
                color.push({i,j});
                while(!color.empty())
                {
                    auto cur = color.front(); color.pop();
                    for(int dir = 0; dir < 4 ; dir++)
                    {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                        if(board[nx][ny] != colorName || vis[nx][ny] == 1) continue;
                        vis[nx][ny] = 1;
                        color.push({nx,ny}); 
                    }
                }
            }
        }
    }
    return Num;
}
int redgreenBfs()
{
    int Num = 0;
    queue<pair<int,int>> color;
    for(int i = 0 ; i < n; i++) 
    {
        for(int j = 0; j < n; j++)
        {
            if((board[i][j] == 'R'|| board[i][j] == 'G') && vis[i][j] == 0)
            {
                Num++;
                vis[i][j] = 1;
                color.push({i,j});
                while(!color.empty())
                {
                    auto cur = color.front(); color.pop();
                    for(int dir = 0; dir < 4 ; dir++)
                    {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                        if(board[nx][ny] == 'B' || vis[nx][ny] == 1) continue;
                        vis[nx][ny] = 1;
                        color.push({nx,ny}); 
                    }
                }
            }
        }
    }
    return Num;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    
    cin >> n;
    for(int i = 0 ; i < n; i++) cin >> board[i];
    int redNum = colorNumBfs('R');
    int greenNum = colorNumBfs('G');
    int blueNum = colorNumBfs('B');
    for(int i = 0 ; i < 102 ; i++) fill(vis[i], vis[i] + 102, 0);
    int redgreenNum = redgreenBfs();

    cout << blueNum + redNum + greenNum << ' ' << redgreenNum + blueNum ;
}