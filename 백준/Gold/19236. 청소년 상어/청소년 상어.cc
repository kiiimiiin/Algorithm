#include <iostream>
const int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
const int dy[8] = { 0, -1, -1, -1, 0, 1, 1, 1 };
using namespace std;
int board[4][4]; // 물고기 보드
int mx = -0x7f7f7f7f;

struct Fish {
	int x, y;
	int dir;
	bool isLived;
};

Fish fish[17];


void Copy(int desc[4][4], int src[4][4], Fish fdesc[17], Fish fsrc[17]) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			desc[i][j] = src[i][j];
		}
	}

	for (int i = 1; i <= 16; i++)
		fdesc[i] = fsrc[i];
}
bool OOB(int x, int y) {
	return x < 0 || x >= 4 || y < 0 || y >= 4;
}


void MoveFish(int sx, int sy) {
	for (int i = 1; i <= 16; i++) {
		if (!fish[i].isLived) continue;

		int nx, ny, nd, dd;

		for (dd = 0; dd < 8; dd++) {
			nd = (fish[i].dir + dd) % 8;
			nx = fish[i].x + dx[nd];
			ny = fish[i].y + dy[nd];
			if (OOB(nx, ny) || (nx == sx && ny == sy)) continue;
			break;
		}


		if (dd == 8) continue;

		if (board[nx][ny] >= 1 && board[nx][ny] <= 16) {
			Fish f = fish[i];

			fish[i].x = nx;
			fish[i].y = ny;
			fish[i].dir = nd;
			fish[board[nx][ny]].x = f.x;
			fish[board[nx][ny]].y = f.y;

			board[f.x][f.y] = board[nx][ny];
			board[nx][ny] = i;

		}
		else if (board[nx][ny] == 0) {
			Fish f = fish[i];

			fish[i].x = nx;
			fish[i].y = ny;
			fish[i].dir = nd;

			board[f.x][f.y] = 0;
			board[nx][ny] = i;
		}
	}
}

void dfs(int eatten, int sx, int sy, int sd) {

	// 1. 상어자리 물고기 섭취
	eatten += board[sx][sy];
	sd = fish[board[sx][sy]].dir;
	fish[board[sx][sy]].isLived = false;
	board[sx][sy] = 0;
	mx = max(mx, eatten);


	// 2. 물고기 이동
	MoveFish(sx, sy);

	// 3. 상어 이동
	int tmp[4][4];
	Fish ftmp[17];
	Copy(tmp, board, ftmp, fish);

	for (int p = 1; p <= 3; p++) {
		int nx = sx + p * dx[sd];
		int ny = sy + p * dy[sd];
		if (OOB(nx, ny) || board[nx][ny] == 0) continue;

		dfs(eatten, nx, ny, sd);

		Copy(board, tmp, fish, ftmp);
	}

}


int main() {
	ios::sync_with_stdio(0), cin.tie(0);


	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int dir;
			cin >> board[i][j] >> dir;
			fish[board[i][j]] = { i, j, dir - 1, true };
		}
	}

	dfs(0, 0, 0, 0);
	cout << mx;

}
