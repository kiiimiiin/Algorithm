#include <iostream>
#include <utility>
using namespace std;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1};

struct Shark{
    int x,y;
    int dir;
    int table[4][4];
    bool is_lived;
};
int board[20][20]; // 상어 위치 보드 
pair<int,int> gases[20][20]; // 냄새 : 출처상어, 남은시간
int n, m, k, t ; 
Shark sharks[400];

void Test(int flag){ // flag 1 : Shark Position , 2 : Gas 
    if(flag == 1){
        cout << "Shark:\n";
        for(int i = 0 ; i < n; i++){
            for(int j = 0; j < n; j++){
                cout << board[i][j];
            }
            cout << '\n';
        }
    }
    else if(flag == 2){ // gas 남은 시간
        cout << "Gas:\n";
        for(int i = 0 ; i < n; i++){
            for(int j = 0; j < n; j++){
                cout << gases[i][j].first;
            }
            cout << '\n';
        }
            
    }
}

void MakeGas(){
    for(int i = 1; i <= m; i++){
        if(!sharks[i].is_lived) continue;
        gases[sharks[i].x][sharks[i].y].first = i; // 출처상어
        gases[sharks[i].x][sharks[i].y].second = k; // 남은 시간
    }
}

void MoveShark(){
   
    // 1. 상어 이동
    
    // 1.1 보드에서 상어좌표 삭제
    for(int i = 1; i <= m ; i++){
        if(!sharks[i].is_lived) continue;
        board[sharks[i].x][sharks[i].y] = 0;    
    }
    
    // 1.2 상어가 바라보는 방향에 따른 상어 순회, 좌표 업데이트
    // 1) 아무 냄새가 없는 칸 2) 자신의 냄새가 있는 칸
    
    
    for(int i = 1; i <= m; i++){
        if(!sharks[i].is_lived) continue;
        int is_to_empty = 0;
        for(int j = 0 ; j < 4; j++){ // 1) 아무 냄새가 없음 
            int nd = sharks[i].table[sharks[i].dir][j];
            int nx = sharks[i].x + dx[nd];
            int ny = sharks[i].y + dy[nd];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(gases[nx][ny].first == 0){ 
                sharks[i].x = nx;
                sharks[i].y = ny;
                sharks[i].dir = nd;
                is_to_empty = 1; 
                break;
            }
        }
        if(is_to_empty) continue;
        
        for(int j = 0 ; j < 4; j++){ // 2) 자신의 냄새가 있음
            int nd = sharks[i].table[sharks[i].dir][j];
            int nx = sharks[i].x + dx[nd];
            int ny = sharks[i].y + dy[nd];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if( i == gases[nx][ny].first){ 
                sharks[i].x = nx;
                sharks[i].y = ny;
                sharks[i].dir = nd;
                break;
            }
        }
    }
    
    // 1.3 보드에서 상어 이동, 중첩 상어 처리 ( 작은 상어 우선)
    for(int i = m; i > 0; i--){
        if(!sharks[i].is_lived) continue;
        if(board[sharks[i].x][sharks[i].y] > i ) // 큰 상어가 위치하면
            sharks[board[sharks[i].x][sharks[i].y]].is_lived = false; // 상어를 먹음
        board[sharks[i].x][sharks[i].y] = i;    
    }
    
    
    // 2. 냄새 시간 감량
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(gases[i][j].second > 0){
                gases[i][j].second--;
                if(gases[i][j].second == 0) // 시간이 없어지면 냄새 사라짐
                    gases[i][j].first = 0;
            }
        }
    }
    
    // 3. 상어 냄새남김
    MakeGas();
}

int main(void){
    cin >> n >> m >> k;
    
    
    for(int i = 0 ; i < n; i++){
        for(int j = 0 ; j < n; j++){
            cin >> board[i][j];
            if(board[i][j]){
                sharks[board[i][j]].x = i;
                sharks[board[i][j]].y = j;
                sharks[board[i][j]].is_lived = true; 
            }
        }
    }
    
    for(int i = 1; i <= m; i++){
        int dir;
        cin >> dir;
        sharks[i].dir = dir - 1; 
    }
    
    for(int i = 1; i <= m; i++){ // 상어 별우선순위 테이블
        for(int j = 0; j < 4; j++){
            for(int k = 0; k < 4; k++){
                int dir;
                cin >> dir; 
                sharks[i].table[j][k] = dir - 1;
            }
        }
    }
    
    // 1. 처음에 상어 위치에 냄새 뿌림 
    MakeGas();     
    while(1){
        int flag = 0;
        for(int i = 2 ; i <= m ; i++){
            if(sharks[i].is_lived) flag = 1;
        }
        if(!flag || t > 1000) break; // 1번 물고기만 남거나 1000초가 넘음
        
        MoveShark();
        // 2. 상어 이동
        t++;
    }
    
    cout << ( t <= 1000 ? t : -1 ); 
}