#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[502][502];
int vis[502][502];
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int cntMax = 0; // 넓이 최댓값
    int picNum = 0; // 그림갯수
    queue<pair<int,int>> Q;

    cin >> n >> m;
    for(int i = 0 ; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {   
            int init;
            cin >> init;
            board[i][j] = init;
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if( board[i][j] && vis[i][j] != 1)
                {   
                    int cnt = 0; // 넓이
                    vis[i][j] = 1;
                    Q.push({i, j});
                    cnt++, picNum++;
                    while(!Q.empty())
                    {
                        pair<int, int> cur = Q.front(); Q.pop();
                        for(int dir = 0; dir < 4; dir++)
                        {
                            int nx = cur.X + dx[dir];
                            int ny = cur.Y + dy[dir];
                            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                            if(vis[nx][ny] || board[nx][ny] != 1) continue;
                            vis[nx][ny] = 1;
                            Q.push({nx,ny});
                            cnt++;
                        }
                    }
                    if(cnt > cntMax) cntMax = cnt;
                }
        }
    }
    cout << picNum << '\n' << cntMax ;
}