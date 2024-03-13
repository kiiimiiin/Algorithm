#include <algorithm>
#include <iostream>
#include <utility>
#include <queue>
using namespace std; 
#define X first
#define Y second
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int board[20][20];
int dist[20][20];
int n, m;
int turn;

struct Taxi{
    int x,y;
    int fuel;
};

struct Person{
    int x,y;
    int dest_x, dest_y;
    bool is_existed; 
};

Person persons[401];
Taxi taxi;

bool is_prior(int i, int min_num){
    return persons[i].x < persons[min_num].x ||
        (persons[i].x == persons[min_num].x && persons[i].y < persons[min_num].y);
}

void Test(){
    // 최단거리
    cout << "\nTest:\n";
    for(int i = 0 ; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << dist[i][j] << ' ';
        }
        cout << '\n';
    }
}

bool PersonToDest(){
    queue<pair<int,int>> q;
    for(int i = 0 ; i < 20; i++) fill(dist[i], dist[i] + 20, -1); 
    
    // 1. 택시 승객 까지 이동 ( 승객 중에 가장 최단거리로 이동해야함 )
    dist[taxi.x][taxi.y] = 0;
    q.push({taxi.x, taxi.y});
    // 최단거리 계산
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for(int dir = 0 ; dir < 4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(board[nx][ny] == 1 || dist[nx][ny] >= 0) continue;
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            q.push({nx,ny});
        }
    }
    
    // 최단거리 승객 탐색
    int min_dist = 0x7f7f7f7f;
    int min_num = 0x7f7f7f7f;
    for(int i = 1 ; i <= m; i++){
        if(!persons[i].is_existed) continue;
        if(dist[persons[i].x][persons[i].y] == -1) continue; //도달이 안되는 승객
        
        if( dist[persons[i].x][persons[i].y] == min_dist && min_dist != 0x7f7f7f7f){
            if(is_prior(i, min_num)){ // 같은 거리 승객 처리
                min_num = i;
                continue;
            }
        }
        if( dist[persons[i].x][persons[i].y] < min_dist ){
            min_dist = dist[persons[i].x][persons[i].y];
            min_num = i;
        }
    }
    
    if(min_dist == 0x7f7f7f7f)  return false; // 도달 불가
    if(taxi.fuel < min_dist)  return false; // 최단거리까지 연료 부족
    
    // 택시 좌표 변경 (탑승)
    taxi.fuel -= min_dist;
    taxi.x = persons[min_num].x;
    taxi.y = persons[min_num].y;
    
    // 2. 승객 목적지 까지 이동
    
    // 최단거리 계산
    for(int i = 0 ; i < 20; i++) fill(dist[i], dist[i] + 20, -1); 
    dist[taxi.x][taxi.y] = 0; 
    q.push({taxi.x, taxi.y});
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for(int dir = 0 ; dir < 4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(board[nx][ny] == 1 || dist[nx][ny] >= 0) continue;
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            q.push({nx,ny});
        }
    }
    //목적지 거리
    int dest_dist = dist[persons[min_num].dest_x][persons[min_num].dest_y];
    if(dest_dist == -1) return false; // 도달 불가
    if(taxi.fuel < dest_dist)   return false;  // 목적지까지 연료 부족
    
    // 택시 좌표 변경 (목적지 수송)
    taxi.fuel -= dest_dist;
    taxi.fuel += 2 * dest_dist; 
    taxi.x = persons[min_num].dest_x;
    taxi.y = persons[min_num].dest_y;
    persons[min_num].is_existed = false; 
    turn++;
    return true; 
}

int main(void){
    // 1. N M 연료 
    // 2. Board (벽,빈칸)
    // 3. 택시 좌표
    // 4. 승객 위치, 목적지 좌표
    
    cin >> n >> m >> taxi.fuel;
    
    for(int i = 0 ; i < n ; i++)
        for(int j = 0; j < n ; j++)
            cin >> board[i][j];
    
    cin >> taxi.x >> taxi.y;
    taxi.x--; taxi.y--;
    
    for(int i = 1; i <= m; i++){
        cin >> persons[i].x  >> persons[i].y >> 
            persons[i].dest_x >> persons[i].dest_y;
        persons[i].x--; persons[i].y--; 
        persons[i].dest_x--; persons[i].dest_y--;
        persons[i].is_existed = true;
    }
        
    int flag;
    while(1){
        flag = 1;
        for(int i = 1 ; i <= m; i++){
            if(persons[i].is_existed) flag = 0;
        }
        if(flag) break; // 존재하는 승객이 없으면 (모든 승객 성공)
        
        if(!PersonToDest()) break; // 이동 실패
    }
    
    cout << ( flag ? taxi.fuel : -1) ; 
}