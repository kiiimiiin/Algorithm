#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[4] = { 1, 0, -1 ,0 };
int dy[4] = { 0, 1, 0, -1};
char board[1000][1000];
int dist_fire[1000][1000];
int dist_person[1000][1000];


int main(void){
    ios::sync_with_stdio(0), cin.tie(0);
    
    int r, c;
    cin >> r >> c;
    queue<pair<int,int>> Q_fire, Q_human;
    
    for(int i = 0 ; i < r ; i++){
        
        fill(dist_fire[i], dist_fire[i] + c, -1);
        fill(dist_person[i], dist_person[i] + c, -1);
        
        for(int j = 0; j < c; j++){
            cin >> board[i][j];
            if(board[i][j] == 'J'){
                dist_person[i][j] = 0;
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
        for(int dir = 0; dir < 4 ; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            if(board[nx][ny] == '#' || dist_fire[nx][ny] >= 0) continue;
            dist_fire[nx][ny] = dist_fire[cur.X][cur.Y] + 1;
            Q_fire.push({nx,ny});
        }
    }
    
    while(!Q_human.empty()){
        auto cur = Q_human.front(); Q_human.pop();
        for(int dir = 0; dir < 4 ; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= r || ny < 0 || ny >= c){
                cout << dist_person[cur.X][cur.Y] + 1;
                return 0;
            }
            if(board[nx][ny] == '#' || dist_person[nx][ny] >= 0) continue;
            if((dist_person[cur.X][cur.Y] + 1 >= dist_fire[nx][ny]) && dist_fire[nx][ny] >= 0) continue;
            dist_person[nx][ny] = dist_person[cur.X][cur.Y] + 1;
            Q_human.push({nx,ny});
        }
    }
    
    cout << "IMPOSSIBLE";
    
}