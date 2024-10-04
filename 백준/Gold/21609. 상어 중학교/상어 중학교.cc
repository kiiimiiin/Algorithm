#include <iostream>
#include <queue>
#include <utility>
#include <tuple>
#include <algorithm>
#define X first
#define Y second
const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };
int n, m;
using namespace std;
int board[22][22];

bool OOB(int x, int y) {
	return x < 0 || x >= n || y < 0 || y >= n;
}

pair<int,int> Find() {
	

	//1. 블락그룹 찾기, 일반블록 기준으로 bfs (기준블락 반환 )
	
	queue<pair<int, int>> q, rq;
	int vis[22][22] = {};

	tuple<int, int, int, int> mx = { -0x7f7f7f7f, 0,0,0 };
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] > 0 && !vis[i][j]) {
				int area = 0;
				int rainbow = 0;
				q.push({ i, j });
				vis[i][j] = 1;
				while (!q.empty()) {
					auto cur = q.front(); q.pop(); area++;
					for (int dir = 0; dir < 4; dir++) {
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];
						if (OOB(nx, ny) || vis[nx][ny]) continue;
						if (board[nx][ny] == 0 || board[nx][ny] == board[i][j]) {
							if (board[nx][ny] == 0) {
								rainbow++;
								rq.push({ nx,ny });
							}
							q.push({ nx,ny });
							vis[nx][ny] = 1;
						}
					}
				}
				
				if (area == 1) continue;
				
				while (!rq.empty()) {
					auto cur = rq.front(); rq.pop();
					vis[cur.X][cur.Y] = 0;
				}

				mx = max(mx, make_tuple(area, rainbow, i, j));
			}
		}
	}

	int area, x, y;
	tie(area, ignore, x, y) = mx;
	if (area == -0x7f7f7f7f) return make_pair(-1, -1);

	return make_pair(x, y);
}

int Remove(int x, int y) { // 점수반환
	queue<pair<int, int>> q;
	int vis[22][22] = {};
	int color;
	int area = 0;

	q.push({ x, y });
	vis[x][y] = 1;
	color = board[x][y];

	while (!q.empty()) {
		auto cur = q.front(); q.pop(); 
		area++;	board[cur.X][cur.Y] = -2;
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (OOB(nx, ny) || vis[nx][ny]) continue;
			if (board[nx][ny] == 0 || board[nx][ny] == color) {
				q.push({ nx,ny });
				vis[nx][ny] = 1;
			}
		}
	}

	return area * area;
}

void Gravity() {
	for (int j = 0; j < n; j++) {
		int cx = n;
		for (int i = n - 1; i >= 0; i--) {
			if (board[i][j] == -2) continue;
			if (board[i][j] == -1) {
				cx = i;
			}
			else {
				int color = board[i][j];
				board[i][j] = -2;
				board[cx - 1][j] = color;
				cx = cx - 1;
			}
		}
	}
}

void Rotate() {
	int tmp[22][22];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			tmp[n -1 - j][i] = board[i][j];
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			board[i][j] = tmp[i][j];
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	int ans = 0;

	while (1) {
		int x, y;
		tie(x,y) = Find();
		if (x == -1 && y == -1) break;
		ans += Remove(x, y);
		Gravity();
		Rotate();
		Gravity();
	}

	cout << ans;
}