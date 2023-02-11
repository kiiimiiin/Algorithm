#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
//3차원 배열 bfs 
string board[32][32];
int dist[32][32][32];
int dx[6] = {1, 0, -1 , 0, 0, 0};
int dy[6] = {0, 1, 0, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};
int l, r, c;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> l >> r >> c;
    queue<tuple<int,int,int>> Q;
    while(l && r && c)
    {

        for(int i = 0; i < l ; i++)
        {
            for(int j = 0; j < r; j++)
            {
                fill(dist[i][j], dist[i][j] + c, -1); // 방문이력 초기화
                cin >> board[i][j];
                for(int k = 0; k < c ; k++)
                {
                    if(board[i][j][k] == 'S')
                    {
                        dist[i][j][k] = 0; // 상범이의 시작점
                        Q.push({i,j,k}); // z , x , y
                    }
                }
            }
        }
        
        while(!Q.empty())
        {
            auto cur = Q.front(); Q.pop();
            int curZ, curX, curY;
            tie(curZ, curX, curY) = cur;
            for(int dir = 0; dir < 6 ; dir++)
            {   
                int nz = curZ + dz[dir];
                int nx = curX + dx[dir];
                int ny = curY + dy[dir];
                if(nz < 0 || nz >= l || nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
                if(board[nz][nx][ny] == '#' || dist[nz][nx][ny] >= 0) continue;
                dist[nz][nx][ny] = dist[curZ][curX][curY] + 1;
                Q.push({nz, nx, ny}); 
            }
        } // bfs
        
        for(int i = 0; i < l ; i++)
        {
            for(int j = 0 ; j < r ; j++)
            {
                for(int k = 0; k < c ; k++)
                {
                    if(dist[i][j][k] >= 0 && board[i][j][k] == 'E')
                        cout << "Escaped in " << dist[i][j][k] << " minute(s).\n";
                    if(dist[i][j][k] < 0 && board[i][j][k] == 'E')
                        cout <<  "Trapped!\n" ;
                }
            }
        }
        cin >> l >> r  >> c;
    }
}