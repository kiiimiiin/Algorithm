#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[1002][1002];
int n, m;
int dx[4] = { 1, 0 , -1 , 0};
int dy[4] = { 0, 1, 0, -1};
int dist[1002][1002];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    queue<pair<int,int>> Q;
    cin >> m >> n;
    for(int i = 0; i < n; i++) fill(dist[i], dist[i] + m ,-1); 
    // dist를 -1로 채워줌으로써 지나가지 않은 칸에 대한 처리
    for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                cin >> board[i][j];
                if(board[i][j] == 1)
                    {
                        dist[i][j] = 0;
                        Q.push({i,j}); // 시작점 지정
                    }
            }
        }

    while(!Q.empty())
    {
        auto cur = Q.front(); Q.pop(); 
        for(int dir = 0 ; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if( nx < 0 || nx >= n || ny < 0 || ny >= m) continue; // 범위벗어남
            if( board[nx][ny] == -1 || dist[nx][ny] >= 0) continue;  // 토마토없거나 이미 처리된 칸
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            Q.push({nx,ny});
        }
    }

    int minDate = 0;
    for(int i = 0; i < n ; i++)
        {
            for(int j = 0; j < m ; j++)
            {
                if(dist[i][j] == -1 && board[i][j] == 0)
                    {
                        cout << -1;
                        return 0;
                    }
                minDate = max(dist[i][j], minDate);
            }
        }
    cout << minDate;
} // O(NM)