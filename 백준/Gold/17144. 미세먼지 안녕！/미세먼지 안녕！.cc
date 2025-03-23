#include <iostream>
using namespace std; 

int r, c, t;
int board[52][52]; 

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 }; 

struct Machine {
	int top, bottom;
};

Machine m;

bool OOB(int nx, int ny) {
	return nx < 0 || nx >= r || ny < 0 || ny >= c; 
}

bool IsMachine(int nx, int ny) {
	return (nx == m.bottom || nx == m.top) && ny == 0;
}

void Spread() {
	int tmp[52][52] = {};

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (board[i][j] > 0) {
				int val = board[i][j] / 5;
				for (int dir = 0; dir < 4; dir++) {
					int nx = i + dx[dir];
					int ny = j + dy[dir];
					if (OOB(nx, ny) || (IsMachine(nx, ny))) continue;
					tmp[nx][ny] += val;
					tmp[i][j] -= val; 
				}
			}
		}
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			board[i][j] += tmp[i][j];
		}
	}
}

void Wind() {
	int tdx[4] = {-1, 0, 1, 0};
	int tdy[4] = { 0, 1, 0, -1 };
	int x = m.top - 1; 
	int y = 0;
	int dir = 0;
	
	while (!(x == m.top && y == 1)) {
		int nx = x + tdx[dir];
		int ny = y + tdy[dir];
		if (OOB(nx, ny) || nx > m.top) {
			dir = (dir + 1) % 4;
			continue;
		}
		board[x][y] = board[nx][ny];
		x = nx; y = ny;
	}
	board[x][y] = 0;

	int bdx[4] = { 1, 0, -1, 0 };
	int bdy[4] = { 0, 1, 0, -1 };
	x = m.bottom + 1;
	y = 0;
	dir = 0;

	while (!(x == m.bottom && y == 1)) {
		int nx = x + bdx[dir];
		int ny = y + bdy[dir];
		if (OOB(nx, ny) || nx < m.bottom) {
			dir = (dir + 1) % 4;
			continue;
		}
		board[x][y] = board[nx][ny];
		x = nx; y = ny;
	}
	board[x][y] = 0;
}

int getAns() {
	int ret = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (board[i][j] > 0)
				ret += board[i][j];
		}
	}

	return ret; 
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);

	cin >> r >> c >> t;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> board[i][j];
			if (board[i][j] == -1)
				m.bottom = i;
		}
	}

	m.top = m.bottom - 1;

	while (t--) {
		Spread();
		Wind();
	}

	int ans = getAns();
	cout << ans; 
}