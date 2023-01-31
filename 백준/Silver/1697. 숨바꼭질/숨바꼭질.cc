#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int dist[100002];
int n, k;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    
    cin >> n >> k;
    fill(dist, dist + 100001, -1); // 방문이력 없음
    
    queue<int> Q;
    dist[n] = 0;
    Q.push(n);

    while(dist[k] == -1)
    {
        int cur = Q.front(); Q.pop();
        for( int nxt : {cur + 1, cur - 1, cur*2})
        {
            if(nxt < 0 || nxt > 100000) continue; // 영역 밖
            if(dist[nxt] >= 0) continue; // 방문 이력 존재
            dist[nxt] = dist[cur] + 1;
            Q.push(nxt);
        }
    }
    cout << dist[k] ;
}