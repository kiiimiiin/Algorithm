#include <iostream>
#include <algorithm>
#include <queue>
#define X first
#define Y second
using namespace std;
struct Fire {
    int m;
    int d;
    int s;
};
int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
vector<Fire> board[52][52]; // 파이어볼 정보를 담는 코드 
int N,M,K; // M : 파이어볼 개수 , K : 명령수

/* 1.이동
새로운 구조체 벡터 배열에 이동한 보드를 복사
이동한 보드를 원래보드에 복사 (이동완료한 배열 만듦)

2. 합치기 나누기
구벡배를 순화해서 각 자리 불 합함(원래 불 제거)
나누어지는 불 정보들을 구하고
나누어진 불을 다시 그 벡터에 삽입 */


void TestFire(){
    //파이어볼 위치에 대한질량 확인
    cout << "Test Fire, m:\n";
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N; j++){
            if(board[i][j].size())
                cout << board[i][j].front().m << ' ';
            else
                cout << 0 << ' ';
        }
        cout << '\n';
    }
}

pair<int,int> ProcessOOB(int x, int y){
    // 바깥으로 나가있으면 연결된 보드처리
    int nx, ny; 
    if(x < 0) nx = N + x ; // x = -1이면 N-1로, -2 이면 N-2로
    else if(x >= N) nx = x - N ; // x = N 이면 0으로, N+1이면 1로 
    else nx = x;
    
    if(y < 0) ny = N + y  ;
    else if(y >= N) ny = y - N ;
    else ny = y;
    
    return {nx,ny};
}

void Copy(vector<Fire> desc[52][52], vector<Fire> src[52][52]){
    for(int i = 0 ; i < N; i++){
        for(int j = 0 ; j < N; j++){
            desc[i][j] = src[i][j]; 
        }
    }    
}


int main(void){
    ios::sync_with_stdio(0), cin.tie(0);
    
    cin >> N >> M >> K;
    for(int i = 0 ; i < M ; i++){
        int x, y, m , s , d;
        cin >> x >> y >> m >> s >> d;
        Fire fire;
        fire.m = m; fire.s = s; fire.d = d;
        board[x-1][y-1].push_back(fire);
    }
    
    

    
    while(K--){
        // 1. 존재하는 파이어볼 이동
        
        vector<Fire> c_board[52][52];
        
        for(int i = 0 ; i < N; i++){
            for(int j = 0 ; j < N; j++){
                if(board[i][j].empty()) continue; // 파이어볼이 비어있음 
                
                auto fires = board[i][j];
                
                for(auto fire : fires){ 
                    int nx = i +  ( fire.s % N ) * dx[fire.d] ; 
                    int ny = j + ( fire.s % N ) * dy[fire.d] ;
                    auto ret = ProcessOOB(nx,ny);
                    if(ret.X < 0 || ret.X >= N || ret.Y < 0 || ret.Y >= N)
                    { exit(0); }
                    c_board[ret.X][ret.Y].push_back(fire);
                }
            }
            
        }
        
        Copy(board, c_board);

 
        //2. 파이어볼 나누기 (파이어볼 탐색 후 나눔)

        
        for(int i = 0 ; i < N ; i++){
            for(int j = 0 ; j < N; j++){
                if(board[i][j].size() >= 2){ // 2개 이상의 파이어볼 칸
                    int cnt = board[i][j].size();
                    int sum_m , sum_s, d_is_all_same;
                    sum_m = sum_s = d_is_all_same = 0;
                    for(auto fire : board[i][j]){
                        sum_m += fire.m;
                        sum_s += fire.s;
                        d_is_all_same += ( fire.d % 2 ); // 홀수면 1누적 짝수면 0
                    }
                    
                    vector<int> dirs; 
                    
                    if(d_is_all_same == cnt || d_is_all_same == 0)
                        dirs = { 0,2,4,6 };
                    else
                        dirs = { 1, 3, 5, 7};
                    
                    board[i][j].clear();
                    int new_m = sum_m / 5;
                    if(new_m == 0 ) continue;
                    int new_s = sum_s / cnt;
                    for(int dir : dirs){
                        Fire new_fire;
                        new_fire.m = new_m; new_fire.s = new_s;
                        new_fire.d = dir; 
                        board[i][j].push_back(new_fire);
                    }
                }
            }
        }
    }
    
    int ans = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0 ; j < N; j++){
            if(board[i][j].empty()) continue;
            for(auto fire : board[i][j]) ans += fire.m;
        }
    }
    cout << ans;
    return 0;
}