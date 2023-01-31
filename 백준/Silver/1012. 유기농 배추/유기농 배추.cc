#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

// 영역 갯수 구하기
int m, n, k;
int dx[4] = { 1, 0, -1, 0};
int dy[4] = { 0, 1, 0, -1};

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while(t--) // testCase
    {
        int board[52][52] = {};
        int vis[52][52] = {}; 
        queue<pair<int,int>> Q;

        cin >> m >> n >> k; // 가로 m, 세로 n 
        while(k--) // 배추위치
        {
            int x, y;
            cin >> x >> y;
            board[y][x] = 1;
        }

        int num = 0; // 지렁이 마릿수 ( 배추 영역수 )

        for(int i = 0 ; i < n; i++)
        {
            for(int j = 0; j < m ; j++)
            {
                if(board[i][j] && vis[i][j] == 0) // 방문하지 않은 배추 발견
                {
                    num++;
                    vis[i][j] = 1;
                    Q.push({i,j});
                    while(!Q.empty())
                    {
                        auto cur = Q.front(); Q.pop();
                        for(int dir = 0; dir < 4 ; dir++)
                        {
                            int nx = cur.X + dx[dir];
                            int ny = cur.Y + dy[dir];
                            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                            if(board[nx][ny] != 1 || vis[nx][ny]) continue;
                            vis[nx][ny] = 1;
                            Q.push({nx,ny});
                        }
                    }
                }
            }
        }
        cout << num << '\n';
    }
}