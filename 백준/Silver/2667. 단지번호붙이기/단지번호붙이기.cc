#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
string board[25];
int vis[25][25];
int n;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
vector<int> houseNum;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for(int i = 0 ; i < n; i++) cin >> board[i];
    
    queue<pair<int,int>> Q;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(board[i][j] == '1' && !vis[i][j]) // 집이 존재하면서, 방문한 이력 없음
            {
                int cnt = 0; // 집의 수 
                vis[i][j] = true;
                Q.push({i,j});
                while(!Q.empty())
                {
                    cnt++;
                    auto cur = Q.front(); Q.pop();
                    for(int dir = 0; dir < 4; dir++)
                    {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                        if(board[nx][ny] == '0' || vis[nx][ny]) continue; 
                        vis[nx][ny] = true;
                        Q.push({nx,ny});
                    }
                }
                houseNum.push_back(cnt);
            }
        }
    }
    sort(houseNum.begin(), houseNum.end());
    cout << houseNum.size() << '\n';
    for(auto i : houseNum)
        cout << i << '\n';
}