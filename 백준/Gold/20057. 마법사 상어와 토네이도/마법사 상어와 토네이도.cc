#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
#define X first
#define Y second
int board[502][502]; // 모래정보
int wind[502][502];
int dx[4] = { 1, 0, -1 , 0};
int dy[4] = { 0, 1, 0, -1};
int sdx[4][10] = {
    { -1, -1 , 0, 0, 2, 0, 0, 1, 1, 1 },
    { -1, 1, -2, 2, 0, -1, 1, -1, 1, 0}, 
    { 1, 1, 0, 0, -2, 0, 0, -1, -1, -1},
    { -1, 1, -2, 2, 0, 1, -1, 1, -1, 0}
};
int sdy[4][10] = {
    { 1, -1, 2, -2, 0, 1, -1, 1, -1, 0},
    {-1,-1, 0, 0, 2, 0, 0, 1, 1, 1},
    { 1, -1, 2, -2, 0, 1, -1, 1, -1, 0},
    { 1, 1, 0, 0, -2, 0, 0, -1, -1, -1}
};
// 0,1 : 1% | 1,2 : 2% | 4: 5% | 5, 6 : 7%  | 7, 8 : 10% | 9 : 55%  
int n;
vector<pair<int,int>> winds;
int sum;

void TestWind(){
    cout << "\nTestWindDir:\n"; 
    for(int i = 0 ; i < n; i++){
        for(int j = 0 ; j < n; j++){
            cout << wind[i][j] << ' ';
        }
        cout << '\n';
    }
}
void TestSand(){
    cout << "\nTestSand:\n";
    for(int i = 0 ; i < n; i++){
        for(int j = 0; j < n ; j++){
            cout << board[i][j] << ' ';
        }
        cout << '\n'; 
    }
}

void MakeWind(){
    // 1. 토네이도 이동
    int x,y, dir, middle;
    x = y = 0; 
    dir = 1;
    middle = (0 + n -1) / 2 ;
    
    for(int i = 0 ; i < n; i++) fill(wind[i], wind[i] + n, -1);
    
    while(!(x == middle && y == middle))
    {
        wind[x][y] = ( dir + 2 ) % 4;
        winds.push_back({x,y});
        
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        // 초기 회전 및 이미 채워진칸
        if(nx >= n || ny >= n || nx < 0 || wind[nx][ny] != -1){ 
            dir = ( dir + 3 ) % 4;
            nx = x + dx[dir];
            ny = y + dy[dir];
        }
        x = nx;
        y = ny;
    }
    wind[middle][middle] = 3;
    winds.push_back({middle,middle});
}

void SpreadSand(int x, int y, int sdir){
    int sand_sum = 0; 
    for(int dir = 0 ; dir < 10; dir++){
        int sand;
        if(dir >= 0 && dir <= 8){
            if(dir == 0 || dir == 1)
                sand = (board[x][y] * 1) / 100;
            else if(dir == 2 || dir == 3)
                sand = (board[x][y] * 2) / 100;
            else if(dir == 4)
                sand = (board[x][y] * 5) / 100;
            else if(dir == 5 || dir == 6)
                sand = (board[x][y] * 7) / 100;
            else if(dir == 7 || dir == 8)
                sand = (board[x][y] * 10) / 100;
            sand_sum += sand;  
        }
        else{
            sand = board[x][y] - sand_sum;
        }

        int nx = x + sdx[sdir][dir];
        int ny = y + sdy[sdir][dir];
        if(nx < 0 || nx >= n || ny < 0 || ny >= n) sum += sand;
        else board[nx][ny] += sand;
    }
    board[x][y] = 0;
    
}
// winds 벡터는 보드끝에서 가운데까지 푸쉬했으므로
// 차례차례 pop하면 가운데부터 보드끝까지 바람방향을 얻을 수 있음 
void SpreadAllSand(){
    // 2. 모래이동
    while(!winds.empty()){ 
        auto cur = winds.back(); winds.pop_back();
        int dir = wind[cur.X][cur.Y];
        int nx = cur.X + dx[dir];
        int ny = cur.Y + dy[dir];
        if(nx < 0 || nx >= n || ny < 0 || ny >= n) { break;}
        
        // 2.1 해당 위치 모래 흩어짐 
        SpreadSand(nx,ny, dir);

    }
}

int main(void){
    
    cin >> n;
    for(int i = 0 ; i < n; i++){
        for(int j = 0 ; j < n; j++){
            cin >> board[i][j];
        }
    }
    
    MakeWind();
    SpreadAllSand();
    cout << sum;
}