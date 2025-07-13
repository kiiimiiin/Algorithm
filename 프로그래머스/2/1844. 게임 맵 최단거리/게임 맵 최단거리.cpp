#include<vector>
#include<queue>
#define X first
#define Y second
using namespace std;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int dist[102][102];


int solution(vector<vector<int> > maps)
{
    int n = maps.size();
    int m = maps[0].size();
    int answer = 0;
    queue<pair<int,int>> q;
    for(int i = 0 ; i < n; i++) fill(dist[i] , dist[i] + m, -1);
    
    q.push({0,0});
    dist[0][0] = 0;
    
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for(int dir = 0 ; dir < 4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(dist[nx][ny] >= 0 || maps[nx][ny] != 1) continue;
            q.push({nx,ny});
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
        }
    }

        
    answer = (dist[n-1][m-1] == -1 ? -1 : dist[n-1][m-1] + 1 );
    return answer;
}