#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <unordered_set>
#include <iostream>
#define X first 
#define Y second
using namespace std;
const int dx[4] = { 1, 0, -1, 0};
const int dy[4] = { 0, -1, 0, 1}; 
bool vis[502][502];
pair<int,int> info[502][502]; // 고유번호, 영역
queue<pair<int,int>> q;
queue<pair<int,int>> pos;
int culSum[502];


int solution(vector<vector<int>> land) {
    int answer = 0;
    int areaIdx = 0;
    int n = land.size();
    int m = land[0].size();
    
    
    
    for(int i = 0 ; i < n; i++){
        for(int j = 0 ; j < m; j++){
            if(!vis[i][j] && land[i][j]){
                unordered_set<int> cul;
                int area = 0;
                q.push({i, j});
                pos.push({i, j});
                vis[i][j] = true;
                while(!q.empty()){
                    auto cur = q.front(); q.pop(); area++; cul.insert(cur.Y);
                    for(int dir = 0 ; dir < 4; dir++){
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                        if(!land[nx][ny] || vis[nx][ny]) continue;
                        q.push({nx,ny});
                        pos.push({nx,ny});
                        vis[nx][ny] = true;
                    }    
                }
                
                for(auto c : cul)
                    culSum[c] += area;
            }
        }
    }
    
    
    int mx = -0x7f7f7f7f;
    for(int j = 0 ; j < m; j++){
        mx = max(mx, culSum[j]);
    }
    
    return mx == -0x7f7f7f7f ? 0 : mx;
}


/*
    석유 덩어리에 대해서 bfs를 한다
    석유 덩어리들의 열 정보를 구한다
    시추들을 순회하며 구한 열정보를 바탕으로 뽑은 석유량을 구한다
*/