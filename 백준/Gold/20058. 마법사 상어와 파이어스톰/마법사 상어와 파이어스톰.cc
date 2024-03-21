#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define X first
#define Y second
int dx[4] = { 1, 0, -1 , 0};
int dy[4] = { 0, 1, 0, -1}; 
int board[65][65];
int marker[65][65];
int N,Q; 

void TestMarker(){
    cout << "TestMarker:\n";
    for(int i = 0; i < (1 << N); i++){
        for(int j = 0; j < (1 << N); j++){
            cout << marker[i][j] << ' ';
        }
        cout << '\n';
    }  
}
void TestBoard(){
    cout << "TestBoard:\n";
    for(int i = 0; i < (1 << N); i++){
        for(int j = 0; j < (1 << N); j++){
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }  
}

bool OOB(int nx, int ny){
    return (nx < 0 || nx >= (1 << N) || ny < 0 || ny >= (1 << N));
}

void Rotate(int L, int x, int y){
    
    int c_board[65][65] = {};
    
    for(int i = x ; i < x + (1 << L); i++){
        for(int j = y ; j < y + ( 1 << L); j++){
            c_board[j-y][ ( 1 << L ) - 1 - ( i - x )] 
                = board[i][j];  
        }
    }// x, y기준 보드값을 c_board에 회전한채로 0,0기준으로 일단저장
    
    for(int i = 0 ; i < ( 1 << L); i++){
        for(int j = 0; j < ( 1 << L); j++){
            board[i + x][j + y] = c_board[i][j];
        }
    }
    // 0,0 기준의 c_board를 x,y기준 보드값에 저장
}

void UpdateBoard(int L){
    // 1. 격자 분리 및 회전
    for(int i = 0 ; i < ( 1 << N); i += ( 1 << L)){
        for(int j = 0 ; j < (1 << N); j += ( 1 << L)){
            Rotate(L, i , j);
        }
    }
}

void ProcessIce(){
    // 2. 얼음 처리
    queue<pair<int,int>> q;
    
    for(int i = 0 ; i < (1 << N) ; i++){
        for(int j = 0 ; j < (1 << N); j++){
            if(board[i][j] == 0) continue;
            int near_ice = 0; 
            for(int dir = 0 ; dir < 4; dir++){
                int nx = i + dx[dir];
                int ny = j + dy[dir];
                if(OOB(nx,ny) ) continue;
                if(board[nx][ny]) near_ice++;
            }
            if(near_ice < 3) q.push({i,j});
        }
    }
    
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        board[cur.X][cur.Y]--;
    }
}

pair<int,int> Bfs(){
    int vis[65][65] = {};
    int sum = 0; 
    int mx = -0x7f7f7f7f;
    for(int i = 0 ; i < ( 1 << N); i++){
        for(int j = 0 ; j < ( 1 << N); j++){
            sum += board[i][j];
            if(board[i][j] && !vis[i][j]){ // bfs
                queue<pair<int,int>> q;
                q.push({i,j});
                vis[i][j] = 1;
                int area = 0; 
                while(!q.empty()){
                    auto cur = q.front(); q.pop();
                    area++;
                    for(int dir = 0 ; dir < 4 ; dir++){
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if(OOB(nx,ny)) continue;
                        if(vis[nx][ny] || board[nx][ny] == 0) continue;
                        vis[nx][ny] = 1;
                        q.push({nx,ny});
                    }
                }
                if(area > 1) mx = max(mx, area);
            }
        }
    }
    
    if(mx == -0x7f7f7f7f) mx = 0; // 덩어리가 없는 경우 0
    return {sum, mx};
}

int main(void){
    cin >> N >> Q; 
    
    for(int i = 0 ; i < (1 << N) ; i++)
        for(int j = 0; j < (1 << N); j++)
            cin >> board[i][j];

    
    
    while(Q--){
        int L;
        cin >> L; 
        UpdateBoard(L); // 1. 격자나누기 및 회전
        ProcessIce(); // 2. 녹는 얼음 처리
    }
    
    pair<int,int> ret = Bfs(); // 3. 남아있는 얼음 및 가장 큰 덩어리 영역 구하기 
    cout << ret.X << '\n' << ret.Y; 
    
}