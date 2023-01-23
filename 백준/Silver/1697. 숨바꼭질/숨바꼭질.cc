#include <bits/stdc++.h>
using namespace std;

int dist[100001];
int n, k;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> k;
    if(n == k) cout << 0;
    fill(dist, dist+100001, -1); // 방문 이력 없는 곳 
    dist[k] = -2; // 동생위치
    
    queue<int> Q;
    dist[n] = 0;
    Q.push(n); // 수빈 시작점
    
    while(!Q.empty())
    {
        auto cur = Q.front(); Q.pop();
        for(int dir = -1; dir < 2 ; dir++)
        {   
            int nx;
            if( dir == 0)   nx = cur * 2; // 순간 이동
            else nx = cur + dir;  // 좌 우 이동

            if( nx < 0 || nx >= 100001) continue;
            if( dist[nx] >= 0) continue;
            else if( dist[nx] == -2) cout << dist[cur] + 1; // 동생 찾음
            dist[nx] = dist[cur] + 1;
            Q.push(nx);
        }
    }
}