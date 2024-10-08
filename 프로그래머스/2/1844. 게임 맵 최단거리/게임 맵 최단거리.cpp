#include <bits/stdc++.h>
#define X first
#define Y second
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
using namespace std;

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    int n = maps.size();
    int m = maps[0].size();
    
    int dist[102][102];
    queue<pair<int,int>> q;
    for(int i = 0; i < n; i++) fill(dist[i], dist[i] + m, -1);
    
    q.push({0,0});
    dist[0][0] = 0;
    
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for(int dir = 0; dir < 4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(maps[nx][ny] == 0 || dist[nx][ny] >= 0) continue;
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            q.push({nx,ny});
        }
    }
    
    
    answer = ( dist[n-1][m-1] != -1 ? dist[n-1][m-1] + 1 : -1 );
    
    return answer;
}