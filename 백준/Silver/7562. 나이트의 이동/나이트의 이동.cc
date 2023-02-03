#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int dist[300][300];
int dx[8] = { -2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = { 1, 2, 2, 1, -1, -2, -2, -1};
int l, t;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> t ;
    while(t--)
    {
        cin >> l;
        for(int i = 0 ; i < l ; i++) fill(dist[i], dist[i] + l, -1); // 방문이력 없음
        int x, y, dest_x, dest_y;
        cin >> x >> y >> dest_x >> dest_y;
        queue<pair<int, int>> Q;
        dist[x][y] = 0;
        Q.push({x,y});
        while(dist[dest_x][dest_y] == -1)
        {
            auto cur = Q.front(); Q.pop();
            for(int dir = 0; dir < 8 ; dir++)
            {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(nx < 0 || nx >= l || ny < 0 || ny >= l) continue;
                if(dist[nx][ny] >= 0) continue;
                dist[nx][ny] = dist[cur.X][cur.Y] + 1;
                Q.push({nx,ny});
            }
        }
        cout << dist[dest_x][dest_y] << '\n';
    }       
}