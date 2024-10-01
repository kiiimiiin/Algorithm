#include <iostream>
#include <tuple>
#include <queue>
#include <utility>
#include <algorithm>
#define X first
#define Y second
using namespace std;
const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };
int board[22][22];
int n, m;
struct Taxi {
	int x, y, g;
};

struct Guest {
	int sx, sy;
	int ex, ey;
	int isLived = false;
};

Guest guest[402];
Taxi t;

bool OOB(int x, int y) {
	return x < 0 || x >= n || y < 0 || y >= n; 
}

bool Drive() {

	// 1. 최소거리 승객 이동
	queue<pair<int, int>> q;
	int dist[22][22];
	for (int i = 0; i < n; i++) fill(dist[i], dist[i] + n, -1);

	q.push({ t.x, t.y });
	dist[t.x][t.y] = 0;

	while (!q.empty()) { 
		auto cur = q.front(); q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (OOB(nx, ny) || dist[nx][ny] >= 0) continue;
			if (board[nx][ny] == 1) continue;
			dist[nx][ny] = dist[cur.X][cur.Y] + 1;
			q.push({ nx, ny });
		}
	}

	
	// 최단거리에 대해 최소거리 승객 탐색
	tuple<int, int, int> mn = { 0x7f7f7f7f, 0, 0 }; // 거리, 행, 열
	int mnDist, mr, mc, mnIdx;

	for (int idx = 1; idx <= m; idx++) {
		if (!guest[idx].isLived) continue;
		auto g = guest[idx];
		if (make_tuple(dist[g.sx][g.sy], g.sx, g.sy) < mn) {
			mn = make_tuple(dist[g.sx][g.sy], g.sx, g.sy);
			mnIdx = idx;
		}
	}

	tie(mnDist, mr, mc) = mn;
	if (mnDist == -1) return false; // ** 
	if (mnDist >= t.g) return false;
	
	t.x = mr; t.y = mc;
	t.g -= mnDist;

	// 2. 목적지까지 이동
	for (int i = 0; i < n; i++) fill(dist[i], dist[i] + n, -1);

	q.push({ t.x, t.y });
	dist[t.x][t.y] = 0;

	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (OOB(nx, ny) || dist[nx][ny] >= 0) continue;
			if (board[nx][ny] == 1) continue;
			dist[nx][ny] = dist[cur.X][cur.Y] + 1;
			q.push({ nx, ny });
		}
	}

	mnDist = dist[guest[mnIdx].ex][guest[mnIdx].ey];
	if (mnDist == -1) return false;
	if (mnDist > t.g) return false;
	
	t.x = guest[mnIdx].ex; t.y = guest[mnIdx].ey; 
	t.g -= mnDist;
	t.g += 2 * mnDist;
	guest[mnIdx].isLived = false;
	
	return true;

}

bool IsNoGuest() {
	for (int idx = 1; idx <= m; idx++) {
		if (guest[idx].isLived) return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);

	cin >> n >> m >> t.g;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> board[i][j];

	cin >> t.x >> t.y;
	t.x--; t.y--;

	for (int i = 1; i <= m; i++) {
		cin >> guest[i].sx >> guest[i].sy
			>> guest[i].ex >> guest[i].ey;
		guest[i].sx--; guest[i].sy--;
		guest[i].ex--; guest[i].ey--;
		guest[i].isLived = true;
	}

	bool notMoved = false;
	while (1) {
		if (!Drive()) {
			notMoved = true;
			break;
		}
		
		if (IsNoGuest())
			break;
	}

	cout << (notMoved ? -1 : t.g);
}

/*
	택시 : 도착지로 데려다주면 충전, 연료떨어지면 종료

	m명 승객

	택시는 최단거리 승객 탑승시킴( 행, 열 작은 순으로 ) 
	목적지로 이동 성공 -> 소모 연료 2배 충전 ( 
	
	이동중 연료 바닥시 종료, 목적지 이동 동시 바닥나는건 실패 x


	sol ) 
	bfs로 최단승객탐색 
	해당 승객에 대하여 목적지로 최단거리 또탐색

	m : 구조체 배열


*/