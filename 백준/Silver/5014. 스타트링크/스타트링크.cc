#include <bits/stdc++.h>
using namespace std;
int s,g,f,u,d;
int dist[1000005];


int main()
{
    cin >> f >> s >> g >> u >> d ;

    queue<int> Q;
    fill(dist, dist + 1000005, -1); //  방문 이력 없음
    dist[s] = 0;
    Q.push(s);
    while(!Q.empty())
    {
        int cur = Q.front(); Q.pop();
        for(int nxt : {cur + u, cur - d})
        {
            if(nxt < 1 || nxt > f) continue; // 층밖에 벗어남
            if(dist[nxt] >= 0) continue; // 방문이력 존재
            dist[nxt] = dist[cur] + 1;
            Q.push(nxt);
        }
    }
    
    if(dist[g] != -1) cout << dist[g]; // g층에 도달할 수 있는 경우
    else cout << "use the stairs";
}