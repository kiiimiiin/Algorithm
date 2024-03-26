#include <iostream>
#include <queue>
#define X first
#define Y second
using namespace std;
int board[22][22];
int dice[7] = { 0, 1, 2, 3, 4, 5, 6 };
int dir, n, m, k, x, y; // dir,x, y 모두 0 
int dx[4] = { 0, 1, 0, -1 }; // 동 남 서 북
int dy[4] = { 1, 0, -1, 0 };

void Move() {
	
	int nx = x + dx[dir];
	int ny = y + dy[dir];
	if (nx < 0 || nx >= n || ny < 0 || ny >= m) { // 방향에 칸 x
		dir = (dir + 2) % 4; 
		nx = x + dx[dir];
		ny = y + dy[dir];
	}

	if (dir == 0) {
		swap(dice[4], dice[6]);
		swap(dice[6], dice[3]);
		swap(dice[3], dice[1]);
	}
	else if (dir == 1) {
		swap(dice[2], dice[6]);
		swap(dice[6], dice[5]);
		swap(dice[5], dice[1]);
	}
	else if (dir == 2) {
		swap(dice[3], dice[6]);
		swap(dice[6], dice[4]);
		swap(dice[4], dice[1]);
	}
	else if (dir == 3) {
		swap(dice[5], dice[6]);
		swap(dice[6], dice[2]);
		swap(dice[2], dice[1]);
	}

	x = nx;
	y = ny;
}

int GetScore() {
	int vis[22][22] = {};
	int number;
	int area = 0;
	queue<pair<int, int>> q;
	q.push({ x,y });
	vis[x][y] = 1;
	number = board[x][y];

	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		area++;
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (board[nx][ny] != number || vis[nx][ny]) continue;
			q.push({ nx,ny });
			vis[nx][ny] = 1;
		}
	}
	return number * area;
}

void MakeDir() {
	if (dice[6] > board[x][y]) dir = (dir + 1) % 4;
	else if (dice[6] < board[x][y]) dir = (dir + 3) % 4;

	return;
}

int solve() {
	int ret = 0;
	while (k--) {
		Move();
		ret += GetScore();
		MakeDir();
	}

	return ret;
}


int main(void) {
	cin >> n >> m >> k;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];

	dir = x = y = 0;
	
	int ans = solve();
	cout << ans;
}