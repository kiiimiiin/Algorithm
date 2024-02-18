#include <bits/stdc++.h>
using namespace std;
int dx[5] = { 9 , 0, 0, -1, 1 }; // dummy 1 동 2 서 3 북 4 남  
int dy[5] = { 9 , 1, -1, 0, 0 };
int n, m, x, y , k;
int board[22][22], dice[7];

void roll(int dir){
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    
    if(nx < 0 || nx >= n || ny < 0 || ny >= m) return;
    
    if(dir == 1){ // 동
        swap(dice[1], dice[3]); 
        swap(dice[3], dice[6]);
        swap(dice[6], dice[4]);
    }
    else if(dir == 2){ // 서
        swap(dice[1], dice[4]); 
        swap(dice[4], dice[6]);
        swap(dice[6], dice[3]);
    }
    else if(dir == 3){ // 북
        swap(dice[1], dice[2]); 
        swap(dice[2], dice[6]);
        swap(dice[6], dice[5]);
    }
    else if(dir == 4){ // 남
        swap(dice[1], dice[5]); 
        swap(dice[5], dice[6]);
        swap(dice[6], dice[2]);
    }
    
    
    if(board[nx][ny] == 0) board[nx][ny] = dice[1];
    else {
        dice[1] = board[nx][ny];
        board[nx][ny] = 0;
    }
    
    cout << dice[6] << '\n';
    
    x = nx; y = ny; 
}

int main(void){
    ios::sync_with_stdio(0), cin.tie(0);
    
    cin >> n >> m >> x >> y >> k;
    
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < m; j++)
            cin >> board[i][j];
    
    while(k--){
        int dir;
        cin >> dir;
        roll(dir); 
        // 명령 
    }
}