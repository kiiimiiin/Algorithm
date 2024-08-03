#include <iostream>
#include <queue>
#include <utility>
#define X first
#define Y second
using namespace std;

struct Guest {
	int sx, sy;
	int dx, dy;
	int isLived;
};

struct Taxi {
	int x, y;
	int gas;
};

Guest guest[402];
const int dx[4] = { 1, 0, -1 ,0 };
const int dy[4] = { 0, 1, 0, -1 };
int board[22][22];
int n, m;
Taxi taxi; 

bool OOB(int x, int y) {
	return x < 0 || x >= n || y < 0 || y >= n; 
}

bool Drive() {
	// 1. 손님을 향해
	queue<pair<int, int>>  q;
	int dist[22][22]; 
	for (int i = 0; i < n; i++) 
		fill(dist[i], dist[i] + n, -1);

	dist[taxi.x][taxi.y] = 0;
	q.push({ taxi.x, taxi.y });

	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (OOB(nx, ny)) continue;
			if (board[nx][ny] == 1 || dist[nx][ny] >= 0) continue;
			dist[nx][ny] = dist[cur.X][cur.Y] + 1;
			q.push({ nx,ny }); 
		}
	}

	int minDist = 0x7f7f7f7f;
	int minIdx = 0x7f7f7f7f; 
	for (int i = 1; i <= m; i++) { // 손님들에 대한 거리 파악
		if (!guest[i].isLived) continue;
		if (dist[guest[i].sx][guest[i].sy] < minDist
			|| dist[guest[i].sx][guest[i].sy] == minDist && guest[i].sx < guest[minIdx].sx
			|| dist[guest[i].sx][guest[i].sy] == minDist && guest[i].sx == guest[minIdx].sx && guest[i].sy < guest[minIdx].sy) {
			minDist = dist[guest[i].sx][guest[i].sy];
			minIdx = i; 
		}
		
	}

	if (minDist == -1) // 못태우는 손님 존재
		return false;

	
	if (minDist >= taxi.gas) // 연료 부족
		return false;



	taxi.gas -= minDist;
	taxi.x = guest[minIdx].sx;
	taxi.y = guest[minIdx].sy;

	// 2. 해당 목적지를 향해

	for (int i = 0; i < n; i++)
		fill(dist[i], dist[i] + n, -1);

	dist[taxi.x][taxi.y] = 0;
	q.push({ taxi.x, taxi.y });

	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (OOB(nx, ny)) continue;
			if (board[nx][ny] == 1 || dist[nx][ny] >= 0) continue;
			dist[nx][ny] = dist[cur.X][cur.Y] + 1;
			q.push({ nx,ny });
		}
	}
	
	if (dist[guest[minIdx].dx][guest[minIdx].dy] == -1) // 목적지 도달 x
		return false;
	
	if (dist[guest[minIdx].dx][guest[minIdx].dy] > taxi.gas) // 연료 부족
		return false;

	taxi.gas -= dist[guest[minIdx].dx][guest[minIdx].dy];
	taxi.gas += 2 * dist[guest[minIdx].dx][guest[minIdx].dy]; 
	taxi.x = guest[minIdx].dx;
	taxi.y = guest[minIdx].dy;
	guest[minIdx].isLived = false;

	return true;
	
}

bool IsNoGuest() {
	for (int i = 1; i <= m; i++) {
		if (guest[i].isLived) return false;
	}
	return true;
}


int main(void) {
	ios::sync_with_stdio(0), cin.tie(0); 

	cin >> n >> m >> taxi.gas;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	cin >> taxi.x >> taxi.y; 
	taxi.x--; taxi.y--;

	for (int i = 1; i <= m; i++) {
		cin >> guest[i].sx >> guest[i].sy
			>> guest[i].dx >> guest[i].dy; 
		guest[i].sx--; guest[i].sy--; 
		guest[i].dx--; guest[i].dy--;
		guest[i].isLived = true;
	}

	int success = 0; 
	while (1) {
		if (IsNoGuest()) {
			success = 1;
			break;
		}

		if (!Drive()) {
			break; 
		}
	}

	cout << (success ? taxi.gas : -1); 
	
}

/*
	택시에서부터 BFS로 최단거리 손님찾음
	다시 BFS로 목적지까지의 최단거리 찾음
	손님 구조체 배열로 가장 작은 거리

*/