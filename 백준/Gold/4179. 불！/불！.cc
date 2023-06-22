#include <bits/stdc++.h>
using namespace std;
#define X first 
#define Y second 
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int r, c;
char board[1002][1002];
int dist_fire[1002][1002];
int dist_human[1002][1002];
queue<pair<int,int>> Q_fire, Q_human;

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> r >> c;
    for(int i = 0 ; i < r ; i++){
        fill(dist_fire[i], dist_fire[i] + c, -1);
        fill(dist_human[i], dist_human[i] + c, -1); // 방문이력 없음
        for(int j = 0 ; j < c; j++){
            cin >> board[i][j];
            if(board[i][j] == 'J'){
                dist_human[i][j] = 0;
                Q_human.push({i,j});
            }
            else if(board[i][j] == 'F'){
                dist_fire[i][j] = 0;
                Q_fire.push({i,j});
            }
        }    
    }
    while(!Q_fire.empty()){
        auto cur = Q_fire.front(); Q_fire.pop();
        for(int dir = 0 ; dir < 4 ; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= r || ny < 0 || ny >= c ) continue;
            if(dist_fire[nx][ny] >= 0 || board[nx][ny] == '#') continue;
            dist_fire[nx][ny] = dist_fire[cur.X][cur.Y] + 1;
            Q_fire.push({nx,ny});
        }
    }
    while(!Q_human.empty()){
       auto cur = Q_human.front(); Q_human.pop();
        for(int dir = 0 ; dir < 4 ; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= r || ny < 0 || ny >= c ){ // 탈출성공 
                cout << dist_human[cur.X][cur.Y] + 1;
                return 0;
            }
            if(dist_human[nx][ny] >= 0 || board[nx][ny] == '#') continue;
            if(dist_human[cur.X][cur.Y] + 1 >= dist_fire[nx][ny] && dist_fire[nx][ny] >= 0) continue;
            dist_human[nx][ny] = dist_human[cur.X][cur.Y] + 1;
            Q_human.push({nx,ny});
        }
    }
    cout << "IMPOSSIBLE" ;
}