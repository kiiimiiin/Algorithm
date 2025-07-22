#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <unordered_set>
#include <algorithm>
#define X first
#define Y second
using namespace std;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
bool vis[52][52] = {}; 
int n, m;


vector<pair<int,int>> bfs(int sx, int sy, vector<vector<int>> board){
    queue<pair<int,int>> q;
    vector<pair<int,int>> group;
    q.push({sx,sy});
    vis[sx][sy] = true;
    
    int minx = sx;
    int miny = sy;
    
    while(!q.empty()){
        auto cur = q.front(); q.pop(); group.push_back(cur);
        for(int dir = 0 ; dir < 4 ; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n || vis[nx][ny]) continue;
            if(board[nx][ny] == ( board[cur.X][cur.Y] == 1 ? 0 : 1)) continue;
            q.push({nx,ny}); 
            vis[nx][ny] = true;
            minx = min(minx, nx);
            miny = min(miny, ny);
        }
    }
    
    for(int i = 0 ; i < group.size(); i++)
        group[i] = make_pair(group[i].X -minx, group[i].Y - miny);
    
    return group;
}


void rotate(vector<pair<int, int>>& v)
{
    int maxX = 0, minX = 100000, minY = 100000;
    for (auto& p : v)
        maxX = max(maxX, p.X);

    for (auto& p : v)
    {
        int temp = p.X;
        p.X = p.Y;
        p.Y = maxX - temp;

        minY = min(minY, p.first);
        minX = min(minX, p.second);
    }
    
    
    for (pair<int, int>& p : v)
    {
        p.X -= minX;
        p.Y -= minY;
    }

  
}
    
    
int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    int answer = 0;
    
    n = game_board.size();
    m = game_board[0].size();
    
    vector<vector<pair<int,int>>> puzzles; // i번째 puzzle의 좌표 묶음
    vector<vector<pair<int,int>>> emptys;
    
    int idx = 0 ; 
    for(int i = 0 ; i < n; i++){
        for(int j = 0 ;  j < m; j++){
            if(vis[i][j] || table[i][j] != 1 ) continue;
            puzzles.push_back(bfs(i, j, table));
        }
    }
    
    for(int i = 0  ; i  < n; i++) fill(vis[i], vis[i] + n , 0); 
    
    for(int i = 0 ; i < n; i++){
        for(int j = 0 ;  j < m; j++){
            if(vis[i][j] || game_board[i][j] != 0 ) continue;
            emptys.push_back(bfs(i, j, game_board));
        }
    }
    
    vector<bool> visPuzzle(puzzles.size(), false); 
    vector<bool> visEmpty(emptys.size(), false);
    
    for (int i =  0; i < emptys.size(); i++) {
        if (visEmpty[i]) continue;
        for (int j =  0; j < puzzles.size(); j++) {
            if (visPuzzle[j]) continue;

            vector<pair<int, int>> puzzle = puzzles[j];
            bool matched = false;

            for (int rot = 0; rot < 4; rot++) {
                auto empty = emptys[i];
                auto rotated = puzzle;

                sort(empty.begin(), empty.end());
                sort(rotated.begin(), rotated.end());

                if (empty == rotated) {
                    visEmpty[i] = visPuzzle[j] = true;
                    answer += rotated.size();
                    matched = true;
                    break;
                }

                rotate(puzzle);  // rotate 원본을 회전시키고 다시 복사함
            }

            if (matched) break;  // 이미 이 empty에 퍼즐이 맞았으면 다음 empty로
        }
    }
    
    
    return answer;
}

/*
    
    1. 
    vector<pair<int,int>> [퍼즐갯수][4방향]
    
    2. 퍼즐을 game_baord에 매칭 
    
*/