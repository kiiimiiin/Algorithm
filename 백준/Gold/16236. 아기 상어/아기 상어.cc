#include <bits/stdc++.h>
using namespace std; 
#define X first
#define Y second
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1};
int dist[22][22];
int board[22][22]; 
int n;


struct Shark{
    int size;
    int eat_num;
};

vector<pair<int,int>> fishes; 

int main(void){
    ios::sync_with_stdio(0), cin.tie(0);
    
    cin >> n;
    queue<pair<int,int>> q; 
    Shark shark;
    shark.size = 2;
    shark.eat_num = 0;
    
    for(int i = 0; i < n; i++){
        for(int j = 0 ; j < n; j++){
            cin >> board[i][j];
            if(board[i][j] == 9) q.push({i,j}); // 상어 좌표
        }
    }

    
    int ans = 0;
    // bfs를 돌리면서 먹을수 있는 가장 가까운 물고기에 도달시 종료한다면 ? (즉 이를 한번에 처리) 
    // 거리, 좌표정보를 같이 갖고있어야하므로 tuple 사용이 적합
    while(1){
    
        for(int i = 0 ; i < n; i++)  fill(dist[i], dist[i]+n, -1);
        
        auto cur = q.front(); 
        board[cur.X][cur.Y] = 0; // 상어이동
        dist[cur.X][cur.Y] = 0;
        
        tuple<int,int,int> mn = {0x7f7f7f7f, 0x7f7f7f7f, 0x7f7f7f7f};
        
        while(!q.empty()){
            auto cur = q.front(); q.pop();
            if(dist[cur.X][cur.Y] >= get<0>(mn)) { while(!q.empty()) q.pop(); break; }
            for(int dir = 0; dir < 4; dir++){
                int nx = cur.X + dir[dx];
                int ny = cur.Y + dir[dy];
                if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                if(board[nx][ny] > shark.size || dist[nx][ny] >= 0) continue;
                dist[nx][ny] = dist[cur.X][cur.Y] + 1;
                q.push({nx,ny});
                if(board[nx][ny] < shark.size && board[nx][ny] != 0) 
                    mn = min(mn, {dist[nx][ny], nx, ny});
            }
        } // 가까운 물고기를 찾음
        
        
        
        int min_dist, x, y; 
        tie(min_dist, x, y) = mn; 
        if(min_dist == 0x7f7f7f7f) {cout << ans; return 0; } // 가까운 물고기가 없음 
        
        shark.eat_num++;
        if(shark.eat_num >= shark.size) { shark.size++; shark.eat_num = 0;}
        ans += dist[x][y];
        board[x][y] = 9; 
        q.push({x, y});
  
    }
}