#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
//비의 양에 따라 잠기지 않는 영역 개수의 최댓값
int board[100][100];
int vis[100][100];
int n, maxHeight, cntMax;
int dx[4] = {1, 0, -1 , 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> n;
    for(int i = 0 ; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> board[i][j];
            maxHeight = max(maxHeight, board[i][j]); // 건물 최대 높이
        }
    }
    
    for(int rainHeight = 0; rainHeight <= maxHeight; rainHeight++) // 비의 높이에 따른 분리 영역 계산
    {
        queue<pair<int,int>> Q;
        int cnt = 0; // 영역수 
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(board[i][j] <= rainHeight) board[i][j] = -1;
            } // 비보다 높이가 낮으면 침수
        }

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(board[i][j] != -1 && !vis[i][j])
                {
                    cnt++;
                    vis[i][j] = true;
                    Q.push({i,j});
                    while(!Q.empty())
                    {
                        auto cur = Q.front(); Q.pop();
                        for(int dir = 0 ; dir < 4 ; dir++)
                        {
                            int nx = cur.X + dx[dir];
                            int ny = cur.Y + dy[dir];
                            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                            if(board[nx][ny] == -1 || vis[nx][ny]) continue;
                            vis[nx][ny] = true;
                            Q.push({nx,ny});
                        }
                    }
                }
            }  
        }
        cntMax = max(cnt, cntMax);
        for(int i =0 ; i < n ; i++) fill(vis[i], vis[i] + n, 0); // 방문이력 초기화
    } // O(N^3)
    cout << cntMax;
}