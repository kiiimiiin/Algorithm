#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>
#define X first
#define Y second
using namespace std;
int n, sx, sy, eaten;
int ss = 2;
int board[22][22];
int dist[22][22];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 }; // 상좌하우

struct Fish {
	int dist, x, y;
};


bool OOB(int x, int y) {
	return (x < 0 || x >= n || y < 0 || y >= n);
}

bool isPrior(Fish& candi, int nx, int ny) {
	return (candi.dist > dist[nx][ny] || (candi.dist == dist[nx][ny] && candi.x > nx)
		|| (candi.dist == dist[nx][ny] && candi.x == nx && candi.y > ny));
}
int eatFish() {
	int t = 0;
	queue<pair<int, int>> q;

	for (int i = 0; i < n; i++)
		fill(dist[i], dist[i] + n, -1);

	dist[sx][sy] = 0;
	q.push({ sx,sy });


	Fish candi = { 0x7f7f7f7f, 0x7f7f7f7f, 0x7f7f7f7f };

	// 1. 먹을 수 있는 물고기 후보탐색
	while (!q.empty()) {
		auto cur = q.front(); q.pop();

		if (dist[cur.X][cur.Y] > candi.dist) break; // 제일 가까운 후보 물고기보다 탐색거리가 커지면

		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (OOB(nx, ny)) continue;
			if (board[nx][ny] > ss || dist[nx][ny] >= 0) continue;

			dist[nx][ny] = dist[cur.X][cur.Y] + 1;
			q.push({ nx,ny });

			if (board[nx][ny] < ss && board[nx][ny] > 0) { // candi
				if (isPrior(candi, nx, ny)) 
					candi = { dist[nx][ny], nx, ny };
			}
		}
	}
	
	// 2. 후보 물고기 섭취
	if (candi.dist != 0x7f7f7f7f) {
		board[sx][sy] = 0;
		board[candi.x][candi.y] = 9;
		sx = candi.x; sy = candi.y;
		eaten++;
		if (eaten == ss) { eaten = 0; ss++; }
		return candi.dist;
	}

	return 0;
}




int main(void) {
	cin >> n; 

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			if (board[i][j] == 9) {
				sx = i; sy = j;
			}
		}
	}

	int ans = 0;
	while (1) {
		int t = eatFish();
		if (t == 0) break; 
		ans += t;
	}

	cout << ans;
	
}