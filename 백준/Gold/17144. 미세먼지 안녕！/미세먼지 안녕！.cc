#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int r, c, t, head, tail;
int board[52][52];
int dx[4] = { 1, 0, -1, 0};
int dy[4] = { 0, 1, 0, -1};

void dust(){
    queue<pair<int,int>> q;
    // 확산된 부분에 확산을 시작할 미세먼지가 있으면 안됨 
    // 값이 변해서 동시에 일어나는 것이 구현되지 않음 
    
    int board2[52][52] = {}; // 확산 미세먼지 값 저장할 board
    for(int i = 0 ; i < r; i++)
        for(int j = 0 ; j < c ; j++)
            if(board[i][j] > 0) q.push({i,j});
    
    while(!q.empty()){
        auto cur = q.front(); q.pop(); 
        for(int dir = 0; dir < 4 ; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            if(board[nx][ny] == -1) continue;
            board2[nx][ny] += board[cur.X][cur.Y] / 5;
            board2[cur.X][cur.Y] -= board[cur.X][cur.Y] / 5;
        }
    }
    
    for(int i = 0 ; i < r ; i++)
        for(int j = 0 ; j < c ; j++)
            board[i][j] += board2[i][j]; // 확산값 반영
}

void clean(){
    // head
    int curX = head - 1;
    int curY = 0;
    int dir = 2; // 북쪽으로 시작
    
    while(1){
        int nx = curX + dx[dir];
        int ny = curY + dy[dir];
        if(nx < 0 || nx > head || ny < 0 || ny >= c){
            dir = ( dir + 3) % 4;
            continue;
        }
        if(board[nx][ny] == -1) break;
        
        board[curX][curY] = board[nx][ny];
        curX = nx; curY = ny;
    }
    board[curX][curY] = 0;

    // tail
    curX  = tail + 1;
    curY = 0;
    dir = 0; 
    
    while(1){
        int nx = curX + dx[dir];
        int ny = curY + dy[dir];
        if(nx < tail || nx >= r || ny < 0 || ny >= c){
            dir = ( dir + 1) % 4;
            continue;
        }
        if(board[nx][ny] == -1) break;
        board[curX][curY] = board[nx][ny];
        curX = nx; curY = ny;
    }
    board[curX][curY] = 0;
    
}

int main(void){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> r >> c >> t;
    
     
    for(int i = 0 ; i < r ; i++){
        for(int j = 0 ; j < c ; j++){
            cin >> board[i][j];
            if(board[i][j] == -1) tail = i;  
        }
    }

    head = tail - 1;
    
    while(t--){
        dust();
        clean();
    }
    
    int ans = 0 ;
    for(int i  = 0 ; i < r; i++)
        for(int j = 0 ; j < c; j++)
            if(board[i][j] > 0) ans += board[i][j];
            
    cout << ans;
}