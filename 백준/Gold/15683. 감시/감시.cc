#include <bits/stdc++.h>
using namespace std;
int n, m;
int mn = 0x7f7f7f7f;
int board[10][10];
int dx[4] = { 1, 0, -1 ,0 };
int dy[4] = { 0, 1, 0, -1 }; 

vector <tuple<int,int,int>> cctvs; // cctv위치, 종류

void copy(int dest[10][10], int src[10][10]){
    for(int i = 0 ; i < n; i++)
        for(int j = 0; j < m; j++)
            dest[i][j] = src[i][j];
}

void detect(int cctv_x, int cctv_y, int dir){
    dir = dir % 4;
    
    int nx = cctv_x; int ny = cctv_y;
    
    while(1){
        nx += dx[dir]; ny += dy[dir]; 
        if(nx < 0 || nx >= n || ny < 0 || ny >= m ) break;
        if(board[nx][ny] == 6) break;
        if(board[nx][ny] >= 1 && board[nx][ny] <= 5) continue;
        board[nx][ny] = 7;
    }
    
} 

void dfs(int idx){
    if(idx == cctvs.size()){
        int area = 0;
        for(int i = 0 ; i < n; i++)
            for(int j = 0; j < m; j++)
                if(board[i][j] == 0) area++;
        
        mn = min(mn, area);     
        return ;
    }
    
    
    int backup[10][10];
    int cctv_x, cctv_y, cctv_type;
    tie(cctv_x, cctv_y, cctv_type) = cctvs[idx];
    
    for(int dir = 0 ; dir < 4; dir++){
        
        copy(backup, board);
        
        if(cctv_type == 1){
            detect(cctv_x, cctv_y, dir);
        }
        else if(cctv_type == 2){
            detect(cctv_x, cctv_y, dir);
            detect(cctv_x, cctv_y, dir + 2);
        }
        else if(cctv_type == 3){
            detect(cctv_x, cctv_y, dir);
            detect(cctv_x, cctv_y, dir + 1);
        }
        else if(cctv_type == 4){
            detect(cctv_x, cctv_y, dir);
            detect(cctv_x, cctv_y, dir + 1);
            detect(cctv_x, cctv_y, dir + 2);
        }
        else if(cctv_type == 5){
            detect(cctv_x, cctv_y, dir);
            detect(cctv_x, cctv_y, dir + 1);
            detect(cctv_x, cctv_y, dir + 2);
            detect(cctv_x, cctv_y, dir + 3);
        }
        
        dfs(idx + 1);
        
        copy(board, backup);
        
    }
}
int main(void){
    ios::sync_with_stdio(0), cin.tie(0);
    
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> board[i][j];
            if(board[i][j] >= 1 && board[i][j] <= 5) cctvs.push_back({i,j, board[i][j]});
        }
    }
    
    dfs(0); // 선택한 cctv수
    
    cout << mn; 
}