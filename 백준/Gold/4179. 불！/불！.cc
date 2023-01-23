#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

string board[1002];
int dist1[1002][1002]; // 불 거리(시간)
int dist2[1002][1002]; // 지훈 거리(시간)
int r, c;
int dx[4] = { -1 , 0, 1 , 0};
int dy[4] = { 0, 1, 0, -1};

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> r >> c ;
    
    for(int i = 0 ; i < r ; i++) cin >> board[i];
    for(int i = 0 ; i < r ; i++)
    {
        fill(dist1[i], dist1[i] + c , -1);
        fill(dist2[i], dist2[i] + c , -1); // 방문 이력 없음
    }

    queue<pair<int,int>> Q1,Q2;
    for(int i = 0; i < r ; i++)
    {
        for(int j = 0 ; j < c ; j++)
        {
            if(board[i][j] == 'F')
            {
                dist1[i][j] = 0;
                Q1.push({i,j}); // 불 시작점
            }
            if(board[i][j] == 'J')
            {
                dist2[i][j] = 0;
                Q2.push({i,j}); // 지훈 시작점
            }
        }
    }
    while(!Q1.empty())
    {
        auto cur = Q1.front(); Q1.pop();
        for(int dir = 0; dir < 4 ; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            if(board[nx][ny] == '#' || dist1[nx][ny] >= 0) continue;
            dist1[nx][ny] = dist1[cur.X][cur.Y] + 1;
            Q1.push({nx,ny});
        }
    }
    while(!Q2.empty())
    {
        auto cur = Q2.front(); Q2.pop();
        for(int dir = 0; dir < 4 ; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= r || ny < 0 || ny >= c)
            { // 거리순으로 탐색하므로 가장 먼저 탈출했을 때의 시간 출력
                cout << dist2[cur.X][cur.Y] + 1;
                return 0;
            }
            if(board[nx][ny] == '#' || dist2[nx][ny] >= 0) continue;
            if(dist2[cur.X][cur.Y] + 1 >= dist1[nx][ny] && dist1[nx][ny] != -1) continue; // 불이 붙은 곳 제외
            dist2[nx][ny] = dist2[cur.X][cur.Y] + 1;
            Q2.push({nx,ny});
        }
    }
    cout << "IMPOSSIBLE"; // 지훈이 BFS를 다 돌아도 탈출하지 못함.
}