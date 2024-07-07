#include <iostream>
#define X first
#define Y second
using namespace std;
int n, ans;
int board[17][17];
int dx[8] = { 1, 1, 1, 0, 0, -1, -1, -1 };
int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
    
bool OOB(int x, int y){
    return (x < 0 || x >= n || y < 0 || y >= n);
}
    
void test(){
    for(int i = 0 ; i < n; i++){
        for(int j = 0 ; j < n; j++){
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

void mark(int curX, int curY){
    board[curX][curY]++; // 퀸
    for(int dir = 0 ; dir < 8; dir++){
        int nx = curX + dx[dir];
        int ny = curY + dy[dir];
        while(!OOB(nx,ny)){
            board[nx][ny]++;; // 공격불가 지역
            nx += dx[dir];
            ny += dy[dir];
        }
    }
    
    //test();
}

void unmark(int curX, int curY){
    board[curX][curY]--; // 퀸
    for(int dir = 0 ; dir < 8; dir++){
        int nx = curX + dx[dir];
        int ny = curY + dy[dir];
        while(!OOB(nx,ny)){
            board[nx][ny]--; // 공격불가 지역
            nx += dx[dir];
            ny += dy[dir];
        }
    }
    
    //test();
}

void dfs(int i){ // i번째 행에 퀸을 둘 차례

    if(i == n ){
        ans++;
        return ;
    }
    
    for(int j = 0 ; j < n; j++){
        if(board[i][j] == 0){
            mark(i,j);
            dfs(i + 1);
            unmark(i,j);
        }
    }
}

int main(void){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    dfs(0);
    cout << ans;
}


/* 
    N*N에 N개의 퀸을 놓으려면 모든 행에 퀸이 있어야 한다.
*/