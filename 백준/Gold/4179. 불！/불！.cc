#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

// 지훈, 불 따로 bfs 
// 지훈이는 불이 탄 지점을 가지 못함 
// bfs를 다 돌리고 지훈이 dist가 모서리에 존재하면 탈출 성공 아니면 실패 

string board[1002];
int distJ[1002][1002], distF[1002][1002];
int r,c;
int dx[4]  = { 1, 0 , -1, 0};
int dy[4] = { 0, 1, 0, -1 };

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> r >> c;
    for(int i = 0; i < r; i++) cin >> board[i];
    for(int i = 0; i < r; i++) 
    {
        fill(distJ[i], distJ[i] + c, -1);
        fill(distF[i], distF[i] + c, -1); // 방문이력 없는 곳
    }
    
    queue<pair<int, int>> QJ, QF;

    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            if(board[i][j] == 'J')
            {
                distJ[i][j] = 0; 
                QJ.push({i,j}); // 지훈 시작점
            }
            if(board[i][j] == 'F')
            {
                distF[i][j] = 0; 
                QF.push({i,j}); // 불 시작점
            }
        }
    }
    while(!QF.empty())
    { // 불을 먼저 bfs 돌려서 지훈이 갈 수 있는 지점을 만듦
        auto cur = QF.front(); QF.pop();
        for(int dir = 0; dir < 4 ; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            if(board[nx][ny] == '#' || distF[nx][ny] >= 0) continue;
            distF[nx][ny] = distF[cur.X][cur.Y] + 1;
            QF.push({nx,ny});
        }
    }
    while(!QJ.empty())
    { // 지훈이가 불이 지나간 곳을 피하며 탈출 지점으로 이동
        auto cur = QJ.front(); QJ.pop();
       for(int dir = 0; dir < 4 ; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            if(board[nx][ny] == '#' || distJ[nx][ny] >= 0) continue;
            if(distJ[cur.X][cur.Y] + 1 >= distF[nx][ny] && distF[nx][ny] > -1) continue; // 불이 먼저 지나간 곳은 못감
            distJ[nx][ny] = distJ[cur.X][cur.Y] + 1;
            QJ.push({nx,ny});
        }
    }
    
    int minTime = r * c + 1; 

    for(int i = 0; i < r; i++) // 왼쪽, 오른쪽 도착 여부
    {   
        if(distJ[i][0] != -1) minTime = min(distJ[i][0], minTime);
        if(distJ[i][c-1] != -1) minTime = min(distJ[i][c-1], minTime);
    }
    //불이 없을 때 이상함 

    for(int j = 0; j < c; j++) // 위쪽, 아래쪽 도착 여부 
    {
        if(distJ[0][j] != -1) minTime = min(distJ[0][j], minTime);
        if(distJ[r-1][j] != -1) minTime = min(distJ[r-1][j], minTime); 
    }

    if(minTime < r * c + 1) cout << minTime + 1; // 가장자리에서 한 칸 더 이동하면 탈출
    else cout << "IMPOSSIBLE";
}