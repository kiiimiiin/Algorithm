#include <iostream>
#include <algorithm>

using namespace std;

struct Fish {
    int x,y;
    int d;
    bool is_lived;
};

int board[4][4]; // 물고기 번호 board
Fish fishes[20]; // 물고기 번호에 대한 물고기 info

int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[8] = { 0, -1, -1, -1, 0, 1, 1, 1 };
int mx = -0x7f7f7f7f; 

void Copy(int desc[4][4], int src[4][4], Fish desc2[20], Fish src2[20]){
    for(int i = 0 ; i < 4; i++)
        for(int j = 0 ; j < 4 ; j++)
            desc[i][j] = src[i][j];
    
    for(int i = 0 ; i < 20; i++) desc2[i] = src2[i];
}

void MoveFish(){
    for(int i = 1; i <= 16; i++){
        if(!fishes[i].is_lived) continue;
        Fish f = fishes[i];
        
        int d = f.d;
        int nx = f.x + dx[d];
        int ny = f.y + dy[d];
        while((nx < 0 || nx >= 4 || ny < 0 || ny >= 4) || board[nx][ny] == -1){ 
            d = ( d + 1 ) % 8;
            nx = f.x + dx[d];
            ny = f.y + dy[d];
        }
    
        fishes[i].d = d; 

        // 물고기 존재 혹은 빈칸 swap
        board[f.x][f.y] = board[nx][ny];
        fishes[board[nx][ny]].x = f.x;
        fishes[board[nx][ny]].y = f.y;
        board[nx][ny] = i;
        fishes[i].x = nx;
        fishes[i].y = ny;
    }
}

void DFS(int x, int y, int sum, int d){ 
    // parm : 상어 x,y / 먹은 물고기 번호 합 / 상어 방향
    // 상어가 x,y에 대한 물고기를 먹었을때의 합을 구함

    mx = max(mx , sum); // 1.  맥스값 구함 
    int cboard[4][4]; 
    Fish cfishes[20];
    Copy(cboard, board, cfishes, fishes);
    
    MoveFish(); // 2. 물고기 이동
    
    for(int i = 1; i <= 3; i++){ // 3. 상어 이동
        int nx = x + i * dx[d];
        int ny = y + i * dy[d];
        if(nx < 0 || nx >= 4 || ny < 0 || ny >= 4) continue;
        if(board[nx][ny] == 0) continue;  // 빈칸
        
        // eat fish
        int n = board[nx][ny];
        int nd = fishes[n].d;
        fishes[n].is_lived = false;
        board[nx][ny] = -1;
        board[x][y] = 0;
        
        DFS(nx, ny, sum + n, nd);
        
        board[nx][ny] = n;
        fishes[n].is_lived = true; 
        board[x][y] = -1; // 원복
    }
    
    Copy(board, cboard, fishes, cfishes); // 보드 원복 

}



// DFS 과정:
// 물고기를 이동한 경우에 대해 상어가 이동할 수 있는 모든 경우를 본다.
// 각 경우가 끝나면 해당 물고기가 이동한 경우는 끝났으므로 보드 원복
// 이전 경우에서 상어가 이동할 다음 경우로 넘어간다.

int main(void){
    ios::sync_with_stdio(0), cin.tie(0);

    for(int i = 0; i < 4; i++){
        for(int j = 0 ; j < 4; j++){
            int n, d;
            cin >> n >> d;
            board[i][j] = n;
            fishes[n].x = i;
            fishes[n].y = j;
            fishes[n].d = d-1;
            fishes[n].is_lived = true;
        }
    }
    
    // (0, 0) 물고기 섭취
    int n = board[0][0];
    int sd = fishes[n].d;
    fishes[board[0][0]].is_lived = false;
    board[0][0] = -1; // 상어 존재 : -1 
    
    DFS(0, 0, n, sd);
    
    cout << mx;
}