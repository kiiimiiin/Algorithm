#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int board[102][102];
int vis[102][102];
vector<int> square_area;
int m, n, k;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    
    cin >> m >> n >> k;
    while(k--)
    {
        int x_left, y_left, x_right, y_right;
        cin >> x_left >> y_left >> x_right >> y_right;
        for(int y = y_left ; y < y_right ; y++)
            for(int x = x_left; x < x_right; x++)
                board[y][x] = -1;
    }
    /* for(int y = m-1; y >= 0 ; y--)
    {
        for(int x = 0; x < n; x++)
            cout << board[y][x] << ' ';
        cout << '\n';
    } */
    
    queue<pair<int,int>> Q;
    for(int y = 0; y < m; y++)
    {
        for(int x = 0; x < n; x++)
        {
            if(board[y][x] == 0 && vis[y][x] == 0)
            {
                int area = 0;
                vis[y][x] = 1;
                Q.push({x,y});
                while(!Q.empty())
                {
                    area++;
                    auto cur = Q.front(); Q.pop();
                    for(int dir = 0 ; dir < 4 ; dir++)
                    {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                        if(board[ny][nx] == -1 || vis[ny][nx]) continue;
                        vis[ny][nx] = 1;
                        Q.push({nx,ny});
                    }
                } // bfs 
                square_area.push_back(area);
            }
        }
    }
    sort(square_area.begin(), square_area.end());
    cout << square_area.size() << '\n';
    for(auto i : square_area)
        cout << i << ' ';
}
