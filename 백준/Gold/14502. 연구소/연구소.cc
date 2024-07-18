#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int n, m;
int mx = -0x7f7f7f7f; 
int board[10][10];
int dx[4]= { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 }; 
vector<pair<int,int>> e_space;
vector<pair<int,int>> virus; 

int bfs(){
    int vis[10][10] = {};
    queue<pair<int,int>> q;
    for(auto v : virus) {
        q.push(v);
        vis[v.X][v.Y] = 1;
    }
    
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for(int dir = 0 ; dir < 4 ; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir]; 
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue; 
            if(board[nx][ny] != 0 || vis[nx][ny]) continue; 
            vis[nx][ny] = 1;
            q.push({nx,ny});
        }
    }
    // 방문한 구간이 virus 전파구간
    int area = 0;    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(board[i][j] == 0 && !vis[i][j]) area++;
    return area; 
}

void dfs(int idx, int k){ // 택하는 인덱스, 벽을 택한 갯수
    if(k == 3){
        int area = bfs(); 
        mx = max(mx, area);
        return ;
    }
    
    for(int i = idx ; i < e_space.size(); i++){
        board[e_space[i].X][e_space[i].Y] = 1;
        dfs(i + 1, k + 1);
        board[e_space[i].X][e_space[i].Y] = 0;
    }
    
}

int main(void){
    ios::sync_with_stdio(0), cin.tie(0);
    
    cin >> n >> m;
    
    for(int i = 0 ; i < n; i++){
        for(int j = 0 ; j < m ; j++){
            cin >> board[i][j];
            if(board[i][j] == 0) e_space.push_back({i,j}); 
            else if(board[i][j] == 2) virus.push_back({i,j}); 
            
        }
    }
    
    // choose 3 space
    
    dfs(0, 0);
  
    cout << mx ;
}
