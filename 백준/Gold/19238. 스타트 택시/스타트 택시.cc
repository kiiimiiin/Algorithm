#include <iostream>
#include <utility>
#include <queue>
#include <tuple>
#define X first
#define Y second
using namespace std; 
int n, m;
int board[22][22];
int dist[22][22];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 }; 

struct Taxi {
	int x, y, g;
};

struct Guest {
	int sx, sy, ex, ey; 
	bool IsLived = false;
};

Taxi t;
Guest guest[402];

bool OOB(int nx, int ny) {
	return nx < 0 || nx >= n || ny < 0 || ny >= n;
}

bool Drive() {
	for (int i = 0; i < n; i++) fill(dist[i], dist[i] + n, -1);
	queue<pair<int, int>> q; 
	dist[t.x][t.y] = 0;
	q.push({ t.x,t.y });

	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (OOB(nx, ny) || dist[nx][ny] >= 0) continue;
			if (board[nx][ny] == 1) continue;
			dist[nx][ny] = dist[cur.X][cur.Y] + 1;
			q.push({ nx,ny });
		}
	}

	tuple< int, int, int> mn = { 0x7f7f7f7f, 0, 0 };
	int mnIdx, mnDist;
	for (int idx = 1; idx <= m; idx++) {
		if (guest[idx].IsLived == false) continue;
		if(mn > make_tuple(dist[guest[idx].sx][guest[idx].sy]
			, guest[idx].sx, guest[idx].sy)) {
			mn = make_tuple(dist[guest[idx].sx][guest[idx].sy]
				, guest[idx].sx, guest[idx].sy);
			mnIdx = idx;
		}
	}

	tie(mnDist, ignore, ignore) = mn;

	if (mnDist == -1 || t.g <= mnDist)
		return false;
	
	t.g -= mnDist; 
	t.x = guest[mnIdx].sx;
	t.y = guest[mnIdx].sy;

	for (int i = 0; i < n; i++) fill(dist[i], dist[i] + n, -1);
	dist[t.x][t.y] = 0;
	q.push({ t.x,t.y });

	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (OOB(nx, ny) || dist[nx][ny] >= 0) continue;
			if (board[nx][ny] == 1) continue;
			dist[nx][ny] = dist[cur.X][cur.Y] + 1;
			q.push({ nx,ny });
		}
	}

	mnDist = dist[guest[mnIdx].ex][guest[mnIdx].ey];
	if ( mnDist == -1 || t.g < mnDist)
		return false;

	t.g -= mnDist;
	t.g += 2 * mnDist;
	t.x = guest[mnIdx].ex;
	t.y = guest[mnIdx].ey;
	guest[mnIdx].IsLived = false; 
	return true; 
}

bool IsNoGuest() {
	for (int idx = 1; idx <= m; idx++) {
		if (guest[idx].IsLived == true) return false;
	}
	return true;
}

int main() {
	cin >> n >> m >> t.g;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	int tx, ty;

	cin >> tx >> ty;
	t.x = tx - 1; t.y = ty - 1;

	for (int idx = 1; idx <= m; idx++) {
		int sx, sy, ex, ey;
		cin >> sx >> sy >> ex >> ey;
		guest[idx].sx = sx - 1; guest[idx].sy = sy - 1;
		guest[idx].ex = ex - 1; guest[idx].ey = ey - 1;
		guest[idx].IsLived = true; 
	}

	bool isPossible = true;
	while (1) {
		if (Drive() == false) {
			isPossible = false;
			break; 
		}
		if (IsNoGuest())
			break; 
	}
	
	cout << (isPossible ? t.g : -1);
}