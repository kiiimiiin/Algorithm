#include <bits/stdc++.h>
using namespace std;
int n, k; // 수빈이의 위치 , 동생의 위치 
int dist[100002];
queue<int> Q;
int main()
{
	cin >> n >> k;
	fill(dist, dist + 100001, -1); // 방문이력 없음
	dist[n] = 0;
	Q.push(n); // 수빈 시작점

	while(dist[k] == -1) // 동생이 있는 지점에 방문이력이 없는 동안 bfs
	{
		auto cur = Q.front(); Q.pop();
		for( auto nx : {cur - 1, cur + 1 , 2*cur})
		{
			if(nx < 0 || nx >= 100001 || dist[nx] >= 0) continue; //범위 벗어나거나 방문이력 존재
			dist[nx] = dist[cur] + 1;
			Q.push(nx);
		}
	}
	cout << dist[k];
}