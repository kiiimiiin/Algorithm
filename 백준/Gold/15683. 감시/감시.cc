#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int board[9][9];
const int dirs[6] = { -1, 4, 2, 4, 4, 1 };
const int dx[4] = { 0, -1, 0, 1 };
const int dy[4] = { 1, 0, -1, 0 };
int n, m;

struct CCTV {
	int x, y, type;
};

vector<CCTV> cctvs;
int mn = 0x7f7f7f7f;

bool OOB(int x, int y) {
	return x < 0 || x >= n || y < 0 || y >= m;
}

void detect(int x, int y, int dir) {
	dir = dir % 4;

	int nx = x;
	int ny = y;
	while (1) {
		nx += dx[dir];
		ny += dy[dir]; 
		if (OOB(nx, ny) || board[nx][ny] == 6) break;
		if (board[nx][ny] >= 1 && board[nx][ny] <= 5) continue;
		board[nx][ny] = 7;
	}
}

void Copy(int desc[9][9], int src[9][9]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			desc[i][j] = src[i][j];
		}
	}
}
void dfs(int k) {
	if (k == cctvs.size()) {
		int area = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j] == 0)
					area++;
			}
		}
		mn = min(mn, area);
		return;
	}
	
	auto cctv = cctvs[k];
	int x = cctv.x; int y = cctv.y; int type = cctv.type;
	int dirCse = dirs[cctv.type];
	int tmp[9][9];

	Copy(tmp, board);

	for (int dir = 0; dir < dirCse; dir++) {
		if (type == 1) {
			detect(x, y, dir);
		}
		else if (type == 2) {
			detect(x, y, dir);
			detect(x, y, dir + 2);
		}
		else if (type == 3) {
			detect(x, y, dir);
			detect(x, y, dir + 1);
		}
		else if (type == 4) {
			detect(x, y, dir);
			detect(x, y, dir + 1);
			detect(x, y, dir + 2);
		}
		else if (type == 5) {
			detect(x, y, dir);
			detect(x, y, dir + 1);
			detect(x, y, dir + 2);
			detect(x, y, dir + 3);
		}

		dfs(k + 1);
		Copy(board, tmp);
	}
}


int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] >= 1 && board[i][j] <= 5) {
				cctvs.push_back({ i, j, board[i][j] });
			}
		}
	}

	dfs(0);
	cout << mn;

}




/*

	CCTV 방향 별 완탐후 최소영역 구하기
	4^8 * 64 = 420만
	

*/