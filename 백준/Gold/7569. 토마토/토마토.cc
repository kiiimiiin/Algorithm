#include <bits/stdc++.h>
using namespace std;
int board[100][100][100];
int dist[100][100][100];
int dx[6] = { 1, 0, -1, 0, 0, 0};
int dy[6] = { 0, 1, 0, -1 , 0, 0};
int dz[6] = { 0, 0, 0, 0, 1, -1};
int m, n , h;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    queue<tuple<int,int,int>> Q;
    cin >> m >> n >> h;
    for(int i = 0; i < h; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            fill(dist[i][j], dist[i][j] + m , -1); // 방문이력 없음
            for(int k = 0; k < m ; k++)
            {
                cin >> board[i][j][k];
                if(board[i][j][k] == 1)
                {
                    dist[i][j][k] = 0;
                    Q.push({i,j,k}); // 익은 토마토 시작점
                }
            }
        }
    }

    while(!Q.empty())
    {
        auto cur = Q.front(); Q.pop();
        int curX, curY, curZ;
        tie(curZ, curX, curY) = cur;
        for(int dir = 0; dir < 6; dir++)
        {
            int nx = curX + dx[dir];
            int ny = curY + dy[dir];
            int nz = curZ + dz[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h) continue;
            if( board[nz][nx][ny] != 0 || dist[nz][nx][ny] >= 0 ) continue; // 방문이력 존재
            dist[nz][nx][ny] = dist[curZ][curX][curY] + 1;
            Q.push({nz,nx,ny});
        }
    }

    int minDate = 0;
    for(int i = 0; i < h ; i++)
    {
        for(int j = 0 ; j < n; j++)
        {
            for(int k = 0 ; k < m; k++)
            {
                if(dist[i][j][k] == -1 && board[i][j][k] == 0) // 익지못한 토마토 존재
                {
                    cout << -1;
                    return 0;
                }
                if(dist[i][j][k] >= 0 && board[i][j][k] == 0) // 익은 토마토에 대한 익은 날짜 비교
                {
                    minDate = max(minDate, dist[i][j][k]);
                }
            }
        }
    }
    cout << minDate; 
}