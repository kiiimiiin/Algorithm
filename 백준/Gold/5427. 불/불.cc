#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
string board[1002];
int dist1[1002][1002]; // 불
int dist2[1002][1002]; // 인간
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    
    int t, y, x ;
    cin >> t;
    while(t--)
    {
        cin >> y >> x ; // 너비, 높이
        for(int i = 0; i < x ; i++) cin >> board[i];
        for(int i = 0; i < x ; i++) 
        {
            fill(dist1[i], dist1[i] + y, -1);
            fill(dist2[i], dist2[i] + y, -1); // 방문 이력 없음
        }
        
        queue<pair<int,int>> q1, q2;

        for(int i = 0; i < x; i++)
        {
            for(int j = 0; j < y; j++)
            {
                if(board[i][j] == '*')
                {
                    dist1[i][j] = 0;
                    q1.push({i,j}); // 불 시작점            
                }
                if(board[i][j] == '@') // 인간 시작점
                {
                    dist2[i][j] = 0;
                    q2.push({i,j});
                }
            }
        } 
        
        while(!q1.empty())
        {
            auto cur = q1.front(); q1.pop();
            for(int i = 0 ; i < 4; i++)
            {
                int nx = cur.X + dx[i];
                int ny = cur.Y + dy[i];
                if(nx < 0 || nx >= x || ny < 0 || ny >= y) continue;
                if(dist1[nx][ny] >= 0 || board[nx][ny] == '#') continue;
                dist1[nx][ny] = dist1[cur.X][cur.Y] + 1;
                q1.push({nx,ny});
            }
        }

        bool isescaped = false;
        while(!q2.empty())
        {
            auto cur = q2.front(); q2.pop();
            for(int i = 0 ; i < 4; i++)
            {
                int nx = cur.X + dx[i];
                int ny = cur.Y + dy[i];
                if(nx < 0 || nx >= x || ny < 0 || ny >= y) 
                {
                    cout << dist2[cur.X][cur.Y] + 1 << '\n';
                    while(!q2.empty()) q2.pop();
                    isescaped = true;
                    break;
                }
                if(dist2[nx][ny] >= 0 || board[nx][ny] == '#') continue;
                if(dist1[nx][ny] <= dist2[cur.X][cur.Y] + 1 && dist1[nx][ny] >= 0) continue;
                dist2[nx][ny] = dist2[cur.X][cur.Y] + 1;
                q2.push({nx,ny});
            } // 사람 bfs
        }

        if(!isescaped) cout << "IMPOSSIBLE\n";
    }
}
